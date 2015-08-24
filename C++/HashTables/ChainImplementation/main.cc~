#include "hash.h"

int main(int argc, char** argv) 
{
  hash Hashy; 
  
  std::string name = "";
  char tmp[101];
  
  Hashy.AddItem("Rickard", "bjorn"); 
  Hashy.AddItem("Emilia", "lulle"); 
  Hashy.AddItem("Hola", "dola"); 
  Hashy.AddItem("Tjola", "koola"); 
  Hashy.AddItem("Emma", "putte");
  Hashy.AddItem("Stefan", "nisse");
  Hashy.AddItem("Gustav", "per");
  Hashy.AddItem("Joe", "green tea");
  Hashy.AddItem("Tjo", "hello"); 
  Hashy.AddItem("Ball", "Nolo");
  
  Hashy.PrintTable();
  Hashy.PrintItemsInIndex(0);
  
  while (name != "exit"){
    printf("Remove: "); 
    scanf("%100s", tmp);
    name = tmp; 
    printf("\n");
    if (name != "exit") {
      Hashy.RemoveItem(name);
    }
  }
  
  Hashy.PrintItemsInIndex(0);
  
  return 0;
}
