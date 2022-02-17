from ast import parse
from random import randint 


natural_number_view = [
  'zero',
  'one',
  'two',
  'three',
  'four',
  'five',
  'six',
  'seven',
  'eight',
  'nine',
  'ten',
]

to_twenty_number_view = [
  '',
  'eleven',
  'twelve',
  'thirteen',
  'fuorteen',
  'fifteen',
  'sixteen',
  'seventenn',
  'eightenn',
  'ninetenn',
]

dozens_number_view = [
  '',
  'ten',
  'twenty',
  'thirty',
  'fourty',
  'fifty',
  'sixty',
  'seventy',
  'eighty',
  'ninety',
]

def parse_natural_numbers(number: int) -> str:
  if (number % 10 <= 10 and number % 10):
    return natural_number_view[number % 10]
  
  return ''


def parse_to_twenty_numbers(number: int) -> str:
  if (number < 20 and number > 10):
    return to_twenty_number_view[number % 10]

  return ''


def parse_dozens_numbers(number: int) -> str:
  dozens_number = number // 10

  if (dozens_number_view != 1):
    return dozens_number_view[dozens_number]

  return ''


def parse_number_year(number: int) -> str:
  out_string = []


  if number <= 10:
    out_string.append(parse_natural_numbers(number))

  elif number <= 11 and number >= 20:
    out_string.append(parse_to_twenty_numbers(number))

  elif number >=20:
    out_string.append(parse_dozens_numbers(number))
    out_string.append(parse_natural_numbers(number))

  out_string[0] = out_string[0].title()

  return ' '.join(out_string)


def main():
  yearNumber = randint(20, 69)

  print('Year number:', yearNumber)

  print(parse_number_year(yearNumber))


if __name__ == '__main__':
  main()
