
cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/cpp-pm/hunter/archive/v0.23.218.tar.gz"
  SHA1 "9a3594a61227967fb92159339ba326701b287b19"
)

project(server)

hunter_add_package(Boost COMPONENTS log thread filesystem system date_time regex)
find_package(Boost CONFIG REQUIRED log thread filesystem system date_time regex)



add_executable(main
  ${CMAKE_CURRENT_SOURCE_DIR}main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}Client.cpp)




