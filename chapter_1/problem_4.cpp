#include <iostream>
#include <string>
#include <vector>

void changeSpaces(std::string sentence) {
  std::vector<std::string> newSentence;  
  for(auto& letter : sentence) {
    if(isspace(letter)) {
      newSentence.push_back("%20");
    } else {
      newSentence.push_back(static_cast<std::string> (letter));
    }
  }
  for(auto& element : newSentence) {
    std::cout << element;
  }
}
