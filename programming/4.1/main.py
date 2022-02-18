from random import randint
from prettytable import PrettyTable


# define table
table = PrettyTable() 
table.field_names = ['year', 'income', 'tag']

# define variables
table_data_item_default = {
  "year": 0,
  "income": 0,
  "tag": "",
}
table_data = []
income = 0
tag = ''

def calculateIncome(k, i) -> float:
  return k * randint(0, 100) - i * randint(0, 50)

minIncome = 0
maxIncome = 0

for i in range(1991, 2022 + 1):
  income = calculateIncome(16, i)

  if not minIncome:
    minIncome = income

  if not maxIncome:
    maxIncome = income

  # min
  if income < 0:
    if income < minIncome:
      minIncome = i

  # max
  if income > 0:
    if income > maxIncome:
      maxIncome = i


  table_data.append({
    "year": i,
    "income": income,
  })

for i in table_data:
  if minIncome == i['year']:
    tag = 'min income'

  elif maxIncome == i['year']:
    tag = 'max income'

  else:
    tag = ''

  table.add_row([i['year'], i['income'], tag])


print(table)
