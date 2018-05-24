#include <iostream>
#include <vector>
#include <string>

std::vector<unsigned> get_reverese_unsigned()
{
  std::string str;
  std::getline(std::cin, str);
  int size = str.size();
  std::vector<unsigned> numeric;
  for(int i = size - 1;0 <= i;--i)
  {
    numeric.push_back(str[i] - '0');
  }
  return numeric;
}
int main()
{
  std::vector<unsigned> numeric(50,0);
  for(int j = 0;j < 100;++j)
  {
    std::vector<unsigned> t = get_reverese_unsigned();
    for(int i = 0;i < 50;++i)
    {
      numeric[i] += t[i];
    }
  }

  //move up
  for(int i = 0;true;++i)
  {
    if(49 <= i)numeric.push_back(0);
    if(numeric[i] > 10)
    {
      numeric[i + 1] += numeric[i] / 10;
      numeric[i] %= 10;
    }
    else if(49 <= i)break;
  }

  int count = 0;
  for(int i = numeric.size() - 2;count < 10;--i, ++count)
  {
    std::cout << numeric[i];
  }
  std::cout << '\n';
}
