#include <stdlib.h>
#include <list>
#include <undordered_map>

void removeDuplicates(std::forward_list<int> &linkedList); 

int main() 
{
  std::list<int> linkedList = {10, 10, 20, 30, 5, 4, 5, 9, 1, 1};
  
  for (std::list::iterator it = linkedList.begin(); it != linkedList.end(); ++it) {
    printf("%d ", *it);  
  }
  
  removeDuplicates(linkedList); 
  
  for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
    printf("%d ", *it);  
  }
  
  
  printf("\n");
  return 0;
}


void removeDuplicates(std::list<int> List)
{ 
  std::unordered_map<int, int> hastTable; 

  for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
    if (hastTable[*it].count == 0) {
      hashTable[*it] = 1;
    } else {
      
      
    
  }
}














