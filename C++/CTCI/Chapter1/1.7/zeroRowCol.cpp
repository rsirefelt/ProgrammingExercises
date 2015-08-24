#include <stdio.h>
#include <vector>

void initMat(int** matrix, const int nrOfRows, const int nrOfCols);
void printMat(int** matrix, const int nrOfRows, const int nrOfCols);
void rowColZero(int** matrix, const int nrOfRows, const int nrOfCols);

int main()
{
  const int nrOfRows = 6;
  const int nrOfCols = 4;
  int** matrix = new int*[nrOfRows];
  for (int i = 0; i < nrOfRows; ++i) {
    matrix[i] = new int[nrOfCols];
  }
  
  initMat(matrix, nrOfRows, nrOfCols);
  printMat(matrix, nrOfRows, nrOfCols);
  matrix[3][3] = 0;
  printf("\n");
  rowColZero(matrix, nrOfRows, nrOfCols);
  printMat(matrix, nrOfRows, nrOfCols);
  printf("\n");
  


  return 0;
}

void rowColZero(int** matrix, const int nrOfRows, const int nrOfCols)
{

  const int rows = 6;
  const int cols = 4; 
  bool zeroRows[rows] = {false}; 
  bool zeroCols[cols] = {false};
  
  for (int i = 0; i < nrOfRows; ++i) {
    for (int j = 0; j < nrOfCols; ++j) {
      if (matrix[i][j] == 0) {
        zeroRows[i] = true;
        zeroCols[j] = true;
      }
    }
  }
  
  for (int i = 0; i < nrOfRows; ++i) {
    if (zeroRows[i]) {
      for (int k = 0; k < nrOfCols; ++k) {
        matrix[i][k] = 0;
      }
    }
  }
  
  for (int i = 0; i < nrOfCols; ++i) {
    if (zeroCols[i]) {
      for (int k = 0; k < nrOfRows; ++k) {
        matrix[k][i] = 0;
      }
    }    
  } 
}




void initMat(int** matrix, const int nrOfRows, const int nrOfCols)
{
  for (int i = 0; i < nrOfRows; ++i) {
    for (int j = 0; j < nrOfCols; ++j) {
      matrix[i][j] = j + nrOfCols*i;
    } 
  }
}

void printMat(int** matrix, const int nrOfRows, const int nrOfCols) 
{
  for (int i = 0; i < nrOfRows; ++i) {
    for (int j = 0; j < nrOfCols; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
