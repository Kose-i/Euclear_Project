#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct Number{
  int den, num;
};

bool is_judge(const int& num1, const int& den1, const int& num2, const int& den2) {
  return (num1*den2 == num2*den1);
}
void unit_test() {
  std::cout <<\
  (is_judge(49, 98, 4,8)?"Yes\n":"No\n");
}

int main(int argc, char** argv) {

  //unit_test();
  //return 0;

  std::vector<Number> vec_ans;
  for (auto i=1;i<10;++i) {
    for (auto j=1;j<10;++j) {
      if (j==i) continue;
      for (auto k=1;k<10;++k) {
        if (k==j||k==i)continue;
        Number t; t.den=k; t.num=j;
        if (is_judge(10*i+j, 10*k+i, j, k)&&(10*i+j<10*k+i)) {
          vec_ans.push_back(t);
          //Number t2; t2.den=10*k+i; t2.num=10*i+j;
          //vec_ans.push_back(t2);
        }
        if (is_judge(10*i+j, 10*i+k, j, k)&&(10*i+j<10*i+k)) {
          vec_ans.push_back(t);
          //Number t2; t2.den=10*i+k; t2.num=10*i+j;
          //vec_ans.push_back(t2);
        }
        if (is_judge(10*j+i, 10*k+i, j, k)&&(10*j+i<10*k+i)) {
          vec_ans.push_back(t);
          //Number t2; t2.den=10*k+i; t2.num=10*j+i;
          //vec_ans.push_back(t2);
        }
        if (is_judge(10*j+i, 10*i+k, j, k)&&(10*j+i<10*i+k)) {
          vec_ans.push_back(t);
          //Number t2; t2.den=10*i+k; t2.num=10*j+i;
          //vec_ans.push_back(t2);
        }
      }
    }
  }
  //std::cout << "size:" << vec_ans.size() << '\n';
  //for (const auto& e : vec_ans) {
  //  cout << e.num << '/' << e.den << '\n';
  //}

  int num_prod {1};
  int den_prod {1};

  for (const auto& e : vec_ans) {
    num_prod *= e.num;
    den_prod *= e.den;
  }
  vector<int> prime_ten{2,3,5,7};
  for (const auto& e : prime_ten) {
    while (num_prod%e==0 && den_prod%e==0) {
      num_prod /= e;
      den_prod /= e;
    }
  }
  cout << den_prod << '\n';
}
