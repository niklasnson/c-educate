#include <iostream>
#include <fstream>
#include <string>

void usage(char* argv[]) {
  std::cout << "Usage: " << argv[0] << " FILENAME" << std::endl; 
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    usage(argv);
    return 0; 
  }

  std::ifstream file;
  file.open(argv[1]); 

  std::string tmp;
  int count{0};  

  if (file.is_open()) {
    while (file >> tmp) {
      count++;
    }
  }

  std::cout << argv[1] << " contains " << count << " words." << std::endl; 

  return 0; 
}