# 🧠 HorribleLLM

[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg?logo=c%2B%2B)](https://en.cppreference.com/w/cpp/20)
[![Python](https://img.shields.io/badge/Python-3.10%2B-blue?logo=python)](https://www.python.org/)
[![Pybind11](https://img.shields.io/badge/Bindings-pybind11-orange?logo=python)](https://pybind11.readthedocs.io/)
[![HorribleLLM CI](https://github.com/horribleprogram/HorribleLLM/actions/workflows/cmake.yml/badge.svg)](https://github.com/horribleprogram/HorribleLLM/actions/workflows/cmake.yml)


> 🦴 *“A delightfully cursed large language model engine built from scratch.  
> Made by Horrible, for Horrible, in the most Horrible way possible.”*

---

## 🚀 Overview

**HorribleLLM** is an experimental **from-scratch large language model framework**, built in **C++20** with **Python bindings** via `pybind11`.  
It’s designed for low-level tinkering — tensors, attention mechanisms, optimizers, and all the internal machinery of modern LLMs.

Perfect if you want to learn **how GPT-style models work**, or if you just love pain. 💀

---

## 🧩 Features

- ⚙️ **Modular C++ Core** – `Tensor`, `Attention`, `Linear` layers  
- 🐍 **Python Integration** via [pybind11](https://github.com/pybind/pybind11)  
- 🧪 **Unit Tests** powered by [GoogleTest](https://github.com/google/googletest)  
- ⚡ **Benchmarks** using [Google Benchmark](https://github.com/google/benchmark)  
- 🧱 **CMake-based** — portable and IDE-friendly  
- 🔍 Fully self-contained — all dependencies auto-fetched with CMake  

---


## 🔧 Build Instructions

### 🖥️ Requirements

- CMake ≥ 3.20  
- C++20 compiler (MSVC, Clang, or GCC)  
- Python 3.10+  
- Git  

### 🛠️ Build

```bash
# Clone
git clone https://github.com/horribleprogram/HorribleLLM.git
cd HorribleLLM

# Configure and build
cmake -B build -DPython_EXECUTABLE=$(which python3)
cmake --build build -j