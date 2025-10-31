from importlib import import_module

_core = import_module('horriblellm')

add = _core.add
tensor_info = getattr(_core, 'tensor_info', lambda: 'no tensor info')

from .core import Tensor, zeros, ones
from .model import HorribleModel

__all__ = ["add", "tensor_info", "Tensor", "zeros", "ones", "HorribleModel"]
