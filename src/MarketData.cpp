#include <string>
#include <limits>

#include <atomic>
#include <chrono>
#include <thread>

#include <unistd.h>

#include "MarketData.hpp"

uint32_t max{std::numeric_limits<uint32_t>::max()};
uint32_t x{0};
uint32_t maxCompare{max};

candle* period;
inline uint32_t xOR()noexcept{
  for(std::atomic<uint32_t> u{0}; u.load(
    std::memory_order_relaxed) <
    maxCompare; u++){
 
    max ^= max << u.load(
     std::memory_order_acquire);
   
    max ^= max >> u.load(
      std::memory_order_acquire);

   return max;
}

inline uint32_t rangeAt()noexcept{
  return 0 + xOR() % (100 - 0 + 1);
}

double  asa{0.0};
size_t MAXIDX{0uz};

void MketData(){
  for(std::atomic<size_t>a{0uz};
    a.load(std::memory_order_relaxed) <
    1024; a++){

    *period{
      new candle(1);
    };

    MAXIDX{
      sizeof(period) % 4
    };

    asa{
      100.000 + ((rangeAt()
      / 1000) - (rangeAt() / 
      1000))
    };

    double* cashFlow{
      &asa
    };

   
    period[MAXIDX]->open{
      *cashFlow
    };

    period[MAXIDX]->high{
      *cashFlow
    };

    period[MAXIDX]->low{
      *cashFlow
    };

    period[MAXIDX]->close{
      *cashFlow
    };

    if(MAXIDX >= 1024){
      std::this_thread::sleep_for(
        std::chrono::milliseconds(500));

      delete period[];
    }
  }
}
