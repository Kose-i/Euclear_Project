#include <iostream>

int main()
{
  constexpr unsigned long target = 600851475143;
  unsigned long answer = target;
  for(int i = 2;i < answer;++i)
  {
    while(!(answer%i)){
      answer /= i;
    }
  }
  std::cout << answer << '\n';
}
/*
max = n * m (n > m)
m = x * y(x > y)
x = 1 * x
max ... x
*/
