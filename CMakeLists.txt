
cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_COVERAGE "Build coverage" OFF)

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


project(boost_filesystem)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_executable(main
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)


target_include_directories(main
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)





hunter_add_package(Boost COMPONENTS system thread)
find_package(Boost CONFIG REQUIRED system thread)

hunter_add_package(Boost COMPONENTS asystem bind)
find_package(Boost CONFIG REQUIRED asystem bind)

hunter_add_package(Boost COMPONENTS system asio)
find_package(Boost CONFIG REQUIRED system asio)

hunter_add_package(Boost COMPONENTS system shared_ptr)
find_package(Boost CONFIG REQUIRED system shared_ptr)

hunter_add_package(Boost COMPONENTS system enable_shared_from_this)
find_package(Boost CONFIG REQUIRED system enable_shared_from_this)

target_link_libraries(main Boost::thread)
target_link_libraries(main Boost::bind)
target_link_libraries(main Boost::asio)
target_link_libraries(main Boost::shared_ptr)
target_link_libraries(main Boost::enable_shared_from_this)

enable_testing()
add_test(NAME unit_tests COMMAND tests) 

if(BUILD_COVERAGE)
  set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
  find_package(codecov)
  add_coverage(boost_asio)
  add_coverage(tests)
  list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/tests/*'")
  coverage_evaluate()
endif()
