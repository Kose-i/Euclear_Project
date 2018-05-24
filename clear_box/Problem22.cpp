#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<std::string> name_maps(1);
  int i = 0;
  while(std::getline(std::cin,name_maps[i++],','))name_maps.push_back("12");
  std::sort(name_maps.begin(), name_maps.end());
  unsigned long score = 0;
  for(int j = 0;j < i - 1 ; ++j)
  {
    int sum = j + 1;
    int name_size = name_maps[j].size() - 1;
    int other_number = 0;
    for(int k = 1;name_maps[j][k] != '"';++k)
    {
      other_number += name_maps[j][k] - 'A' + 1;
    }
    sum *= other_number;
    std::cout << name_maps[j] << ' ' << sum << '\n';
    score += sum;
  }
  std::cout << score << '\n';
}
