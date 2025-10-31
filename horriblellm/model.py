import numpy as np

from .core import Tensor

class HorribleModel:
  """A hilariously minimal MLP model."""
  def __init__(self, in_dim, out_dim):
    self.weights = Tensor(np.random.randn(in_dim, out_dim))
    self.bias = Tensor(np.zeros(out_dim))

  def forward(self, x: Tensor):
    return Tensor(x.data @ self.weights.data + self.bias.data)
    

