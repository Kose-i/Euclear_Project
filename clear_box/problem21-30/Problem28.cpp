#include <iostream>

unsigned long long answer(const unsigned& now_layer_line, const unsigned long& start, const unsigned& end_layer_line) {
  if (now_layer_line > end_layer_line) {
    return 0;
  } else if (now_layer_line == 1) {
    return 1 + answer(now_layer_line + 2, 2, end_layer_line);
  } else {
    unsigned long long this_sum = 4*start;
    constexpr int count = 1 + 2 + 3 + 4;
    this_sum += count*(now_layer_line - 1) - 4;
    return this_sum + answer(now_layer_line + 2, start + 4*now_layer_line - 4, end_layer_line);
  }
}

int main(int argc, char** argv) {
  std::cout << answer(1, 1, 1001) << '\n';
}
