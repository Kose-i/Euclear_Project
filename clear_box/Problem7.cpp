#include <iostream>
#include <vector>
#define SIZE 10001

int main()
{
  std::vector<unsigned long long> prime_num(SIZE, 2);
  for(unsigned i = 1;i < SIZE;++i)
  {
    unsigned k = prime_num[i - 1];
    for(;true;++k)
    {
      bool find = true;
      for(unsigned j = 0;j < i;++j)
      {
        if(k % prime_num[j] == 0)
        {
          find = false;
          break;
        }
      }
      if(find)break;
    }
  prime_num[i] = k;
  }
  std::cout << prime_num[SIZE - 1] << '\n';
}
