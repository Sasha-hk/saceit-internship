from math import sin, cos, exp
from prettytable import PrettyTable


# v 16
table = PrettyTable()
table.field_names = ['a', 'b', 'z']

def f1(x: int) -> float:
  return 3 + x / (x + 3)

def f2(x: int) -> float:
  return (2 - x)**3 + x**-4 + 3 * x**1/2

def f3(x: int) -> float:
  return sin(x)**2 + 45 * cos(x) - 2 / (x**3 + 2)

a = 0
b = 1
z = 0
x = 1

for i in range(16 + 8 + 1):
  a += f2(x)
  b *= f3(x)
  z = 3 * a * b
  table.add_row([a, b, '%.2f' % z])

print(table)