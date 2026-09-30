#include <iostream>
#include <thread>
#include <iomanip>
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
    for(size_t sumloop{0uz}; sumloop < 10; sumloop++)
    std::cout << "volatility:" << std::setprecision(17) 
    << volatility(sumloop, 10) << 
    " :" << period.size() << "\n";
 
    if(period.empty() || 10 > period.size())
      std::this_thread::sleep_for(
      std::chrono::milliseconds(5));
    
  }

  return {};
}
