#include <iostream>
#include <vector>
#define SIZE 15

typedef struct tree* link;
struct tree{
  unsigned int Item;
  link left_link;
  link right_link;
};
unsigned int sum_cost(link target_link)
{
  if(target_link == nullptr)return 0;
  unsigned int sum_left = sum_cost((*target_link).left_link);
  unsigned int sum_right = sum_cost((*target_link).right_link);
  if(sum_left > sum_right)return ((*target_link).Item + sum_left);
  else return ((*target_link).Item + sum_right);
}
int main()
{
  const unsigned int case_size{(SIZE* (SIZE + 1) ) / 2};
  std::vector<struct tree> node(case_size);
  const link target_link = &node[0];
  {
    for(int i = 1,j = 0;i < SIZE + 1;++i)
    {
      for(int k = 0;k < i;++k,++j)
      {
        std::cin >> node[j].Item;
        if(i < SIZE )
        {
          node[j].left_link = &node[j + i];
          node[j].right_link = &node[j + i + 1];
        }
        else
        {
          node[j].left_link = nullptr;
          node[j].right_link = nullptr;
        }
      }
    }
  }
  std::cout << sum_cost(target_link) << '\n';
}
