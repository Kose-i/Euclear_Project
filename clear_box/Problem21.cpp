#include <iostream>
#include <vector>
#include <cmath>
#define SIZE 10000

std::vector<int> make_prime(int size)
{
  int check_size = std::sqrt(size);
  std::vector<bool> check_prime(size + 1,true);
  for(int i = 2;i < check_size;++i)
  {
    if(check_prime[i])
    {
      for(int j = i*2;j < size + 1;j += i)
      {
        check_prime[j] = false;
      }
    }
  }
  std::vector<int> prime;
  for(int i = 2;i < size + 1;++i)
  {
    if(check_prime[i])prime.push_back(i);
  }
  return prime;
}
int deliminate(int check_integar, std::vector<int> prime)
{
  int prime_size = prime.size();
  std::vector<unsigned> count_prime(prime_size,0);
  for(int i = 0;i < prime_size;++i)
  {
    while(check_integar % prime[i] == 0)
    {
      check_integar /= prime[i];
      ++count_prime[i];
    }
  }
  int sum = 1;
  for(int i = 0;i < prime_size;++i)
  {
    int sum_dec = 0;
    for(int j = 0;j <= count_prime[i];++j)
    {
      sum_dec += std::pow(prime[i],j);
    }
    sum *= sum_dec;
  }
  return sum;
}
int main()
{
  std::vector<int> prime_number = make_prime(SIZE);
  unsigned sum = 0;
  for(int i = 1;i < SIZE;++i){
    int k = deliminate(i,prime_number) - i;
    if(i < k)
    {
      int j = deliminate(k,prime_number) - k;
      if(i == j)
      {
        sum += i + k;
      }
    }
  }
  std::cout << sum << '\n';
}
