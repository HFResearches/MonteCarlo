cmake_minimum_required(VERSION 3.10)

project(MonteCarlo
  LANGUAGES CXX
  VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)
set(PROJECT_NAME MonteCarlo)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set(CMAKE_COMPILER_C_LAUNCHER 
    "${CCACHE_PROGRAM}")

  set(CMAKE_COMPILER_CXX_LAUNCHER
    "${CCACHE_PROGRAM}")
endif()

add_executable(MonteCarlo
  src/main.cpp)

add_library(MonteCarlolib
  src/MarketData)

target_include_directories(MonteCarlo
  PRIVATE src)

target_link_libraries(MonteCarlo PRIVATE
  PRIVATe MonteCarlolib)
