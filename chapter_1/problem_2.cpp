#include <iostream>
#include <string>

void reverseString(std::string word) {
  //do something
  int endIndex = word.size() - 1;
  if(endIndex == 0) {
    std::cerr << "NO WORD" << std::endl;
  }
  for(int i = endIndex; i >= 0; i--) {
    std::cout << word[i];
  }
}

int main() {
  std::string word = "string";
  reverseString(word);
  return 0;
}
