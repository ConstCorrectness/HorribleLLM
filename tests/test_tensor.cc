#include <gtest/gtest.h>

#include "horriblellm/Tensor.hpp"


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

