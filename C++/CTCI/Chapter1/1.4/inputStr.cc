#include <stdio.h>

void ReplaceSpaces(char* str);

int main()
{
  char str[256] = "hej ho bamaram i kalsdjfal hsaldjf tjolaholm asdkfh                           "; 
  
  printf("%s\n", str);
  ReplaceSpaces(str);
  printf("%s\n", str);
  
  return 0;
}

void ReplaceSpaces(char* str)
{
  char* start = str;
  int newStrLength = 0, oldStrLength = 0;
  
  while(*start != ' ' || *(start+1) != ' '){
    if (*start == ' ') {
      newStrLength += 3;
    } else {
      ++newStrLength;
    }
    ++oldStrLength;
    ++start;
  }
  
  int j = newStrLength-1;
  for (int i = oldStrLength-1; i > -1; --i) {
    if (str[i] == ' ') {
      str[j] = '0';
      str[j-1] = '2';
      str[j-2] = '%';
      j -= 3;
    } else {
      str[j] = str[i];
      --j;
    } 
  }
}
