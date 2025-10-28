#ifndef HORRIBLE_TENSOR_HPP_
#define HORRIBLE_TENSOR_HPP_


template<typename T, size_t NUM_ROWS, size_t NUM_COLS>
class Tensor {
public:


  constexpr explicit Tensor() noexcept = default;      // explicit -- prevents copy-list-initialization: Tensor t = { };



  constexpr size_t rows() const noexcept { return NUM_ROWS; }
  constexpr size_t cols() const noexcept { return NUM_COLS; }

private:
  size_t rows_ { NUM_ROWS };
  size_t cols_ { NUM_COLS };
};




#endif        // HORRIBLE_TENSOR_HPP_