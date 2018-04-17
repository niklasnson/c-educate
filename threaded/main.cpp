#include <iostream>
#include <string>
#include <iomanip> 
#include <vector>

typedef std::vector<int> int_vect_t; 

void system_info (std::string msg) {
  std::cout << " × " << msg << std::endl; 
}

void adder(int_vect_t &numbers) {
  int num = numbers.back(); 
  numbers.push_back(++num);
}

void system_init (void) {
  system_info("executing the setup...");
  return; 
}

void vector_list (int_vect_t &numbers) {
  for (auto num : numbers ) {
    std::cout << num << std::endl; 
  }
}

int main (int argc, char* argv[]) {
  int_vect_t numbers{0}; 
  for (int i = 0; i < 2500; i++)
    adder(ref(numbers));

  

  system_init(); 
  return 0; 
}