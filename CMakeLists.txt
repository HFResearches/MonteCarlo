cmake_minimum_required(VERSION 3.20)

project(MonteCarlo
        VERSION 1.25
        LANGUAGES CXX C)

set(CMAKE_CXX_STARNDARDS 27)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_BUILD_TYPE Debug)

find_program(CCACHE ccache)

if(CCACHE)
  set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE})
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
endif()

add_executable(MonteCarlo
               src/main.cpp)

add_library(MonteCarloLib
            src/MarketData.cpp
            src/container.cpp
            src/rand.cpp)

target_link_libraries(MonteCarlo 
                      PRIVATE
                      MonteCarloLib)
            
target_include_directories(MonteCarlo 
                           PRIVATE src)
