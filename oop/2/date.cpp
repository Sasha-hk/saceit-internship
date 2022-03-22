#include "date.h"
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <time.h>

using namespace std;

// time(nullptr)

int dd(int x, int y) {
  return floor(x / y);
}

int roundUp(int numToRound, int multiple) {
  if (multiple == 0) {
    return numToRound;
  }

  int remainder = numToRound % multiple;
  if (remainder == 0) {
    return numToRound;
  }

  return numToRound + multiple - remainder;
}

int Date::getSeconds() {
  return unixTime % 60;
}

int Date::getMinutes() {
  return floor(unixTime / 60 % 60);
}

int Date::getHours() {
  return int(floor(unixTime / 60 / 60)) % 24;
}

int Date::getDate() {
  return 0;
}

int Date::getMonth() {
  return 0;
}

int Date::getYear() {
  return 1970 + unixTime / 60 / 60 / 24 / 365;
}

Date::Date() {
  time_t current_time = time(NULL);
  // tm* localtime(const time_t* current_time);

  // time_t curr_time;

	// time(&curr_time);
	// cout << "Current date and time: " << asctime(localtime(&curr_time)) << endl;


  time_t curr_time;
	curr_time = time(NULL);

	tm *tm_gmt = gmtime(&curr_time);
	cout << "Current time : " << tm_gmt->tm_hour << ":" << tm_gmt->tm_min << ":" << tm_gmt->tm_sec << " GMT";


  time_t tim;
	tm *ptr;
  int y = 2017, m = 4, d = 20;
	char weekday[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  time(&tim);
	ptr = localtime(&tim);

  ptr->tm_year = y - 1900;
	ptr->tm_mon = m - 1;
	ptr->tm_mday = d;

  mktime (ptr);

  cout << "April 20, 2017 was " << weekday[ptr->tm_wday] << endl;




  cout << unixTime << endl;
  // need to as count timezone offset
  static uint8_t daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  days = unixTime / 86400;
  unixTime = time(nullptr);

  cout << 1 << " <<< timzone " << endl;

  year = getYear();

  leapYears = floor(roundUp(year - 1970, 4) / 4);

  month = getMonth();

  date = getDate();

  hours = getHours();

  minutes = getMinutes();

  seconds = getSeconds();

  cout <<  year << "-" << month << "-" << date << " " << hours << ":" << minutes << ":" << seconds << endl;
}

// Date::Date(string date) {

// }

// Date::Date(Date *date) {

// }

// Date::Date(
//   unsigned int year,
//   unsigned int month,
//   unsigned int date,
//   unsigned int hours,
//   unsigned int minutes,
//   unsigned int seconds
// ) {

// }

// void Date::enter() {

// }

// void Date::display() {

// }
