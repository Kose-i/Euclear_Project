#include <iostream>
#include <string>

bool judge(unsigned long ans)
{
  std::string s1 = std::to_string(ans);
  int size = s1.size();
  for(int i = 0;i < size / 2;++i)
  {
    if(s1[i] != s1[size - i - 1])return false;
  }
  return true;
}
int main()
{
  bool find = false;
  unsigned long ans = 1000 * 1000 - 1;
  for(;true;--ans){
    while(!judge(ans))--ans;
    for(unsigned long a1 = 1000 - 1;a1 > 100;--a1)
    {
      if(! (ans % a1))
      {
        if((ans / a1) < 100)continue;
        if( (ans / a1) >= 1000)break;
        std::cout << ans /a1 << '*' << a1 << '\n';
        find = true;
      }
      if(find)break;
    }
    if(find)break;
  }
  std::cout << ans << '\n';
}
