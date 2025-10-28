#include <iostream>
#include <filesystem>
#include <atomic>
#include <utility>
#include <type_traits>
#include <format>

#include <horriblellm/horriblellm.hpp>

namespace fs = std::filesystem;

int main(int argc, char **argv, char **envp) {
  std::cout << std::format("CWD: {}", fs::current_path().string()) << std::endl;
 

  return 0;
}