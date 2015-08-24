#include <string>
#include <list>
#include <stdio.h>
#include <iostream>

int main()
{
  std::list<std::string> staff;
  
  staff.push_back("Carl");
  staff.push_back("Harry");
  staff.push_back("Larry");
  staff.push_back("Susan");
  
  std::list<std::string>::iterator pos;
  
  pos = staff.begin();
  ++pos; ++pos; ++pos;
  
  staff.insert(pos,"Bengan");
  
  pos = staff.begin();
  ++pos;
  
  staff.erase(pos);
  
  for (pos = staff.begin(); pos != staff.end(); ++pos) {
    printf("%s ", (*pos).c_str());
  }
  printf("\n");
    
  
  return 0;
}
