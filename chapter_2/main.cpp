#include <iostream>
#include <cmath>

int main() {
  int divisor = 10;
  int number = 975;
  int temp = number;
  int count = 0;
  int printVal;
  while (number / divisor > 0) {
    number = number / divisor;
    count++;
  }
  int array[count + 1] = {};
  for (int i = 1; i <= count + 1; i++) {
    int power = std::pow(divisor, i);
    std::cout << (temp % power) << std::endl;
    array[i] = (temp % power);
  }
}
