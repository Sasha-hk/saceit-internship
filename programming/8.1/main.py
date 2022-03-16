from random import randint


def fill_data(data):
  new_data = {}
  print("Fill data:")
  for i in range(len(data)):
    print(f'\n >>> {i}')

    new_data['licenseNumber'] = int(input(' license number: '))
    new_data['fullName'] = input(' full name: ')
    new_data['dataOfBirth'] = input(' date of birth: ')
    new_data['weaponType'] = input(' weapon type: ')
    new_data['price'] = input(' price: ')

    data[i] = new_data
    new_data = {}

  print('')    

def show_data(data, message = 'Data: '):
  print(message)
  for i in data:
    print(i)

  print('')    

def sort_by_license_number(data):
  swap = None

  for i in range(len(data)):
    for j in range(len(data)):
      if data[i]['licenseNumber'] < data[j]['licenseNumber']:
        swap = data[j]
        data[j] = data[i]
        data[i] = swap

def get_by_type(data, type: str):
  result = []
  for i in range(len(data)):
    if data[i]['weaponType'] == type:
      result.append(data[i])

  return result


def main():
  weapon_default = [
    {
      'licenseNumber': None,
      'fullName': None,
      'dateOfBirth': None,
      'weaponType': None,
      'price': None,
    }
  ]

  count = int(input("Enter count of weapon: "))

  weapon = [weapon_default for i in range(count)]

  fill_data(weapon)

  show_data(weapon)

  sort_by_license_number(weapon)

  show_data(weapon)

  type = input("Enter weapon type for search: ")

  show_data(get_by_type(weapon, type), 'Result:')


if __name__ == '__main__':
  main()
