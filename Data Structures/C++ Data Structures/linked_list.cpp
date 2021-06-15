#include <stdlib.h>
#include <iostream>

using namespace std;

struct node{
  int data;
  node* next;
};

class LinkedList{
  private:
    node *head, *tail;

  public:
    LinkedList(){
      head = NULL;
      tail = NULL;
    }

    void createNode(int value);
    void displayList();
    void insertNode(int position, int value);
    void deleteNode(int position);
};

void LinkedList::createNode(int value){

  node* temp = new node;
  temp->data = value;
  temp->next = NULL;
  if(head == NULL){
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else{
    tail->next = temp;
    tail = temp;
  }

}

void LinkedList::displayList(){
  node* temp = new node;
  temp = head;

  while(temp != NULL){
    cout << temp->data << "\t";
    temp = temp->next;
  }
  cout << endl;
}

void LinkedList::insertNode(int position, int value){

  if (position == 0){
    node* temp = new node;
    temp->data = value;
    temp->next = head;
    head = temp;
  }
  else{
    node* previous = new node;
    node* current = new node;
    node* temp = new node;
    current = head;
    for (int i = 1; i < position; i++) {
      previous = current;
      current = current->next;
    }
    temp->data = value; //Assign data to temporary pointer
    previous->next = temp; //Point from previous node to temporary node
    temp->next = current; //Point from temporary node to next "current" ndoe
  }

}

void LinkedList::deleteNode(int position){

  if (position == 0){
    node* temp = new node;
    temp = head;
    head = head->next;
    delete temp;
  }
  else{
    node* current = new node;
    node* previous = new node;
    current = head;
    for (int i = 1; i < position; i++){
      if(i < position){
        previous = current;
        current = current->next;
      }
      else{
        tail = previous;
        previous->next = NULL;
        delete current;
      }
    }
  previous->next = current->next;
  }

}

int main() {

  LinkedList myLinkedList;
  myLinkedList.createNode(2);
  myLinkedList.createNode(4);
  myLinkedList.createNode(7);
  myLinkedList.displayList();

  return 0;
}
