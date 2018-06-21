#include <iostream>
#include <fstream>
#include <iomanip>

#define NUMBER_SIZE 400

int main(int argc, char** argv) {
  std::ofstream output_file("number_check.txt");
  output_file << "success is blank\n";
  for (auto i = 1;i < NUMBER_SIZE;++i) {
    output_file << i;
    if (i % 20 == 0) output_file << '\n';
    else output_file << ' ';
  }
}
