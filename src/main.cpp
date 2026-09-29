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
    for(size_t sumloop{0uz}; sumloop < 4; sumloop++)
    std::cout << "volatility:" << volatility(sumloop) << 
    " :" << period.size() << "\n";
 
    if(period.empty() || 3 > period.size())
      std::this_thread::sleep_for(
      std::chrono::milliseconds(5));
    do{
        period.clear();
    }while(period.size() >= 1024); 
  }

  return {};
}
