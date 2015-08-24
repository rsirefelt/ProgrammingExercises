#include <unordered_map>
#include <string>
#include <stdio.h>

int main()
{
  std::unordered_map<std::string,std::string> unorderedMap;
  unorderedMap.emplace("www.facebook.com", "184.51.49.225");
   
  printf("IP Address: %s\n", unorderedMap["www.facebook.com"].c_str());
  
  unorderedMap.insert(std::make_pair("www.newark.com", 
    "185.51.50.121"));
  
  for (auto itr = unorderedMap.begin(); itr != unorderedMap.end();
    ++itr) {
    printf("%s: %s: %s\n", itr->first.c_str(), itr->second.c_str());
  }
  
  for (auto &itr:unorderedMap) {
    printf("%s: %s\n", itr.first.c_str(), itr.second.c_str());
  }
  return 0;
}
