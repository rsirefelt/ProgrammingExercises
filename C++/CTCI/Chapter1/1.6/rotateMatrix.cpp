#include <stdio.h>

void initMat(int **matix, int dim);
void printMat(int **matrix, int dim);
void rotateMat(int **matrix, int dim);

int main()
{
  const int dim = 6;

  int **matrix = new int*[dim];
  for (int i = 0; i < dim; ++i) {
    matrix[i] = new int[dim];
  }
  
  initMat(matrix, dim);
  printMat(matrix, dim);
  printf("\n");
  
  rotateMat(matrix, dim);
  printMat(matrix, dim);
}

void initMat(int **matrix, int dim)
{
  for (int i = 0; i < dim; ++i) {
    for (int j = 0; j < dim; ++j) {
      matrix[i][j] = j + i*dim;
    }
  }
}

void printMat(int **matrix, int dim)
{
  for (int i = 0; i < dim; ++i) {
    for (int j = 0; j < dim; ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  } 
}

void rotateMat(int **matrix, int dim)
{
  int savedCell, movingCell;
  int iRow, iCol, oldRow;
  int jLimit = dim%2==0 ? dim/2 : dim/2+1;
  int nrOfSides = 4;
  
  for (int i = 0; i < dim/2; ++i) {
    for (int j = 0; j < jLimit; ++j) {
      iRow = i;
      iCol = j;
      movingCell = matrix[iRow][iCol];
      for (int k = 0; k < nrOfSides; ++k) {
        savedCell = matrix[dim-iCol-1][iRow];
        matrix[dim-iCol-1][iRow] = movingCell;
        movingCell = savedCell;
        
        oldRow = iRow; 
        iRow = dim-iCol-1;
        iCol = oldRow;
      }
    }
  }
}






