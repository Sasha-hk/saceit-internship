# Date

Table of contents:

- [Requirements](./requirements.md)

**Usage:**

```c++
#include "date.h"
#include <iostream>

using namespace std;

int  main() {
  // create date object
  Date date = Date("2000.01.04 12:05:04");

  // output
  cout << date << endl;

  return 0;
}
```

Output:

```sh
2000.01.04 12:05:04
```

**Complex example:**

```c++
#include "date.h"
#include <iostream>

using namespace std;

int  main() {
  // create two date objects
  Date date = Date("2000.01.04 12:05:04");
  Date otherDate = Date("2000.01.04 12:05:04");

  // << operator overflow (output)
  cout << date << endl;
  cout << otherDate << endl;

  // compare operator overflow
  if (date == otherDate) {
    cout << "date == other date" << endl;
  }
  else {
    cout << "date != other date" << endl;
  }

  // add 4 hours to the current hours
  date.appendHours(4);

  cout << endl << "Date after appendHours:" << endl;

  cout << date << endl;
  cout << otherDate << endl;

  if (date <= otherDate) {
    cout << endl << "date == other date" << endl;
  }
  else {
    cout << "date != other date" << endl;
  }

  // set 4 hour
  date.setHours(4);

  cout << endl << "Date after setHours:" << endl;

  cout << date << endl;
  cout << otherDate << endl;

  if (date < otherDate) {
    cout << "date == other date" << endl;
  }
  else {
    cout << "date != other date" << endl;
  }

  return 0;
}
```

Outptu:

```sh
2000.01.04 12:05:04
2000.01.04 12:05:04
date == other date

Date after appendHours:
2000.01.04 16:05:04
2000.01.04 12:05:04
date != other date

Date after setHours:
2000.01.04 04:05:04
2000.01.04 12:05:04
date == other date
```

**Constructors:**

```c++
#include "date.h"
#include <iostream>

using namespace std;

int  main() {
  // based on current time
  Date = date_1 Date();

  // based on other date object
  Date date_2 = Date(date_1);

  // based on string
  Date date_3 = Date("2000.02.23 09:10:45");

  // base on numbers
  Date date_4 = Date(2010, 6, 15, 7, 24, 18);
}
```

**Append date time:**

```c++
#include "date.h"
#include <iostream>

using namespace std;

int  main() {
  Date date = Date("2000.01.02 003:04:05");

  cout << date << endl;

  date.appendSeconds(1);
  date.appendMinutes(1);
  date.appendHours(1);
  date.appendDate(1);
  date.appendMonth(1);
  date.appendYear(1);

  cout << date << endl;
}
```

Output:

```sh
Before:
2000.01.02 03:04:05

After:
2001.02.03 04:05:06
```

**Set date time:**

```c++
#include "date.h"
#include <iostream>

using namespace std;

int  main() {
  Date date = Date("2000.01.02 003:04:05");

  cout << date << endl;

  date.setSeconds(1);
  date.setMinutes(1);
  date.setHours(1);
  date.setDate(1);
  date.setMonth(1);
  date.setYear(2005);

  cout << date << endl;

  return 0;
}
```

Output:

```sh
2000.01.02 03:04:05
2005.01.01 01:01:01
```

**Get date time:**

```c++
#include "date.h"
#include <iostream>

using namespace std;

int  main() {
  Date date = Date("2000.01.02 003:04:05");

  cout << "Seconds: " << date.getSeconds() << endl;
  cout << "Minutes: " << date.getMinutes() << endl;
  cout << "Hours: " << date.getHours() << endl;
  cout << "Date: " << date.getDate() << endl;
  cout << "Month: " << date.getMonth() << endl;
  cout << "Year: " << date.getYear() << endl;

  cout << date << endl;

  return 0;
}
```

Output:

```sh
Seconds: 5
Minutes: 4
Hours: 3
Date: 2
Month: 1
Year: 2000
2000.01.02 03:04:05
```
