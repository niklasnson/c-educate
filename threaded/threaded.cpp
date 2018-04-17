#include <iostream>
#include <thread>
#include <mutex>

#define NUM_THREADS 5

std::mutex num_mutex;

void adder(int &num) {
  num_mutex.lock();
  for (int i=0; i < 6; ++i) 
    ++num; 
  num_mutex.unlock(); 
}

void reducer(int &num) {
  num_mutex.lock(); 
  for (int i=0; i < 3; --i)
    num = num - 1;  
  num_mutex.unlock(); 
}


int main (int argc, char* argv[]) {
  int num{0}; 
  std::thread t1(adder, std::ref(num)); 
  std::thread t2(adder, std::ref(num));
  std::thread t3(adder, std::ref(num));
  std::thread t4(adder, std::ref(num));

  std::cout << t1.get_id() << std::endl; 

  t1.join();
  t2.join(); 
  t3.join();
  t4.join(); 
  std::cout << "value of n is now <" << num << ">" << std::endl;  
  return 0; 
}