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

# ============================================
# 🧠 HorribleLLM Documentation Build System
# ============================================

# Find Python for running Sphinx
if(NOT Python_EXECUTABLE)
  find_package(Python3 COMPONENTS Interpreter REQUIRED)
  set(Python_EXECUTABLE ${Python3_EXECUTABLE})
endif()

# Try to find Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
  message(STATUS "Found Doxygen: ${DOXYGEN_EXECUTABLE}")
  set(DOXYGEN_AVAILABLE TRUE)
else()
  message(WARNING "⚠️  Doxygen not found — C++ API docs will be skipped.")
  set(DOXYGEN_AVAILABLE FALSE)
endif()

# Doxygen configuration template
set(DOXYFILE_IN ${CMAKE_SOURCE_DIR}/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

if(DOXYGEN_AVAILABLE AND EXISTS ${DOXYFILE_IN})
  configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)
endif()

# Documentation target
add_custom_target(docs
  COMMENT "Generating documentation (Doxygen + Sphinx)"
  COMMAND ${CMAKE_COMMAND} -E echo "🧾 Checking dependencies..."
  COMMAND ${Python_EXECUTABLE} -m pip install --upgrade sphinx myst-parser sphinx-rtd-theme breathe
  # Run Doxygen if available
  COMMAND ${CMAKE_COMMAND} -E echo "📗 Running Doxygen (if available)..."
  COMMAND ${CMAKE_COMMAND} -E env DOXYGEN_AVAILABLE=${DOXYGEN_AVAILABLE}
          ${CMAKE_COMMAND} -P "${CMAKE_SOURCE_DIR}/cmake/run_doxygen.cmake"
  # Run Sphinx always (it can still generate Markdown & Python docs)
  COMMAND ${CMAKE_COMMAND} -E echo "📘 Running Sphinx..."
  COMMAND ${Python_EXECUTABLE} -m sphinx -b html ${CMAKE_SOURCE_DIR}/docs ${CMAKE_BINARY_DIR}/docs_html
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  VERBATIM
)