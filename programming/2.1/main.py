from math import sqrt, sin, cos
from random import randint


x = randint(0, 10)

def f1(x: int) -> float:
  return 3 + x / (x + 3)

def f2(x: int) -> float:
  return (2 - x)**3 + x**-4 + 3 * x**1/2

def f3(x: int) -> float:
  return sin(x)**2 + 45 * cos(x) - 2 / (x**3 + 2)

result = f1(x) - 2 * f2(x) / f3(x)

print("Result: ", result)
