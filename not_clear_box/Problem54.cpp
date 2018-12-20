#include <iostream>
#include <vector>
#include <string>

enum class soot{
  spade,
  heart,
  crab,
  diye
};

enum class yaku{
  onepair,
  twopair,
  threecard,
  straight,
  flash,
  fulhouse,
  fourcard,
  straightflash,
  royalstraightflash
};

struct data_card{
  int number;
  enum class soot mark;
};

struct hand_power{
  int number;
  enum class yaku point_yaku;
};

class one_hand{
  typedef std::vector<struct data_card> One_hand_pair;
  public:
    one_hand(){}
    ~one_hand(){}
    void get_hand(std::string&& str){}
    void get_hand(std::string& str){}
    friend operator<(class one_hand& rhs, class one_hand& lhs) {
      return lhs.score.point_yaku < rhs.score.point_yaku || \
        (rhs.score.point_yaku == lhs.score.point_yaku && rhs.score.number > lhs.score.number);
    }
  private:
    void get_score(){}
    One_hand_pair hand;
    struct data_card score;
};
int main(int argc, char** argv) {
  int sum_winner_a{};
  std::string str{};

  while(std::getline(std::cin, str)) {
    class one_hand a_poker_card();
    auto t = str.find(' ');
    for (int i{};i < 5;++i, t=str.find(' ', ++t));
    std::string temp(str.begin(), t);
    std::string other_temp(t, str.end());
    one_hand own_hand(temp);
    one_hand enemy_hand(other_temp);
    if (enemy_hand < own_hand)++sum_winner_a;
  }
  std::cout << sum_winner_a << '\n';
}
