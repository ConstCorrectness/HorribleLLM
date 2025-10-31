from importlib import import_module

# Import compiled C++ backend
_core = import_module("._horriblellm", __package__)

# Re-export bindings
add = _core.add
tensor_info = getattr(_core, "tensor_info", lambda: "no tensor info yet")

__all__ = ["add", "tensor_info"]

