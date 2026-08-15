cmake_minimum_required(VERSION 3.20)

project(MonteCarlo
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

add_executable(MonteCarlo 
  src/main.cpp)

target_include_directories(MonteCarlo PRIVATE
  src)

add_library(MonteCarloLib
  src/MarketData.cpp)

target_link_libraries(MonteCarlo PRIVATE 
  MonteCarloLib)


