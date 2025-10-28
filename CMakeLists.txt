cmake_minimum_required(VERSION 3.20)

project(
  HorribleLLM
  DESCRIPTION "Horribly Awesome LLM"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(HORRIBLE_BUILD_TESTS "Build HorribleLLM tests" ON)
option(HORRIBLE_BUILD_BENCHMARKS "Build HorribleLLM benchmarks" ON)

find_package(Python COMPONENTS Interpreter Development REQUIRED)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)


FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.9.4
)
FetchContent_MakeAvailable(benchmark)

# --- pybind11 (automatic download)
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG v2.13.1
)
FetchContent_MakeAvailable(pybind11)

add_subdirectory(src)



if(HORRIBLE_BUILD_TESTS)
  add_subdirectory(tests)
endif()

if(HORRIBLE_BUILD_BENCHMARKS)
  add_subdirectory(benchmarks)
endif()

