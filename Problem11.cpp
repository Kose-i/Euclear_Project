#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
  std::vector<std::vector<int>> vec(20, std::vector<int>(20,0));
  for(auto& e : vec)
  {
    for(auto& f : e)std::cin >> f;
  }
  std::vector<std::vector<int>> map = vec;
  for(auto& e : map)
  {
    for(auto& f : e)
    {
      if(f < 80)f = 0;
    }
  }
  for(const auto& e : map)
  {
    for(const auto& f : e)
    {
      std::cout << std::setw(2) << std::setfill(' ') <<f << ' ';
    }
    std::cout << '\n';
  }
}
