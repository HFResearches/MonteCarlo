#include <iostream>
#include <thread>

#include <chrono>
#include "MarketData.hpp"

size_t x{0uz};
//testing
int engulfing{0};

int main(){
  using namespace std::chrono_literals;

  std::thread t(MonteCarlo);
  t.detach();
  
  while(true){
    if(period.size() < 3){
      std::cerr << "it isnt pushing anything here into period.size()!\n";
    } else {
      
      bool condition = (body(idx(2)) < body(idx(3))
      && (net(idx(1)) < 0 || net(idx(1)) > 0));
      if(condition){
        engulfing+=1;
        
        std::cout << "engulfing:" << engulfing << "\n";
      }
 
      if(period.size() >= 3096){
        period.clear();

        engulfing = 0;
      }
    }
  }

  return {};
}
