from math import pow
sum = 0
x = 16

for i in range(1, 16):
  sum += (pow(x, i) / -i) + pow(i * x, 1.0 / i)

print('Sum:', sum)
