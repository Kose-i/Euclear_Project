#include <iostream>
#include <vector>
#include <algorithm>

bool is_check_box_prime(const unsigned& check_number, const unsigned& now_prime_count, const std::vector<unsigned>& prime_box)
{
  for (auto i = 0;i < now_prime_count;++i) {
    if (check_number % prime_box[i] == 0) {
      return false;
    }
  }
  return true;
}

unsigned prime_make_to_1000(std::vector<unsigned>& prime_box)
{
  auto prime_pos = 0;
  for (unsigned i = 2;i < 1000;++i) {
    if (is_check_box_prime(i, prime_pos, prime_box)) {
      prime_box.push_back(i);
      ++prime_pos;
    }
  }
  return prime_pos;
}

int main(int argc, char** argv)
{
  std::vector<unsigned> prime_box;
  unsigned prime_pos = prime_make_to_1000(prime_box);
  std::for_each(prime_box.begin(), prime_box.end(), [](auto& it){std::cout << it << ' ';});
  std::cout << '\n';
}
