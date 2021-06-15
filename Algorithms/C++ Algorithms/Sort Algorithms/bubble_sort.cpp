#include <iostream>
using namespace std;

void bubbleSort(int array[], int size);
bool checkSort(int array[], int size);
void printArray(int array[], int size);

int main(){

  int myArray[] = {-2, 0, 11, -9, 45};
  int n = sizeof(myArray) / sizeof(myArray[0]);
  cout << "Unsorted array: ";
  printArray(myArray, n);
  bubbleSort(myArray, n);
  cout << "Sorted array: ";
  printArray(myArray, n);
  cout << endl;

  return 0;
}

void bubbleSort(int array[], int size){

  int currentElement = 0;

  while (checkSort(array, size) == 0){
    for (int i = 0; i < size - 1; ++i){
      if (array[i] > array[i + 1]){
        currentElement = array[i];
        array[i] = array[i + 1];
        array[i + 1] = currentElement;
      }
    }
  }

}

bool checkSort(int array[], int size){
  int trueSort = 0;
  for(int i = 0; i < size - 1; ++i){
    if(array[i] < array[i + 1]){
      trueSort += 1;
    }
  }

  if(trueSort == size - 1){
    return true;
  }else{return false;}

}

void printArray(int array[], int size){
  cout << "[";
  for(int i = 0; i < size; ++i){
    if (i == size - 1){
      cout << array[i];
    }else {cout << array[i] << ", ";}
  }

  cout << "]" <<endl;
}
