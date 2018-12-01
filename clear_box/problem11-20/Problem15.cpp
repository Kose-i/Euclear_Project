#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> make_prime(const int size)
{
  std::vector<bool> prime_judge(size + 1,true);
  int i_check = std::sqrt(size);
  for(int i = 2;i < i_check;++i)
  {
    if(prime_judge[i])
    {
      for(int j = 2*i;j < size + 1;j += i)
      {
        prime_judge[j] = false;
      }
    }
  }
  std::vector<int> prime;
  for(int i = 2;i < size + 1;++i)
  {
    if(prime_judge[i])
    {
      prime.push_back(i);
    }
  }
  return prime;
}
int main()
{
  std::vector<int> prime = make_prime(40);
  int box_size = prime.size();
  std::vector<int> lowwer_count(box_size, 0);
  for(int i = 1;i <= 20;++i)
  {
    int k = i;
    for(int j = 0;j < box_size && k != 1;++j)
    {
      while(!(k % prime[j]))
      {
        k /= prime[j];
        ++lowwer_count[j];
      }
    }
  }
  std::vector<int> bigger_count(box_size, 0);
  for(int i = 40;i > 20;--i)
  {
    int k = i;
    for(int j = 0;j < box_size && k != 1;++j)
    {
      while(!(k % prime[j]))
      {
        k /= prime[j];
        ++bigger_count[j];
      }
    }
  }
  for(int i = 0;i < box_size;++i)
  {
    bigger_count[i] -= lowwer_count[i];
  }
  unsigned long sum = 1;
  for(int i = 0;i < box_size;++i)
  {
    sum *= std::pow(prime[i], bigger_count[i]);
  }
  std::cout << sum << '\n';
}
