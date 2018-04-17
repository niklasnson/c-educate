#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

typedef std::vector<std::string> str_vect_t; 

void list_words(str_vect_t &vec_t) {
  for (auto w : vec_t) {
    std::cout << w << std::endl; 
  }
}

void add_word(std::string word, str_vect_t &vec_t) {
  vec_t.push_back(word); 
}

int main (int argc, char* argv[]) {
  if (argc == 1) {
    std::cerr << "error: no inputfile" << std::endl; 
    return 1; 
  }

  std::fstream ifs; 
  std::string  reader; 
  str_vect_t   vec_t; 

  ifs.open(argv[1]);
  if (!ifs.is_open()) {
    std::cerr << "error: file could not be opend" << std::endl;
    return 1; 
  }

  while (ifs >> reader ) {
    add_word(reader, vec_t); 
  }

}