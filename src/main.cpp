#include <iostream>
#include <thread>

#include <chrono>
#include "MarketData.hpp"

size_t x{0uz};
//testing
int engulfing{0};
bool condition{false};

int main(){
  std::thread t(MonteCarlo);
  t.detach();
  
  while(true){
    condition = body(idx(2)) < body(idx(3))
    && (net(idx(1)) < 0 || net(idx(1)) > 0) && 
    period.size() <= 1024 && period.size() >= 3;
      if(condition){
        engulfing+=1;
        
        std::cout << "engulfing:" << engulfing << 
        " :" << period.size() << "\n";
      }
 
      if(period.empty() || 3 > period.size())
        std::this_thread::sleep_for(
        std::chrono::milliseconds(5));
      do{
        engulfing +=0;

        period.clear();
      }while(period.size() >= 1024 && engulfing >= 
       period.size()); 
  }

  return {};
}
