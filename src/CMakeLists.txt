add_executable(horrible_main
  main.cc
)


add_library(horrible_core
  core/Tensor.cc
)

target_include_directories(horrible_main 
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)


target_include_directories(horrible_core 
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

# Python bindings
pybind11_add_module(horriblellm bindings/pybind.cc)
target_include_directories(horriblellm PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(horriblellm PRIVATE horrible_core)

# Optional install into site-packages
install(TARGETS horriblellm
    LIBRARY DESTINATION ${Python_SITEARCH}
)

