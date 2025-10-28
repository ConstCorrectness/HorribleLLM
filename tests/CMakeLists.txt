enable_testing()

add_executable(horrible_tests
    test_tensor.cc
)
target_link_libraries(horrible_tests PRIVATE
    horrible_core
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(horrible_tests)
