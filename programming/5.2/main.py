from random import randint


duration = [randint(0, 10) for i in range(25)]

for i in duration:
  print(i, end=' ')

print()

print('Min avarage time:', min(duration))
