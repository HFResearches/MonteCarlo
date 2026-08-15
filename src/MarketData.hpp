#include <iostream>
#include <mutex>
#include <vector>

struct candle{
  double open,
    high,low,
    close;
};

extern std::vector<candle> period;
extern std::mutex mtx;

void MonteCarlo();

double body(size_t x);
