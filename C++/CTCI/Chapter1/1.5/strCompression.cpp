#include <stdio.h>


void CompressStr(char* str);

int main()
{
  int buffSize = 256;
  char str[buffSize];
  
  printf("Put in string: ");
  scanf("%256s", str);
  
  printf("%s\n", str);
  CompressStr(str);
  printf("%s\n", str);
  
  return 0;
}

void CompressStr(char* str)
{
  char currentChar = str[0];
  int oldStrLength = 0, compStrLength = 0, currentCharInd = 0;
  int ind = 0, charCount = 1;
  while (str[ind]) {
    ++oldStrLength;
    if (str[ind] != str[currentCharInd]) {
      currentCharInd = ind;
      while (charCount/10 != 0) {
        ++compStrLength;
        charCount = charCount/10;
      }
      compStrLength += 2; 
      charCount = 1;
    } else {
      ++charCount;
    }
    ++ind;
  }
  
  while (charCount/10 != 0) {
    ++compStrLength;
    charCount = charCount/10;
  }
  compStrLength += 2;
  
  printf("%d\n", compStrLength);
  
  if (compStrLength < oldStrLength) {
    char compStr[compStrLength];
    int currentCompStrInd = compStrLength-1;
    currentCharInd = oldStrLength-1;
    charCount = 0;
    
    for (int i = oldStrLength-1; i > -1; --i) {
      if(str[i] != str[currentCharInd]) {
        while (charCount/10 != 0) {
          compStr[currentCompStrInd] = charCount%10 + '0';
          --currentCompStrInd;
          charCount = charCount/10;
        }
        compStr[currentCompStrInd] = charCount + '0';
        --currentCompStrInd;
        compStr[currentCompStrInd] = str[currentCharInd];
        --currentCompStrInd;
        
        currentCharInd = i;
        charCount = 1;
      } else {
        ++charCount;
      }
      ++ind;
    }
    
    while (charCount/10 != 0) {
      compStr[currentCompStrInd] = charCount%10 + '0';
      --currentCompStrInd;
      charCount = charCount/10;
    }
    compStr[currentCompStrInd] = charCount + '0';
    --currentCompStrInd;
    compStr[currentCompStrInd] = str[currentCharInd];
    
    for (int i = 0; i < compStrLength; ++i) {
      str[i] = compStr[i];
    }
    str[compStrLength] = '\0';
  }
}
