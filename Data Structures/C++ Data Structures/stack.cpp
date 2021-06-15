#include <iostream>
#include <stdlib.h>

using namespace std;
#define MAX 10

class Stack{

  public:
    int a[MAX];
    int top;

    //Methods
    Stack(){top = -1;}
    void push(int item);
    int pop();
    bool isEmpty();
    void printStack();
    int peek();

};

void Stack::push(int item){
  if (top >= (MAX - 1)){
    cout << "The stack is full" << endl;
  }
  else{
    a[++top] = item;
  }
}
int Stack::pop(){
  if(top < 0){
    cout << "Stack Underflow" << endl;
    return 0;
  }
  else{
    int x = a[top--];
    return x;
  }
}
bool Stack::isEmpty(){
  return (top < 0);
}

int Stack::peek(){
  if (top < 0){
    cout << "Stack is empty" << endl;
    return 0;
  }
  else{
    int x = a[top];
    return x;
  }
}

void Stack::printStack(){

}

int main(){

  Stack stack;
  char str[MAX] = "carter";

  for (int i = 0; i < 6; i++){
    stack.push(str[i]);
  }

  while (!stack.isEmpty()){
    cout << (char) stack.peek();
    stack.pop();
  }
  cout << endl;

  return 0;
}
