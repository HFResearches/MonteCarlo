#include <iostream>
#include <atomic>

#include <exception>
#include <stdexcept>
#include <thread>
#include <chrono>

#define MAX__IDX UINT8_MAX
#define MIN__IDX UINT8_MIN

template <typename x>
class Vector{
  private:
    x* valor;
    
    static std::atomic <uint8_t> iSum{MIN__IDX};
    const static uint8_t __bufferSize{sizeof(&valor) % 4};
    
  public:
    const void* Push_(x Valor){
      if(iSum.load
        (std::memory_order_relaxed) <
        MAX__IDX){

        iSum.fetch_add
          (1, std::memory_order_acq_rel);
 
        valor = new x; 
        valor[iSum.load
          (std::memory_order_acquire)] =

          valor;
      }     
    }

    std::atomic <const x*> ValueAt
      (const uint8& i){

      std::atomic <x> receive_this;
      try{
        if(__bufferSize >= i){
          receive_this.store
            (valor[i], 
            std::memory_order_release);

          return receive_this.load
            (std::memory_order_acquire);
        }

        if(__buffersize < i){ 
          throw std::runtime_error
            ("out of the index\n");

          std::this_thread::sleep_for
            (chrono::milliseconds(10));
              
        }
        
      }catch(const std::exception& Ex__){
         std::cerr << "problem: "
           << Ex__.what() << "\n";
      }
      
      return {(void)};         
    } 
};
