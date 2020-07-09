#include <iostream>
#include <cmath>
#include <vector>

int main()
{
  std::vector<unsigned> number{1};
  int size = 0;
  for(int count = 0;count < 1000;++count)
  {
    for(auto& e : number)
    {
      e *= 2;
    }
    for(int i = 0;i <= size;++i)
    {
      if(number[i] > 9)
      {
        if(i == size)
        {
          number.push_back(number[i] / 10);
          number[i] %= 10;
          ++size;
        }
        else {
          ++number[i + 1];
          number[i] %= 10;
        }
      }
    }
  }
  unsigned long sum = 0;
  for(const auto& e : number)
  {
    sum += e;
  }
  std::cout << sum << '\n';
}
