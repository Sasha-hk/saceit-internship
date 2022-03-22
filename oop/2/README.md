# Date class

Implementation: based on UNIX time.

Capabilities:

- create date from string, such as Date("2022.01.12")
- create date from numbers, such as Date(2022, 1, 12)
- append date, date.appendYear(1), the same fot others
- set date, date.setMonth(5)
- set weekday, setDayShift(6), setDayUnshift(0)
- get: year, month, date, weekDay, hours...
- set: year, month, date...
- get UNIX time
- overload operators such as: =, <, >, <=, >=, ==, !=...
