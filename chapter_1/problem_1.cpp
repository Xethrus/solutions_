#include <iostream>
#include <string>

bool allUnqiueChar(std::string word) {
  if(word.size() > 128) { return false; }
  bool boolArray[128];
  for(int i = 0; i <= word.size(); i++) {
    int value = word[i];
    if(boolArray[value]) { 
      std::cout
      << "false" << 
      std::endl;
      return false; 
    }
    boolArray[value] = true;
  }
  return true;
}
int main() {
  std::string word = "boonno";
  allUnqiueChar(word);
  return 0;
}
