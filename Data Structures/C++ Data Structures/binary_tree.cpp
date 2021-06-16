#include <stdlib.h>
#include <iostream>

using namespace std;

struct node{
  int data;
  node* left;
  node* right;
};

class BinaryTree{
  private:
    void insert(int value, node* currentNode);
    void printTree(node* currentNode);
    node* root; //Pointer called "root" to a node (not a node)
  public:
    BinaryTree(){root = NULL;}
    void insert(int value);
    void printTree();

};

void BinaryTree::insert(int value){
  if (root == NULL){
    //Must point to a node struct called root
    node* head = new node; //Pointer to a node that is a node itself
    head->data = value;
    head->left = NULL;
    head->right = NULL;
    root = head; //head goes out of scope after if-statement
  }else {
    insert(value, root);
  }

}

void BinaryTree::insert(int value, node* currentNode){
  if (value < currentNode->data){
    if (currentNode->left == NULL){
      node* temp = new node;
      temp->data = value;
      temp->left = NULL;
      temp->right = NULL;
      currentNode->left = temp;
    }else{
      insert(value, currentNode);
    }
  }
  else if (value > currentNode->data ){
    if (currentNode->right == NULL){
      node* temp = new node;
      temp->data = value;
      temp->left = NULL;
      temp->right = NULL;
      currentNode->right = temp;
    }else{
      insert(value, currentNode);
    }
  }

}

void BinaryTree::printTree(){
  if(root != NULL){
    printTree(root);
  }
}

void BinaryTree::printTree(node* currentNode){
  if (currentNode != NULL){
    printTree(currentNode->left);
    cout << currentNode->data << endl;
    printTree(currentNode->right);
  }

}

int main(){
  BinaryTree btree;
  btree.insert(0);
  btree.insert(2);
  btree.printTree();

  return 0;
}
