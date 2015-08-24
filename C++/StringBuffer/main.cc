#include <stdio.h>
#include <string>
#include "StringBuffer.h"

int main()
{
  int size = 2;
  StringBuffer stringBuf(size);
  

  stringBuf.append("hej");
  stringBuf.append("yo");
  stringBuf.append("mom");
  stringBuf.append("hej");
  stringBuf.append("yo");
  stringBuf.append("mom");
  
  std::string print = stringBuf.toString();
  
  printf("%s\n", print.c_str());
  

  return 0;
}

