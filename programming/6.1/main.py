from random import randint


def genearate_payment(data):
  for i in range(len(data)):
    data[i] = randint(10000, 15000) / 100 * 80

  return data

def generate_time(data):
  for i in range(len(data)):
    data[i] = randint(0, 32)

  return data

y_time = [i for i in range(10)]
g_time = [i for i in range(15)]

y_payment = [i for i in range(10)]
g_payment = [i for i in range(15)]

y_time = generate_time(y_time)
g_time = generate_time(g_time)

y_payment = genearate_payment(y_payment)
g_payment = genearate_payment(g_payment)

y_average_payment = 0
g_average_payment = 0

for i in y_payment:
  y_average_payment += i

for i in g_payment:
  g_average_payment += i

y_average_payment = y_average_payment / 10
g_average_payment = g_average_payment / 15

if y_average_payment > g_average_payment:
  print('Y avarage payment time more than G')

else:
  print('G avarage payment time more than Y')
