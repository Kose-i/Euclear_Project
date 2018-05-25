#include <iostream>
#include <vector>
#define SIZE 1000000

std::vector<bool> judge(SIZE, true);
bool check_history()
{
  for(const auto& e : judge)
  {
    if(e)return true;
  }
  return false;
}
std::vector<unsigned long> history {1};
unsigned add_history(unsigned root)
{
  unsigned history_size = history.size();
  for(unsigned i = root; i < history_size;++i)
  {
    if(!( (history[i] - 1) % 3))
    {
      unsigned a = (history[i] - 1) / 3;
      bool find = false;
      for(auto& e : history)
      {
        if(e == a)find = true;
      }
      if(a % 2 && !find)
      {
        history.push_back(a);
        if(0 <= a && a < SIZE)judge[a] = false;
      }
    }
    {
      bool find = false;
      unsigned a = 2*(history[i]);
      for(const auto& e : history)
      {
        if(e == a)find = true;
      }
      if(!find)
      {
        history.push_back(a);
        if(0 <= a && a < SIZE)judge[a] = false;
      }
    }
  }
  return history_size;
}
int main()
{
  judge[0] = false;
  unsigned root = 0;
  for(int i = 0;i < 100;++i)
  {
    root = add_history(root);
    if(!check_history())break;
  }
  for(const auto& e : history)
  {
    std::cout << e << ' ';
  }
  std::cout << history[history.size() - 1] << '\n';
}
