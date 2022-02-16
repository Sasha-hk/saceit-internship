from math import sin, sqrt, cos, atan, exp
from random import randint


x = randint(0, 10)
y = randint(0, 10)

while x == y: 
  y = randint(0, 10)


c = sqrt(x + y)
d = cos(x * y)
z = (atan(x + y) - 1.5 * exp(x) * c + sqrt(abs(d)))

print(z)
