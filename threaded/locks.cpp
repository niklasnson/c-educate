#include <iostream>
#include <vector>
#include <thread>
#include <mutex> 

std::mutex num_mutex; 

typedef std::vector<int> int_vector_t; 

void add_numbers(int_vector_t &vect) {
  if (vect.empty()) {
    std::cout << "is empty" << std::endl; 
  }
  num_mutex.lock(); 
  for (int i=0; i < 250; ++i) {
    vect.push_back(i);
  }
  num_mutex.unlock(); 
}

int main (int argc, char* argv[]) {
  int_vector_t vect; 

  std::thread t1(add_numbers, std::ref(vect));
  std::thread t2(add_numbers, std::ref(vect));
  t1.join(); 
  t2.join(); 

  for (auto num : vect ) {
    std::cout << num << std::endl; 
  }

}
