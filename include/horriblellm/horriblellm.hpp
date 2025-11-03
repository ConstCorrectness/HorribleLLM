#ifndef HORRIBLE_LLM_HPP_
#define HORRIBLE_LLM_HPP_

#include <type_traits>
#include <format>
#include <iostream>
#include <typeinfo>
#include <concepts>

namespace horrible::utils
{

template<typename T, size_t NUM_BYTES = sizeof(T), size_t NUM_BITS = sizeof(T) * 8>
struct TINFO {
public:
  constexpr explicit TINFO() noexcept = default;
  constexpr size_t num_bytes() const noexcept { return NUM_BYTES; }
  constexpr size_t num_bits() const noexcept { return NUM_BITS; }

  friend std::ostream& operator<<(std::ostream& os, TINFO<T, NUM_BYTES, NUM_BITS> const& t) {
    return os << std::format("horrible::utils::tinfo<{}, {}, {}>", typeid(T).name(), t.num_bytes(), t.num_bits());
  }
};

template<typename T> 
concept is_not_pointer = !std::is_pointer_v<T>;

template<typename T>
concept Comparable = requires(T a, T b) {
  { a < b } -> std::convertible_to<bool>;
};


template<Comparable T> 
T max(T const& a, T const& b) requires is_not_pointer<T> {
  return b < a ? a : b;
}



}             // end namespace horrible::utils



#endif        // HORRIBLE_LLM_HPP_