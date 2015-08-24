#include <stdio.h>
#include <math.h>

const double PI = 3.14159; 

int main()
{
  // Create some data
  int points = 11;
  double *data = new double[points]();
  
  //Test
  printf("%lu\n", sizeof(double));
  
  for (int i = 0; i < points; ++i) {
    data[i] = sin(i/((double)points-1)*2*PI);
  }
  
  //Write the file
  FILE *file = fopen("file.dat","wb");
  fwrite(&points,sizeof(int),1,file);
  fwrite(data,sizeof(double),points,file);
  fclose(file);
  
  for (int i = 0; i < points; ++i) {
    printf("%f\n", data[i]);
  }
  
  delete[] data;
  
  return 0;
}
