#include <cstdint>
#include <atomic>
#include <thread>
#include <iostream>

#define max8 UINT8_MAX
#define max16 UINT16_MAX

static uint8_t next, seed{1};
static uint8_t init;

void Srand(){
  next++;
  seed++;
}

uint16_t Rand(){
  return ((next++) *
    (max8 - next));
}

int main(void){
  std::thread i(Srand); 
  i.join();
  
  while(true){
    std::cout << (Rand() % (1 + 100)) <<
      "\n";
  }

  return {0};
}
