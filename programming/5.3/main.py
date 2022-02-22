from random import randint 

n = 9
arr = [[randint(0, 100) for i in range(n)] for j in range(n)]

max_value = arr[0][0]
min_value = arr[0][0]

tt = 0
for i in range(0, int(n / 2 + 1)):
  for j in range(tt, n - tt):
    if arr[i][j] > max_value:
      max_value = arr[i][j]

  tt += 1


bt = int(n / 2 - 1)
for i in range(int(n / 2 + 1), n):
  for j in range(bt, n - bt):
    if arr[i][j] > max_value:
      max_value = arr[i][j]

  bt -= 1

rt = n
for i in range(0, int(n / 2)):
  for j in range(rt, n):
    if arr[i][j] > max_value:
      max_value = arr[i][j]

  rt -= 1
    
lt = 1
for i in range(0, n):
  for j in range(0, lt):
    if arr[i][j] < min_value:
      min_value = arr[i][j]

  if i >= n / 2:
    lt -= 1

  else:
    lt += 1

rp = int(n / 2)
for i in range(0, int(n / 2 + 1)):
  for j in range(rp, n):
    if arr[i][j] > max_value:
      max_value = arr[i][j]


# output
for i in range(0, n):
  for j in range(0, n):
    print(arr[i][j], end=' ')
  
  print()

print()
print(' - Min value:', min_value)
print(' - Max value:', max_value)
