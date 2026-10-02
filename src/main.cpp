#include <iostream>
#include <thread>
#include <iomanip>
#include <chrono>
#include "MarketData.hpp"

size_t x{0uz};
//testing
int engulfing{0};
bool condition{false};

size_t Idx(size_t x){
  for(size_t t{0uz}; t < x; t++) return t;
}

int main(){
  std::thread t(MonteCarlo);
  t.detach();
  
  while(true){
    std::cout << "volatility:" << std::setprecision(17) 
    << volatility(10,1,10) << 
    " :" << period.size() << "\n";
 
    if(period.empty() || 10 > period.size())
      std::this_thread::sleep_for(
      std::chrono::milliseconds(5));
    
  }

  return {};
}
