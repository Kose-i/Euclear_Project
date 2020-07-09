#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <vector>


void each_cell(std::vector<std::vector<int>>& cells, std::function<void(int&)> func) {
  for (auto& data_line : cells) {
    for (auto& data : data_line) {
      func(data);
    }
  }
}

int line_max(const std::vector<std::vector<int>>& cells) {
  int max = 0;
  for (auto i = 0;i < 20;++i) {
    for (auto j = 0;j < 20 - 3;++j) {
      int tmp = cells[i][j]*cells[i][j+1]*cells[i][j+2]*cells[i][j+3];
      max = (tmp > max)?tmp:max;
    }
  }
  return max;
}
int row_max(const std::vector<std::vector<int>>& cells) {
  int max = 0;
  for (auto i = 0;i < 20;++i) {
    for (auto j = 0;j < 20 - 3;++j) {
      int tmp = cells[j][i]*cells[j+1][i]*cells[j+2][i]*cells[j+3][i];
      max = (tmp > max)?tmp:max;
    }
  }
  return max;
}
int topleft_max(const std::vector<std::vector<int>>& cells) {
  int max = 0;
  for (auto i = 0;i < 20 - 3;++i) {
    for (auto j = 0;j < 20 - 3;++j) {
      int tmp = cells[i][j]*cells[i+1][j+1]*cells[i+2][j+2]*cells[i+3][j+3];
      max = (tmp > max)?tmp:max;
    }
    for (auto j = 0;j < 20 - 3;++j) {
      int tmp = cells[j][i]*cells[j+1][i+1]*cells[j+2][i+2]*cells[j+3][i+3];
      max = (tmp > max)?tmp:max;
    }
  }
  return max;
}

int topright_max(const std::vector<std::vector<int>>& cells) {
  int max = 0;
  for (auto i = 20 - 1;3 < i;--i) {
    for (auto j = 20 - 1;3 < j;--j) {
      int tmp = cells[i][j]*cells[i-1][j-1]*cells[i-2][j-2]*cells[i-3][j-3];
      max = (tmp > max)?tmp:max;
    }
    for (auto j = 20 - 1;3 < j;--j) {
      int tmp = cells[j][i]*cells[j-1][i-1]*cells[j-2][i-2]*cells[j-3][i-3];
      max = (tmp > max)?tmp:max;
    }
  }
  return max;
}

int main(int argc, char** argv) {
  std::ifstream ifs("Problem11.txt");

  if (! ifs.is_open()) {
    std::cerr << "Fail open\n";
  }

  std::vector<std::vector<int>> cells(20,std::vector<int>(20));
  each_cell(cells, [&](int& t){ifs>>t;});

  int lineMax = line_max(cells);
  int rowMax = row_max(cells);
  int topLeftMax = topleft_max(cells);
  int topRightMax = topright_max(cells);

  int max = (lineMax > rowMax)?lineMax:rowMax;
  max = (topLeftMax > max)?topLeftMax:max;
  max = (topRightMax > max)?topRightMax:max;

  std::cout << max << '\n';
}
