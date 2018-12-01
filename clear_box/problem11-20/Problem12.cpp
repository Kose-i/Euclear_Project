#include <iostream>
#include <vector>
#include <cmath>
#define YAKUSUU_COUNT 500
#define PRIME_SIZE 5000000

std::vector<unsigned> make_prime_number()
{
  std::vector<bool> prime_number(PRIME_SIZE, true);
  prime_number[0] = false;prime_number[1] = false;
  unsigned search_i = std::sqrt(PRIME_SIZE) + 1;
  for(unsigned i = 2;i < search_i; ++i)
  {
    if(prime_number[i]) {
      for(unsigned j = i*2;j < PRIME_SIZE;j += i)
      {
        prime_number[j] = false;
      }
    }
  }
  std::vector<unsigned> prime_num;
  for(unsigned i = 0;i < PRIME_SIZE;++i)
  {
    if(prime_number[i])prime_num.push_back(i);
  }
  return prime_num;
}
int main(){
  std::vector<unsigned> prime_num = make_prime_number();
  unsigned long long sum_ans = 0;
  for(unsigned i = 1;;++i)
  {
    int count_sum = 1;
    sum_ans += i;
    unsigned long long sum = sum_ans;
    for(int j = 0;prime_num[j] <= sum;++j)
    {
      int count = 0;
      while(!(sum % prime_num[j]) )
      {
        sum /= prime_num[j];
        ++count;
      }
      count_sum *= (count + 1);
    }
    if(count_sum > YAKUSUU_COUNT)
    {
      std::cout << sum_ans << '\n';
      break;
    }
  }
}
