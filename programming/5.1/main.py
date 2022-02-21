from random import randint
from prettytable import PrettyTable

table = PrettyTable()
table.field_names = [f'{i}' for i in range(10)]
data = [[None] * 10] * 10

def generate_data_item():
  return randint(-16 * 10 * randint(0, 10), 10 * 10 * 10)

def generate_data(data):
  for i in range(len(data)):
      data[i] = [generate_data_item() for i in range(len(data[i]))]

  return data


data = generate_data(data)

for i in data:
  table.add_row(i)

min_index_n = 0
min_index_k = 0
min_value = data[0][0]

max_index_n = 0
max_index_k = 0
max_value = data[0][0]


for i in range(len(data)):
  for j in range(len(data[i])):
    if data[i][j] < min_value:
      min_value = data[i][j]
      min_index_n = i
      min_index_k = j

    if data[i][j] > max_value:
      max_value = data[i][j]
      max_index_n = i
      max_index_k = j

print(table)
print()
print(f'Min\n  n:{min_index_n}\n  k:{min_index_k}\n')
print(f'Max\n  n:{max_index_n}\n  k:{max_index_k}')
