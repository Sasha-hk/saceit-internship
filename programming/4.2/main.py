from random import randint

def generate_data_item(i: int) -> float:
  return 1.12 * randint(-i * randint(0, 50), 100)

def fill_data(data):
  for i in range(len(data)):
    data[i] = generate_data_item(i % 10)

  return data

def find_max_index(data):
  max_value = data[0]
  max_index = None
  for i in range(len(data)):
    if data[i] > max_value:
      max_value = data[i]
      max_index = i

  return max_index

data = [None] * 20
data = fill_data(data)
swap = 0

# swap indexes
max_index = find_max_index(data)
swap = data[4]
data[4] = data[max_index]
data[max_index] = swap

print('Data before swap:')

for i in data:
  print('%.2f' % i)

print('\nData after swap:')
for i in range(len(data)):
  if i == max_index:
    print('%.2f' % data[i], ' <<< swapred')

  elif i == 4:
    print('%.2f' % data[i], ' <<< swapre')

  else:
    print('%.2f' % data[i])



