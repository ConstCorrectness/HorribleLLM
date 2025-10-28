#include <pybind11/pybind11.h>

#include "horriblellm/horriblellm.hpp"

namespace py = pybind11;

PYBIND11_MODULE(horriblellm, m) {
    m.doc() = "HorribleLLM - a delightfully cursed LLM from scratch";
    m.def("add", [](float a, float b) { return a + b; });
}

