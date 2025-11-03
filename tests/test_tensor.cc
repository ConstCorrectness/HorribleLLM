#include <gtest/gtest.h>

#include "horriblellm/Tensor.hpp"
#include "horriblellm/horriblellm.hpp"


// 
constexpr size_t VOCAB_SIZE = 1'335'400;
constexpr size_t MODEL_DIM = 1'326;

TEST(HorribleLLM, Initialization) {
    // explicit Tensor<T, NUM_ROWS, NUM_COLS>::Tensor() = default;
    Tensor<float, VOCAB_SIZE, MODEL_DIM> t { };
    // Tensor<float, 10, 10> t = { };           // copy-list-initialization ERROR

    EXPECT_EQ(t.rows(), VOCAB_SIZE);
    EXPECT_EQ(t.cols(), 1'326);
}


TEST(HorribleLLM, horrible_utils_TINFO) {
    using namespace horrible::utils;
    TINFO<int> t;

    EXPECT_EQ(t.num_bits(), sizeof(int) * 8);
    EXPECT_EQ(t.num_bytes(), sizeof(int));
    
    // EXPECT_EQ(is_not_pointer<int>, true);
    // EXPECT_EQ(is_not_pointer<int * const *>, false);
    // EXPECT_EQ(is_not_pointer<int const * const>, false);

}