#include<stdio.h>
#include<stack>


class Tower
{
  private:
    std::stack<int> disks;
    int index;
  
  public: 
    Tower(int i);
    int Index();
    void Add(int d);
    void MoveTopTo(Tower* t);
    void MoveDisks(int n, Tower* destination, Tower* buffer);
};

Tower::Tower(int i) { index = i; }

int Tower::Index() { return index; }

void Tower::Add(int d) 
{
  if(!disks.empty() && disks.top() <= d) {
    printf("Error placing disk %d\n", d);
  } else {
    disks.push(d);
  }
}

void Tower::MoveTopTo(Tower* t)
{
  int top = disks.top();
  disks.pop();
  t->Add(top);
  printf("Move disk %d from %d to %d\n", top, this->Index(), t->Index());
}

void Tower::MoveDisks(int n, Tower* destination, Tower* buffer) 
{
  if (n > 0) {
    this->MoveDisks(n-1, buffer, destination);
    this->MoveTopTo(destination);
    buffer->MoveDisks(n-1, destination, this); 
  }
}


int main()
{
  int n = 4;
  Tower towers[3] = { 0, 1, 2 };
  
  for (int i = n - 1; i >= 0; --i) {
    towers[0].Add(i);
  }
  
  towers[0].MoveDisks(n, &towers[2], &towers[1]);
    
  return 0;
}














