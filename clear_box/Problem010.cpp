#include <iostream>
#include <vector>
#include <cmath>
#define SIZE 2000000

int main()
{
  std::vector<bool> box(SIZE + 1, true);
  box[0] = false;box[1] = false;
  unsigned i_check_size = std::sqrt(SIZE) + 1;
  for(unsigned i = 2;i < i_check_size;++i)
  {
    if(box[i] == true)
    {
      for(unsigned j = i*2 ;j < SIZE + 1;j += i)
        box[j] = false;
    }
  }
  unsigned long long sum = 0;
  for(unsigned i = 0;i < SIZE + 1;++i)
  {
    if(box[i])
    {
      sum+=i;
    }
  }
  std::cout << sum << '\n';
}
