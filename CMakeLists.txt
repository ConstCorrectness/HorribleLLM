cmake_minimum_required(VERSION 3.20)

project(
  HorribleLLM
  DESCRIPTION "Horribly Awesome LLM"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Python configuration ---
# Try to auto-detect active interpreter if not provided
if(NOT DEFINED Python_EXECUTABLE)
    find_program(Python_EXECUTABLE NAMES python3 python)
    if(Python_EXECUTABLE)
        message(STATUS "Using detected Python executable: ${Python_EXECUTABLE}")
    else()
        message(WARNING "No Python executable found — please set Python_EXECUTABLE manually.")
    endif()
endif()

# Build options
option(HORRIBLE_BUILD_TESTS "Build HorribleLLM tests" ON)
option(HORRIBLE_BUILD_BENCHMARKS "Build HorribleLLM benchmarks" ON)

# --- Dependencies ---
find_package(Python COMPONENTS Interpreter Development REQUIRED)
include(FetchContent)

# GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

# Google Benchmark
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.9.4
)
FetchContent_MakeAvailable(benchmark)

# pybind11
FetchContent_Declare(
  pybind11
  GIT_REPOSITORY https://github.com/pybind/pybind11.git
  GIT_TAG v2.13.1
)
FetchContent_MakeAvailable(pybind11)

# --- Project subdirectories ---
add_subdirectory(src)

if(HORRIBLE_BUILD_TESTS)
  add_subdirectory(tests)
endif()

if(HORRIBLE_BUILD_BENCHMARKS)
  add_subdirectory(benchmarks)
endif()

