#include <iostream>
#include <thread>

#include <chrono>
#include "MarketData.hpp"

size_t x{0uz};
//testing
int main(){
  using namespace std::chrono_literals;

  std::thread t(MonteCarlo);
  t.join();
  
  std::cin >> x;

  while(true){
    if(period.size() < x){
       std::this_thread::sleep_for(20ms);
    } else {
      std::cout << "body:" << body(x) << "\n";
    }
  }

  return {};
}
