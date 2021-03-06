#include <stdio.h>
#include <string>
#include <algorithm>
#include <unordered_map>

bool uniqueChar(std::string str);

int main()
{
  char buffer[256]; 
  std::string input;
  
  printf("Give a string: ");
  if (scanf("%256s", buffer) == 1) {
    input.append(buffer);
  } else {
    printf("Error\n");
  }
  
  printf("%s\n", uniqueChar(input) ? "true" : "false");

  return 0;
}

bool uniqueChar(std::string str)
{
  // sorting O(nlog n), bad solution
  // can be done in O(n) 
  
  //std::sort(str.begin(), str.end());
  
  //for (int i = 0; i < str.size(); ++i) {
  //  if (str[i] == str[i+1]) return false;
  //}
  
  //std::unordered_map<char, bool> uniqueMapTest;
  //for (int i = 0; i < str.size(); ++i) {
  //  if (uniqueMapTest.count(str[i]) > 0) {
  //    return false;
  //  }
  //  else { 
  //    uniqueMapTest.emplace(str[i], true);
  //  }
  //}
  
  bool lookup[256] = {false};
  
  for (int i = 0; i < str.size(); ++i) {
    if (lookup[(int)str[i]]) return false;
    
    lookup[(int)str[i]] = true;
  }
  
  return true;
}






















