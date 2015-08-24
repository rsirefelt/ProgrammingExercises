#include <iostream>

void quickSort(int* arr, int loInd, int hiInd);
int partition(int* arr, int loInd, int hiInd);
void swap(int* arr, int firstInd, int secondInd);

int main()
{

  int size = 10;
  int numbers[10] = {6,10,5,4,17,1,9,8,7,2};
  
  quickSort(numbers,0, size-1);
  
  for (int i = 0; i < size; i++) 
  {
    std::cout << numbers[i] << " "; 
  }   
  
  std::cout << std::endl;

  return 0;
}

void quickSort(int* arr, int loInd, int hiInd)
{
  if (loInd < hiInd)
  {
    int pInd = partition(arr, loInd, hiInd);
    quickSort(arr, loInd, pInd-1);
    quickSort(arr, pInd+1, hiInd);
  } 
}

int partition(int* arr, int loInd, int hiInd)
{
  int pivotInd = (hiInd+loInd)/2;
  int pivotValue = arr[pivotInd];
  
  swap(arr, pivotInd, hiInd); // Puts the pivot at the top
  int storeInd = loInd;
  
  for (int i = loInd; i < hiInd; i++) 
  {
    if (arr[i] < pivotValue)
    {
      swap(arr, i, storeInd);
      storeInd++;
    }
  }
  swap(arr, storeInd, hiInd); // Return pivot to correct place
  
  return storeInd;
}

void swap(int* arr, int firstInd, int secondInd)
{
  int temp = arr[firstInd];
  arr[firstInd] = arr[secondInd];
  arr[secondInd] = temp;
}


















