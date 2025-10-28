add_executable(horrible_bench
    bench_tensor.cc
)
target_link_libraries(horrible_bench PRIVATE
    horrible_core
    benchmark::benchmark
)