#include "hash.h"

hash::hash()
{
  for (int i = 0; i < tableSize; ++i) {
    HashTable[i] = new item; 
    HashTable[i]->name = "empty"; 
    HashTable[i]->pet = "empty"; 
    HashTable[i]->next = NULL; 
  }
}

void hash::AddItem(std::string name, std::string pet)
{
  int index = Hash(name); 
  
  if (HashTable[index]->name == "empty") {
    HashTable[index]->name = name; 
    HashTable[index]->pet = pet; 
  } else { // if collision in index
    item* ptr = HashTable[index]; 
    item* n = new item; 
    n->name = name; 
    n->pet = pet; 
    n->next = NULL; 
    
    while (ptr->next != NULL) {
      ptr = ptr->next; // traverse the chain
    }
    ptr->next = n;  
  }
} 

void hash::PrintTable()
{
  int number; 
  for (int i = 0; i < tableSize; ++i) {
    number = NumberOfItemsInIndex(i); 
    printf("--------------------------\n");
    printf("index = %i\n", i); 
    printf("%s\n", HashTable[i]->name.c_str()); 
    printf("%s\n", HashTable[i]->pet.c_str());
    printf("# of items = %i\n", number);
    printf("--------------------------\n");
  }
}


void hash::PrintItemsInIndex(int index) 
{
  item* ptr = HashTable[index];
  
  if (ptr->name == "empty") {
    printf("index = %i is empty\n", index); 
  } else {
    printf("index = %i contains the following items:\n", index); 
    while (ptr != NULL) {
      printf("----------------------\n"); 
      printf("%s\n", ptr->name.c_str()); 
      printf("%s\n", ptr->pet.c_str());
      printf("----------------------\n"); 
      ptr = ptr->next;
    }
  }
}

void hash::FindPet(std::string name)
{
  int index = Hash(name); 
  bool foundName = false;
  std::string pet; 
  
  item* ptr = HashTable[index];
  while(ptr != NULL) {
    if (ptr->name == name) {
      foundName = true;
      pet = ptr->pet; 
    }
    ptr = ptr->next; 
  }
  
  if (foundName) {
    printf("pet = %s\n", pet.c_str()); 
  } else {
    printf("%s was not found in the Hash Table\n", name.c_str()); 
  }

}


int hash::NumberOfItemsInIndex(int index) 
{
  int count = 0; 
  if (HashTable[index]->name == "empty") {
    return count;  
  } else {
    ++count; 
    item* ptr = HashTable[index]; 
    while (ptr->next != NULL) {
      ++count; 
      ptr = ptr->next; 
    }
  }
  return count;
}


int hash::Hash(std::string key)
{
  int hash = 0; 
  int index; 
  
  for (int i = 0; i < key.length(); ++i) {
    hash = (hash + (int)key[i]) * 7; 
  }
  
  index = hash % tableSize; 
  //printf("%s -> %d\n", key.c_str(), index);
  
  return index;

}


void hash::RemoveItem(std::string name)
{
  int index = Hash(name);
  item* delPtr; 
  item* ptr1; 
  item* ptr2; 
  
  // Case 0 - bucket is empty
  if (HashTable[index]->name == "empty" && 
    HashTable[index]->pet == "empty") {
    printf("%s was not found in the Hash Table\n", name.c_str());
  } else if (HashTable[index]->name == name && HashTable[index]->next == NULL) {
  // Case 1 - only 1 item contained in bucket 
  //and that item has matching name
    HashTable[index]->name = "empty";
    HashTable[index]->pet = "emtpy";
    
    printf("%s was removed from the Hash Table\n", name.c_str());
  } else if (HashTable[index]->name == name) { 
  // Case 2 - match is located in the first item in 
  // the bucket but there are more items in the bucket
    delPtr = HashTable[index];
    HashTable[index] = HashTable[index]->next;
    delete delPtr;
    
    printf("%s was removed from the Hash Table\n", name.c_str());
  } else {
  // Case 3 - bucket contains items but first item is not a match
  
    ptr1 = HashTable[index];
    ptr2 = ptr1->next; 
    while (ptr2 != NULL && ptr2->name != name) {
      ptr1 = ptr2;
      ptr2 = ptr2->next;
    }
    
    // Case 3.1 - no match
    if (ptr2 == NULL) {
      printf("%s was not found in the Hash Table\n", name.c_str());
    // Case 3.2 - match is found
    } else {
      delPtr = ptr2;
      ptr1->next = ptr2->next;
      delete delPtr; 
      printf("%s was removed from the Hash Table\n", name.c_str());
    }
  }
}














