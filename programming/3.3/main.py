from math import sqrt, sin
from random import randint


def Yi(x: int) -> float:
  return sin(x)


def main():
  h = 0.1
  max = 16
  count = 0
  sum = 1
  r = 0
  i = 0

  while i < max:
    r = Yi(i)

    if r > 0:
      sum *= r
      count += 1

  print(f'Sum:   {sum}')
  print(f'Count: {count}')


if __name__ == '__main__':
  main()
