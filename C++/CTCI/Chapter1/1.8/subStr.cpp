#include <stdio.h>
#include <string>

bool IsSubstr(std::string s1, std::string s2);
bool IsRotation(std::string s1, std::string s2);

int main()
{

  std::string s1 = "bottlewater";
  std::string s2 = "waterbottle";
  
  printf("Is substring: %d\n", IsSubstr(s1, s2));
  printf("Is rotation: %d\n", IsRotation(s1, s2));

}

bool IsSubstr(std::string s1, std::string s2)
{
  std::string::size_type n;
  
  n = s2.find(s1);
  
  if (n == std::string::npos) {
    return false;
  } else {
    return true;
  }
}

bool IsRotation(std::string s1, std::string s2)
{  
  if (s1.length() == s2.length() && s1.length() > 0) {
    std::string s2s2 = s2 + s2; 
    return IsSubstr(s1, s2s2);
  } 
  
  return false;
}




