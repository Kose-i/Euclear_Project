#include <iostream>
#include <cmath>
#define SIZE 100

int main()
{
  unsigned long long sum_sqrt = 0;
  for(int i = 1;i <= SIZE;++i)sum_sqrt += std::pow(i, 2);
  unsigned long long sum = 0;
  for(int i = 1;i <= SIZE;++i)sum += i;
  sum = std::pow(sum, 2);
  std::cout << sum - sum_sqrt << '\n';
}
