#include <iostream>
#include <vector>
#include <string>
#define SIZE 1000
#define BOX_SIZE 13

unsigned long long sum_vec(std::vector<unsigned> a)
{
  unsigned long long sum = 1;
  for(const auto& e : a)
  {
    sum *= e;
    if(sum == 0)return 0;
  }
  return sum;
}
int main()
{
  std::vector<unsigned> numeric_sequence(BOX_SIZE, 0);
  unsigned target_index = 0;
  unsigned long long max_sum = 0;
  for(int i = 0;i < SIZE;++i)
  {
    unsigned long long input{[](){char a;std::cin >> a;return (unsigned long)a - '0';}()};
    numeric_sequence[target_index] = input;
    unsigned long long sum = sum_vec(numeric_sequence);
    if(max_sum < sum)
    {
      max_sum = sum;
    }
    ++target_index;
    if(target_index >= BOX_SIZE)target_index = 0;
  }
  std::cout << max_sum << '\n';
}
