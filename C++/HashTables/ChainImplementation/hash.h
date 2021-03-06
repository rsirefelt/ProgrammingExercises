#ifndef HASH_H
#define HASH_H

#include <string> 
#include <stdio.h>


class hash{
public:
  hash();
  int Hash(std::string key);
  void AddItem(std::string name, std::string pet); 
  int NumberOfItemsInIndex(int index);
  void PrintTable();
  void PrintItemsInIndex(int index);
  void FindPet(std::string name);
  void RemoveItem(std::string name);
  

private: 
  static const int tableSize = 4;

  struct item{
    std::string name; 
    std::string pet; 
    item* next; 
  };
  
  item* HashTable[tableSize];

};




#endif

