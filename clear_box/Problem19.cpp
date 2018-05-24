#include <iostream>

int main()
{
  int count = 0;
  const int day = 1;
  for(int year = 1901;year <= 2000;++year)
  {
    int calc = year + (year/4) - (year/100)+ (year/400) + day;
    for(int month = 3;month <= 14;++month)
    {
      if(! ((calc +(month *13 + 8)/5)%7) )++count;
    }
  }
  std::cout << count << '\n';
}
