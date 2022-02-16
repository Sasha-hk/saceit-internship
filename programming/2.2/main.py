from math import atan, tan, exp, sqrt, log, atan
from random import randint


y = 0
x = randint(0, 10)
x1 = 0.011
x3 = 1.546
K = 0.800
L = 7.145

a = (K * x**5 - 10 * exp(-x))**(1/3)
b = (log(L))**1/3 * tan(x)

condition = a**2 + b**2

if condition > 0.1:
  y = atan(a - 5 * b)

elif condition <= 0.1:
  y = atan(5 * a + 3 * b)

print('Result:', y)
