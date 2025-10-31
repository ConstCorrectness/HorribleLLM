import numpy as np

class Tensor:
  def __init__(self, data):
    self.data = np.array(data, dtype=np.float32)

  def __add__(self, other):
    return Tensor(self.data + other.data)
  
def zeros(shape):
  return Tensor(np.zeros(shape))

def ones(shape):
  return Tensor(np.ones(shape))

