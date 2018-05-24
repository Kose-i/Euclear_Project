#include <iostream>
#include <vector>

std::vector<unsigned long long> Make_Even_Fibo()
{
  std::vector<unsigned long long> Fibo {1,1,2};
  for(unsigned long long top = 2;top < 4000000;)
  {
    top = top * 2;
    top -= Fibo[Fibo.size() - 3];
    Fibo.push_back(top);
  }
  return Fibo;
}
int main()
{
  std::vector<unsigned long long> Fibo = Make_Even_Fibo();
  unsigned long long sum = 0;
  for(const auto& e : Fibo)
  {
    if(! (e % 2) )sum += e;
  }
  std::cout << sum << '\n';
}
