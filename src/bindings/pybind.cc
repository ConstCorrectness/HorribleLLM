#include <pybind11/pybind11.h>

#include "horriblellm/horriblellm.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_horriblellm, m) {
    m.doc() = "HorribleLLM C++ core bindings";
    m.def("add", [](float a, float b) { return a + b; });
}
