from matplotlib import pyplot


def makeSomething():
  x_min = -5
  x_max = 5
  h = 0.01

  roll_num = []
  marks = []

  i = x_min
  while (True):
    roll_num.append(i)
    marks.append(i**3 - i**2 - i - 1)
    i += h

    if (i >= x_max):
      break
  
  pyplot.plot(roll_num, marks) 
  
  pyplot.show() 

def main():
  makeSomething()

main()
