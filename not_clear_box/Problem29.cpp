#include <vector>
#include <cmath>

#include <iostream>

/*素因数から考える*/

namespace prob29{
  std::vector<unsigned> make_prime_to(const unsigned& target) {
    if (target <= 1) {
      std::cerr << "target is too small\n";
    }
    std::vector<unsigned> correct_prime(target + 1,1);
    correct_prime[0] = correct_prime[1] = 0;
    for (auto i = 2;i <= target;++i) {
      if (correct_prime[i] == 0) {
        continue;
      }
      for (auto j = 2;i*j <= target;++j) {
        correct_prime[i * j] = 0;
      }
    }
    std::vector<unsigned> prime_box;
    for (auto i = 2;i <= target;++i) {
      if (correct_prime[i] == 1) {
        prime_box.push_back(i);
      }
    }
    return prime_box;
  }

  unsigned long saiki_combination(const std::vector<unsigned>& target_vec, const unsigned& max, const unsigned& pos, const unsigned& now_score) {
    if (target_vec.size() <= pos) {
      return 1;
    } else if (max < now_score) {
      std::cerr << "max < now_score error\n";
      return 0;
    } else if (now_score*target_vec[pos] > max){
      return 1;
    } else {
      unsigned long combination_count{};
      combination_count += saiki_combination(target_vec, max, pos + 1, now_score);
      combination_count += saiki_combination(target_vec, max, pos, now_score*target_vec[pos]);
      combination_count += saiki_combination(target_vec, max, pos + 1, now_score*target_vec[pos]);
      return combination_count;
    }
  }

  unsigned long combination(const std::vector<unsigned>& target_vec, const unsigned& max) {
    return saiki_combination(target_vec, max, 0, 1);
  }

  unsigned long make_answer(std::vector<unsigned>& target_vec, const unsigned& max) {
    unsigned long make_in_max = combination(target_vec, max) * 100;
    /*引く数*/
    /*2の累乗2^100 (2^2)^51*/
    /*3の累乗3^100 (3^2)^51*/
    /*5の累乗5^100 (5^2)^51*/
    /*7の累乗7^100 (7^2)^51*/
    return make_in_max;
  }

};

int main(int argc, char** argv) {
  std::vector<unsigned> answer = prob29::make_prime_to(100);
  std::cout << prob29::make_answer(answer, 100) << '\n';
}
