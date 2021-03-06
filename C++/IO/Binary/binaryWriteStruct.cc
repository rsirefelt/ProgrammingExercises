#include <stdio.h>
#include <math.h>

const double PI = 3.14159; 

typedef struct FileHeader
{
  int points;
  
  int year, month, day;
} FileHeader;

int main()
{
  //Creat dome data
  
  FileHeader header;
  header.points = 11;
  header.year = 2013;
  header.month = 4;
  header.day = 30;
  
  double *data = new double[header.points]();
  
  for (int i = 0; i < header.points; ++i) {
    printf("%f\n", data[i]);
  }
  
  for (int i = 0; i < header.points; ++i) {
    data[i] = sin(i/((double) header.points - 1)*2*PI);
  }
  
  // Write the file
  
  FILE *file = fopen("file.dat","wb");
  fwrite(&header, sizeof(FileHeader), 1, file);
  fwrite(data, sizeof(double), header.points, file);
  fclose(file);
  
  
  // Print out what was written
  
  for (int i = 0; i < header.points; ++i) {
    printf("%f\n", data[i]);
  }
  delete[] data;
  
  return 0;
  
}
  
  
  
  
  
  
  
  
