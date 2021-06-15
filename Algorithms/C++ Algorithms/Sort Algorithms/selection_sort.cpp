#include <iostream>
using namespace std;

void printArray(int array[], int size);
void selectionSort(int array[], int size);

int main(void){

  int myArray[] = {-2, 0, 11, -9, 45};
  int n = sizeof(myArray) / sizeof(myArray[0]);
  cout << "Unsorted array: ";
  printArray(myArray, n);
  cout << "Sorted array: ";
  selectionSort(myArray, n);
  printArray(myArray, n);

  return 0;
}

void selectionSort(int array[], int size){

  for(int i = 0; i < size; ++i){
    int minIndex = i;
    for (int j = i + 1; j < size; ++j){
      if(array[j] < array[minIndex]){
        minIndex = j;
      }
    }
  int currentElement = array[i];
  array[i] = array[minIndex];
  array[minIndex] = currentElement;
  }

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
