#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int seki_four(std::initializer_list<unsigned> t)
{
  if (t.size() != 4) {
    return -1;
  }
  return t[0]*t[1]*t[2]*t[3];
}

void left_top(std::vector<std::vector<unsigned>>& board, unsigned& max)
{
}
void right_top(std::vector<std::vector<unsigned>>& board, unsigned& max)
{
}
void print_vec(const std::vector<std::vector<unsigned>>& vec)
{
  for(const auto& e : vec) {
    for(const auto& f : e) {
      std::cout << std::setw(3) << f;
    }
    std::cout << '\n';
  }
}
int main(int argc, char** argv)
{
  std::vector<std::vector<unsigned>> vec(20, std::vector<unsigned>(20,0));
  for  (auto i = 0;i < vec.size();++i) {
    std::for_each(vec[i].begin(), vec[i].end(), [](auto& e){std::cin >> e;});
  }

  /*transform under average to 0*/
  {
    unsigned sum = 0;
    for (auto i = 0;i < vec.size();++i) {
      std::for_each(vec[i].begin(), vec[i].end(), [&sum](auto& e){sum += e;});
    }
    unsigned avg = sum / (vec[0].size()* vec.size());
    for (auto i = 0;i < vec.size();++i) {
      for (auto j = 0;j < vec[0].size();++j) {
        if (vec[i][j] < avg) {
          vec[i][j] = 0;
        }
      }
    }
  }

  unsigned seki_max = 0;
  left_top(vec, seki_max);
  right_top(vec, seki_max);
}
