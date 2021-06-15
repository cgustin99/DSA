#include <stdlib.h>
#include <iostream>

#define SIZE 5

class Queue{

  public:
    int front;
    int rear;
    int a[SIZE];
    Queue(){
      front = -1;
      rear = -1;
    }

    void enqueue(int item);
    void dequeue();
    bool isEmpty();
    bool isFull();
    int peek();

};

void Queue::enqueue(int item){
  if (front < 0 && rear < 0){
    front = 0, rear = 0;
    a[0] = item;
  }
  else if (rear != SIZE - 1){
    a[++rear] = item;
  }
  else{std::cout << "Queue is full" << std::endl;}
}

void Queue::dequeue(){
  if (!(front < 0 && rear < 0)){
    if (front < SIZE - 1 && rear < SIZE - 1){
      std::cout << a[front++] << std::endl;
    }
    else{
      std::cout << a[front] << std::endl;
      front = -1, rear = -1;
    }
  }else{std::cout << "Queue is empty" << std::endl;}

}

bool Queue::isEmpty(){
  return (front < 0 && rear < 0);
}

bool Queue::isFull(){
  return (front == 0 && rear == SIZE - 1);
}

int Queue::peek(){
  return a[rear];
}

int main(){
  int i = 1;
  Queue q;

  //Enque elements and display by peek():
  while (!q.isFull()){
    q.enqueue(i);
    std::cout << q.peek() << std::endl;
    i++;
  }

  return 0;
}
