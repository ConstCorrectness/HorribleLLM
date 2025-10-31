#!/usr/bin/env python3
"""
train_basic.py
---------------
A minimal example of using HorribleLLM's Python API and C++ core bindings
to train a hilariously small neural network on fake data.
"""

import numpy as np
import horriblellm as hllm


def generate_data(n=128, in_dim=4, out_dim=2):
  """Generate a fake linear dataset y = Wx + b + noise."""
  X = np.random.randn(n, in_dim).astype(np.float32)
  true_W = np.random.randn(in_dim, out_dim).astype(np.float32)
  true_b = np.random.randn(out_dim).astype(np.float32)
  y = X @ true_W + true_b + 0.1 * np.random.randn(n, out_dim).astype(np.float32)
  return X, y


def mean_squared_error(pred, target):
  """Compute mean squared error between two numpy arrays."""
  diff = pred - target
  return np.mean(diff * diff)


def train_basic():
  print("🚀 Training a HorribleModel...")

  in_dim, out_dim = 4, 2
  model = hllm.HorribleModel(in_dim, out_dim)

  X, y = generate_data(n=256, in_dim=in_dim, out_dim=out_dim)

  lr = 0.05
  epochs = 100

  for epoch in range(epochs):
    # Forward pass
    preds = model.forward(hllm.Tensor(X))

    # Compute loss
    loss = mean_squared_error(preds.data, y)

    # Fake gradient descent
    # (This is just for demonstration; no autograd yet)
    model.weights.data -= lr * np.random.randn(*model.weights.data.shape)
    model.bias.data -= lr * np.random.randn(*model.bias.data.shape)

    if epoch % 10 == 0 or epoch == epochs - 1:
      print(f"Epoch {epoch:03d} | Loss: {loss:.4f}")

  print("✅ Training complete (in the most Horrible way possible).")


if __name__ == "__main__":
  train_basic()

