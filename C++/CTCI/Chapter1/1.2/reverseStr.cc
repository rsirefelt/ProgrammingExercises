#include <stdio.h>

void reverse(char *str);

int main()
{
  
  int stringSize = 256; 
  char str[256];
  
  printf("Input c_string: ");
  if (scanf("%256s", str) != 1) {
    fprintf(stderr, "Error\n");
  }
    
  reverse(str);
  
  fprintf(stdout, "%s\n", str);

  return 0;
}


void reverse(char *str)
{
  char *end = str;
  char *start = str; 
  char tmp;
  
  if (start) {
    while (*end) {
      ++end;
    }
    --end;
  
    while (start < end) {
      tmp = *end; 
      *end = *start;
      *start = tmp;
    
      ++start;
      --end;
    }
  }
  
}
