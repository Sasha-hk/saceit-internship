from math import sqrt, sin, log, log10, exp


x = input('Enter x: ')

v16 = (x**2 + sqrt(sin(x)**2) - log(x**2)) / log10(x + sqrt(5.5 * x + log(x))**1.3) - exp(2.5 + x**2)

print(v16)
