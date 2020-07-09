#include <iostream>

int main()
{
  unsigned long long sum = 0;
  unsigned long long a = 3;
  for(int i = 2;a < 1000;++i)
  {
    sum += a;
    a = 3*i;
  }
  a = 5;
  for(int i = 2;a < 1000;++i)
  {
    sum += a;
    a = 5*i;
  }
  a = 15;
  for(int i = 2;a < 1000;++i)
  {
    sum -= a;
    a = 15*i;
  }
  std::cout << sum << '\n';
}
