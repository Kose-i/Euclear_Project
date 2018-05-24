#include <iostream>
#include <cmath>

int main()
{
  unsigned b,c;
  for(c = 1000 - 1;c > 333;--c)
  {
    bool find = false;
    for(b = 1000 - c - 1;b > (1000 - c) / 2 - 1;--b)
    {
      if(std::pow(c,2)==std::pow(1000-c-b,2)+std::pow(b,2))
      {
        find = true;
        break;
      }
    }
    if(find)break;
  }
  std::cout << (1000 - c - b) << ' ' << b << ' ' << c << '\n';
  std::cout << (1000 - c - b) *b * c << '\n';
}
