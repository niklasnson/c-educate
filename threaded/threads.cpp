#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

typedef std::vector<std::string> str_vec_t; 
std::mutex vec_mtx; 

void runner(str_vec_t &vect) {
  vec_mtx.lock(); 
  vect.push_back("Hello World");
  vec_mtx.unlock();  
}

int main (int argc, char* argv[]) {
  str_vec_t vect;

  std::thread t1(runner, std::ref(vect));
  std::thread t2(runner, std::ref(vect));
  t1.join(); 
  t2.join();

  for (auto c : vect) 
    std::cout << c << std::endl;
  return 0; 
} 