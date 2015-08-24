#include <string>

#ifndef STRING_BUFFER
#define STRING_BUFFER

class StringBuffer
{
public:
  StringBuffer();
  StringBuffer(int initSize);
  
  void append(std::string word);
  std::string toString() const;
private:
  int arrayLength;
  int nrOfWords = 0;
  std::string *words; 
  
};

#endif
