#include "date.cpp"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// Date makeDate(string date) {
//   return Date(date);
// }

int  main() {
  srand(time(NULL));

  Date date = Date("2000.01.04 12:13:04");

  Date otherDate = Date();

  // time_t now;
  // struct tm tm_now;
  // struct tm tm_later;

  // now = time ( NULL );
  // tm_now = *localtime ( &now );
  // tm_later = *localtime ( &now );

  // tm_later.tm_hour = 12;

  // printf ( "%s", asctime ( &tm_now ) );
  // printf ( "%s", asctime ( &tm_later ) );

  // cout << endl << date.getString() << endl;
  // cout << otherDate.getString() << endl;

  // cout << date << endl;
  // cout << otherDate << endl;


  // if (date == otherDate) {
  //   cout << "date == other date" << endl;
  // }
  // else {
  //   cout << "date != other date" << endl;
  // }

  return 0;
}
