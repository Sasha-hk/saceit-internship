from random import randint

def generateData():
  return [[randint(0, 100) for j in range(10)] for i in range(5)]

def showData(data):
  for i in data:
    print(i) 

numbers1 = generateData()
numbers2 = generateData()
numbers3 = generateData()
numbers4 = generateData()

# show all arrays
print('Numbers 1:')
showData(numbers1)
print('Numbers 2:')
showData(numbers2)
print('Numbers 3:')
showData(numbers3)
print('Numbers 4:')
showData(numbers4)

print()

# has all
hasAll = [0 for i in range(102)]

for i in range(5):
  for j in range(10):
    hasAll[numbers1[i][j]] += 1
    hasAll[numbers2[i][j]] += 1
    hasAll[numbers3[i][j]] += 1
    hasAll[numbers4[i][j]] += 1

print("Has all:")

for i in range(102):
  if (hasAll[i] >= 4):
    print(hasAll[i], end=" ")

print()

# has no one
hasNoOne = [True for i in range(102)]

for i in range(5):
  for j in range(10):
    hasNoOne[numbers1[i][j]] = False
    hasNoOne[numbers2[i][j]] = False
    hasNoOne[numbers3[i][j]] = False
    hasNoOne[numbers4[i][j]] = False

print("Has no one:")

for i in range(102):
  if hasNoOne[i]:
    print(i, end=" ")

print()

# has 2 and 4
hasFew = [0 for i in range(102)]

for i in range(5):
  for j in range(10):
    hasFew[numbers2[i][j]] += 1
    hasFew[numbers4[i][j]] += 1

print("Has 2 and 4:")

for i in range(102):
  if (hasFew[i] >= 2):
    print(i, end=" ")