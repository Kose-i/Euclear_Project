#include <iostream>
#include <vector>
#include <numeric>

int main()
{
  std::vector<unsigned int> each_item{1};
  int vec_size = 1;
  for(int i = 1;i <= 100;++i)
  {
    for(auto& e : each_item)
    {
      e *= i;
    }
    for(int i = 0;i < vec_size;++i)
    {
      if(10 <= each_item[i])
      {
        if(i < vec_size - 1)
        {
          each_item[i + 1] += each_item[i] / 10;
          each_item[i] %= 10;
        }
        else{
          ++vec_size;
          each_item.push_back(each_item[i] / 10);
          each_item[i] %= 10;
        }
      }
    }
  }
  std::cout << std::accumulate(each_item.begin(),each_item.end(),0) << '\n';
}
