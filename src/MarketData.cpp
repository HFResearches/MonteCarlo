#include <iostream>
#include <random>

#include <mutex>
#include <vector>
#include <iomanip>
#include <algorithm>

#include <stdexcept>
#include <numeric>
#include <atomic>
#include <memory>

#include "MarketData.hpp"

std::mutex mtx;
std::vector<candle> period;

double cashflow[4];
double Cashflow[4];

constexpr double totalAssets{100.000};

double var;

std::unique_ptr<double> variance(){
  std::random_device rd;
  std::mt19937 gerar(rd());

  std::uniform_real_distribution<double>
    pointdistribuir(-0.100, 0.100);

  var = pointdistribuir(gerar);
  return std::make_unique<double>(var); 
}

bool hasOpen, hasHigh, hasLow, hasClose =
  {false};

void MonteCarlo(){
  period.reserve(1024);
  candle c;
  double d,d1={0.0}; 
    

  while(true){
    for(std::atomic<size_t> a{0uz}; a < 1024;
      a++){

      for(std::atomic<size_t> x{0uz};
        x.load(std::memory_order_relaxed)
        < 4; x++){
  
        d = *variance();
        d1 = *variance();

        cashflow[x.load(std::memory_order_relaxed)] =
          totalAssets + (d - d1);
      }

      for(std::atomic<size_t> x{0uz};
        x.load(std::memory_order_relaxed) < 4; x++){

        d = *variance();
        d1 = *variance();

        Cashflow[x.load(std::memory_order_relaxed)] =
          cashflow[x.load(std::memory_order_relaxed)] + (d - d1);
      }

      c.open = 
        Cashflow[0];

      c.close = 
        Cashflow[3];

      c.high = *std::max_element(
        std::begin(Cashflow),
        std::end(Cashflow));
       
      c.low = *std::min_element(
        std::begin(Cashflow),
        std::end(Cashflow));

      //std::cout << std::setprecision(6) << c.open << "|" << c.high
      // << "|" << c.low << "|" << c.close << "\n";   

      {
        std::lock_guard<std::mutex> lock(mtx);
        period.push_back(c);
      }
    }

    period.clear(); 
  }
}

double body(size_t x){
  try{
    {
      std::lock_guard<std::mutex> lock(mtx);
      candle c = period[x];

      return std::abs(c.open - c.close);
    }

<<<<<<< HEAD
  }else{

    std::cout << "out of the index!\n";
    
=======
    if(x > period.size()){
      throw std::runtime_error("out of the index!\n");
    }
  }catch(const std::exception& ex){
    std::cerr << "error:" << ex.what() << '\n';
    return {};
  }
}

double net(size_t x){
  try{
    {
      std::lock_guard<std::mutex> lock(mtx);
      candle c = period[x];
      return c.open - c.close;
    }

    if(x > period.size()){
      throw std::runtime_error("out of the index!\n");
    }
  }catch(const std::exception& ex){
    std::cerr << "error:" << ex.what() << '\n';
    return {};
  }
}

double lowerShadow(size_t x){
  try{
    {
      std::lock_guard<std::mutex> lock(mtx);
      candle c = period[x];
    
      return (((c.open - c.close) < 0) ? c.close - c.low : 0);
      return (((c.open - c.close) > 0) ? c.open - c.low : 0);
    }

    if(x > period.size()){
      throw std::runtime_error("out of index !\n"); 
    }
  }catch(const std::exception& ex){
    std::cerr << "error:" << ex.what() << '\n';
    return {};
  }
}

double upperShadow(size_t x){
  try{
    {
      std::lock_guard<std::mutex> lock(mtx);
      candle c = period[x];
    
      return (((c.open - c.close) < 0) ? c.open - c.high : 0);
      return (((c.open - c.close) > 0) ? c.close - c.high : 0);
    }

    if(x > period.size()){
      throw std::runtime_error("out of index !\n"); 
    }
    
  }catch(const std::exception& ex){
    std::cerr << "error:" << ex.what() << '\n';
>>>>>>> 6b21fc1 (Implemented exception system to best diagnostistics on debugging the stuffs)
    return {};
  }
}

double net(size_t x){
  if(x <= period.size()){
    {
      std::lock_guard<std::mutex>
        lock(mtx);

      candle c = period[x];
      return c.open - c.close;
    }

  }else{

    std::cout << "out of the index!\n";

    return {};
  }
}


