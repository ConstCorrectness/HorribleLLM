# --- Core executables and libraries ---

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

# --- Python bindings ---
pybind11_add_module(_horriblellm bindings/pybind.cc)
target_include_directories(_horriblellm PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(_horriblellm PRIVATE horrible_core)

# Force all configs to output to the Python package folder
foreach(CONFIG_TYPE IN ITEMS Debug Release RelWithDebInfo MinSizeRel)
    set_target_properties(_horriblellm PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY_${CONFIG_TYPE} "${PROJECT_SOURCE_DIR}/horriblellm"
        RUNTIME_OUTPUT_DIRECTORY_${CONFIG_TYPE} "${PROJECT_SOURCE_DIR}/horriblellm"
        ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_TYPE} "${PROJECT_SOURCE_DIR}/horriblellm"
    )
endforeach()


# --- Copy compiled module into the Python package after build ---
add_custom_command(TARGET _horriblellm POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_FILE:_horriblellm>
            "${PROJECT_SOURCE_DIR}/horriblellm/$<TARGET_FILE_NAME:_horriblellm>"
)

