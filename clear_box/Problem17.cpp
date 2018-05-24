#include <iostream>
#include <vector>
#include <string>

unsigned long count_string(const std::vector<std::string> str_box)
{
  unsigned long sum = 0;
  for(const auto& e : str_box)
  {
    sum += e.size();
  }
  return sum;
}
int main()
{
  const std::vector<std::string> number{"","one","two","three","four","five","six","seven","eight","nine"};
  const std::vector<std::string> number_tenmore{"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
  const std::vector<std::string> number_twntymore{"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
  const std::string hundread{"hundred"};
  const std::string hundread_help{"and"};
  const std::string thousand{"thousand"};
  const unsigned long sum_less_ten{count_string(number)};
  const unsigned long sum_less_hundread{count_string(number_tenmore) + sum_less_ten* 9 + 10*(count_string(number_twntymore))};
  const unsigned long sum_less_thousand{sum_less_hundread*10 + sum_less_ten* 100 + hundread.size()* (1000 - 100) + hundread_help.size()* (1000 - 100- 9 )};
  std::cout <<sum_less_ten <<' '<< sum_less_hundread <<' '<< sum_less_thousand << '\n';
  std::cout << sum_less_thousand + std::string{"onethousand"}.size() << '\n';
}
