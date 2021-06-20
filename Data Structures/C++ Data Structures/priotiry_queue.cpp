#include <stdlib.h>
#include <iostream>

#define MAX 5

struct item{
  int value;
  int priority;
};

class PriorityQueue{
  public:
    item q[MAX];
    int numOfElems;
    bool emptySlot;
    int maxPriorityIndex;

    PriorityQueue(){numOfElems = 0;}
    void enqueue(item element);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};

bool PriorityQueue::isEmpty(){
  return numOfElems == 0;
}

void PriorityQueue::enqueue(item element){
  if (emptySlot == true){
    q[maxPriorityIndex].value = element.value;
    q[maxPriorityIndex].priority = element.priority;
    emptySlot = false;
  }
  else if (emptySlot == false){
    q[numOfElems].value = element.value;
    q[numOfElems].priority = element.priority;
    numOfElems++;
  }
}


void PriorityQueue::dequeue(){
  maxPriorityIndex = 0;

  for(int i = 1; i < numOfElems; i++){
    if (q[i].priority > q[maxPriorityIndex].priority){
      maxPriorityIndex = i;
    }
  }
  std::cout << q[maxPriorityIndex].value << '\n';
  q[maxPriorityIndex].value = 0;
  q[maxPriorityIndex].priority = 0;
  emptySlot = true;

}

void PriorityQueue::display(){
  std::cout << "{";
  for (int i = 0; i < numOfElems; i++){
    std::cout << "{" << q[i].value << ", " << q[i].priority << "}" << ", ";
  }
  std::cout << "}" << std::endl;
}


int main(){

  PriorityQueue pq;

  item pqItem1 = {1, 2};
  item pqItem2 = {2, 5};
  item pqItem3 = {3, 1};

  pq.enqueue(pqItem1);
  pq.display();
  pq.enqueue(pqItem2);
  pq.display();
  pq.dequeue();
  pq.enqueue(pqItem3);
  pq.display();



  return 0;
}
