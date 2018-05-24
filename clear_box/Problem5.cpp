#include <iostream>
#include <vector>
#define SIZE 20

unsigned long multiple_ans(std::vector<unsigned> vec)
{
  unsigned long sum = 1;
  for(const auto& e : vec)
  {
    sum *= e;
  }
  return sum;
}
int main()
{
  std::vector<unsigned> elements(SIZE);
  for(int i = 0;i < SIZE;++i)
  {
    elements[i] = i + 1;
  }
  for(int i = 1;i < SIZE / 2;++i)
  {
    if(elements[i] > 1)
    {
      for(unsigned j = i + elements[i];j < SIZE;j += elements[i])
      {
        if(elements[j] % elements[i])
        {
          continue;
        }
        elements[j] /= elements[i];
      }
    }
  }
  std::cout << multiple_ans(elements) << '\n';
}
