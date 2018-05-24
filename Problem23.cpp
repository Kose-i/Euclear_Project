#include <iostream>
#include <vector>
#include <cmath>
#define SIZE 23132

std::vector<int> make_prime(int size)
{
  std::vector<bool> prime_check(size + 1,true);
  int check_size = std::sqrt(size);
  for(int i = 2;i < check_size;++i)
  {
    if(prime_check[i])
    {
      for(int j = i*2;j <= size;j += i)
      {
        prime_check[j] = false;
      }
    }
  }
  std::vector<int> prime;
  for(int i = 2;i < size;++i)
  {
    if(prime_check[i])prime.push_back(i);
  }
  return prime;
}
int deliminate(int check_integar, std::vector<int> prime)
{
  int prime_size = prime.size();
  std::vector<unsigned> count_prime(prime_size,0);
  for(int i = 0;i < prime_size && count_prime[i] != 1;++i)
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
std::vector<int> over_delimite(std::vector<int> prime, int max_element)
{
  std::vector<int> over_delim;
  for(int i = 0;i < max_element;++i)
  {
    if(deliminate(i,prime) > 2*i)over_delim.push_back(i);
  }
  return over_delim;
}
/*
bool isexpr(int check_target, std::vector<int> delimite)
{
}
*/
int main()
{
  std::vector<int> prime = make_prime(SIZE);
  std::cout << "prime checked\n";
  std::vector<int> delimite = over_delimite(prime,SIZE);
  for(const auto& e : delimite)
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
  unsigned long sum = 0;
  for(int i = 0;i < SIZE;++i)
  {
    //if(!isexpr(i,delimite))sum += i;
  }
  std::cout << sum << '\n';
}
