#include <stdio.h>
#include <string>
#include <unordered_map>
#include <functional>

class Make
{
public: 
  std::string name;
  
  Make(std::string name)
  {
    name = name;
  }
  
  bool operator==(const Make &make) const
  {
    return name==make.name;
  }
};

class Model
{
public: 
  std::string name; 
  int year; 
  
  Model(std::string name, int year)
  {
    name = name;
    year = year;
  }
  
  bool operator==(const Model &model) const
  {
    return (name == model.name && year == model.year);
  }
};


class ModelHash
{
public: 
  size_t operator()(const Model &model) const
  {
    return std::hash<std::string>()(model.name)^std::hash<int>()
      (model.year);
  }
};

int main()
{
  std::unordered_map<Model, Make, ModelHash> model2make;
  
  Model camry2005("Camry",2005); 
  Model tercel1993("Tercel",1993);
  
  Make toyota("Toyota");
  
  model2make.emplace(camry2005, toyota); 
  model2make.emplace(tercel1993,toyota);
  
  for (auto &itr:model2make)
  {
    printf("%s, %d, %s\n", itr.first.name.c_str(), itr.first.year, 
      itr.second.name.c_str());    
  }
  
  return 0;
}

  
  
  
  
  
  
  
  
  
  
  
  
  
  
