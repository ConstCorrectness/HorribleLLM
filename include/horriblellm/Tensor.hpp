#ifndef HORRIBLE_TENSOR_HPP_
#define HORRIBLE_TENSOR_HPP_


template<typename T, size_t NROWS, size_t NCOLS>
class Tensor {
public:
  // explicit -- prevents copy-list-initialization: Tensor t = { };
  constexpr explicit Tensor() noexcept = default;
  
  constexpr Tensor(Tensor<T, NROWS, NCOLS> const& t): rows_{t.rows_}, cols_{t.cols_} { }
  
  constexpr size_t rows() const noexcept { return NROWS; }
  constexpr size_t cols() const noexcept { return NCOLS; }

  constexpr auto operator[](size_t i) const {
    return Tensor<T, 1, NCOLS>();
  }

  constexpr auto& operator[](size_t i) {
    return Tensor<T, 1, NCOLS>();
  }
 


private:
  size_t                  rows_ { NROWS };
  size_t                  cols_ { NCOLS };
  std::unique_ptr<size_t> data_ { nullptr };
};



// 1xM row-vector
template<typename T, size_t NCOLS>
class Tensor<T, 1, NCOLS> {
  constexpr explicit Tensor() noexcept = default;

  T operator[](size_t i) const {
    return T { };
  }

private:
  size_t                  rows_ { 1 };
  size_t                  cols_ { NCOLS };
  std::unique_ptr<size_t> data_ { nullptr };
};

// Nx1 column-vector
template<typename T, size_t NROWS>
class Tensor<T, NROWS, 1> {
  T operator[](size_t i) const {
    return T { };
  }



private:
  size_t                  rows_ { NROWS };
  size_t                  cols_ { 1 };
  std::unique_ptr<size_t> data_ { nullptr };
};



#endif        // HORRIBLE_TENSOR_HPP_