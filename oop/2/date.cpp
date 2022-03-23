#include "date.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

// data staff
int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// staff functions
void tokenize(std::string const &str,
  const char delim,
  std::vector<std::string> &out)
{
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
  {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

string checkZero(int num) {
  if (num < 10) {
    return '0' + to_string(num);
  }
  return to_string(num);
}

int mod(int div, int divider) {
  return int(floor(div / divider));
}

// private
void Date::adjustUnixTime() {
  unixTime = mktime(&TIME);
}

// public
Date::Date() {
  unixTime = time(NULL);
  TIME = *localtime(&unixTime);
}

Date::Date(string datetime) {
  string datePart = datetime.substr(0, datetime.find(' '));
  string timePart = datetime.substr(datetime.find(' ') + 1, -1);
  int parseDateIndex = 0;
  int year = 1970;
  int month = 0;
  int date = 1;

  int parseTimeIndex = 0;
  int hours = 0;
  int minutes = 0;
  int seconds = 0;

  // parse date part
  std::vector<std::string> dateOptions;
  tokenize(datePart, '.', dateOptions);

  year = stoi(dateOptions[0]) - 1900;
  month = stoi(dateOptions[1]);
  date = stoi(dateOptions[2]);

  // parse time part
  std::vector<std::string> timeOptions;
  tokenize(timePart, ':', timeOptions);

  hours = stoi(timeOptions[0]);
  minutes = stoi(timeOptions[1]);
  seconds = stoi(timeOptions[2]);

  // initialize time
  unixTime = time(NULL);
  TIME = *localtime(&unixTime);

  TIME.tm_year = year;
  TIME.tm_mon = month;
  TIME.tm_mday = date;
  TIME.tm_hour = hours;
  TIME.tm_min = minutes;
  TIME.tm_sec = seconds;

  adjustUnixTime();
}

Date::Date(Date *datePtr) {
  unixTime = datePtr->getUnixTime();
  TIME = datePtr->getTime();
}

Date::Date(
  unsigned int year,
  unsigned int month,
  unsigned int date,
  unsigned int hours,
  unsigned int minutes,
  unsigned int seconds
) {
  time_t current_time = time(NULL);
  TIME = *localtime(&current_time);

  TIME.tm_year = year;
  TIME.tm_mon = month;
  TIME.tm_mday = date;
  TIME.tm_hour = hours;
  TIME.tm_min = minutes;
  TIME.tm_sec = seconds;

  adjustUnixTime();
}

void Date::enter() {
  int year, month, date, hours, minutes, seconds;

  cout << "Enter year:";
  cin >> year;
  cout << "Enter month:";
  cin >> month;
  cout << "Enter date:";
  cin >> date;
  cout << "Enter hours:";
  cin >> hours;
  cout << "Enter minutes:";
  cin >> minutes;
  cout << "Enter seconds:";
  cin >> seconds;

  TIME.tm_year = year;
  TIME.tm_mon = month;
  TIME.tm_mday = date;
  TIME.tm_hour = hours;
  TIME.tm_min = minutes;
  TIME.tm_sec = seconds;

  unixTime = mktime(&TIME);
}

void Date::display() {
  cout
    << checkZero(getYear()) << "."
    << checkZero(getMonth()) << "."
    << checkZero(getDate()) << " "
    << checkZero(getHours()) << ":"
    << checkZero(getMinutes()) << ":"
    << checkZero(getSeconds()) << endl;
}

string Date::getString() {
  return checkZero(getYear()) + '.'
    + checkZero(getMonth()) + '.'
    + checkZero(getDate()) + ' '
    + checkZero(getHours()) + ':'
    + checkZero(getMinutes()) + ':'
    + checkZero(getSeconds());
}

int Date::getSeconds() {
  return TIME.tm_sec;
}

int Date::getMinutes() {
  return TIME.tm_min;
}

int Date::getHours() {
  return TIME.tm_hour;
}

int Date::getDate() {
  return TIME.tm_mday;
}

int Date::getMonth() {
  return TIME.tm_mon;
}

int Date::getYear() {
  return TIME.tm_year + 1900;
}

long Date::getUnixTime() {
  return unixTime;
}

tm Date::getTime() {
  return TIME;
}

void Date::setSeconds(int seconds) {
  TIME.tm_sec = seconds;
  adjustUnixTime();
}

void Date::setMinutes(int minutes) {
  TIME.tm_min = minutes;
  adjustUnixTime();
}

void Date::setHours(int hours) {
  TIME.tm_hour = hours;
  adjustUnixTime();
}

void Date::setDate(int date) {
  TIME.tm_mday = date;
  adjustUnixTime();
}

void Date::setMonth(int month) {
  TIME.tm_mon = month;
  adjustUnixTime();
}

void Date::setYear(int year) {
  TIME.tm_year = year;
  adjustUnixTime();
}

void Date::appendSeconds(int seconds) {
  int sum = TIME.tm_sec + seconds;

  if (sum > 60) {
    appendMinutes(mod(sum, 60));
    TIME.tm_sec += sum % 60;
  }
  else {
    TIME.tm_sec = sum;
  }

  adjustUnixTime();
}

void Date::appendMinutes(int minutes) {
  int sum = TIME.tm_min + minutes;

  if (sum > 60) {
    appendHours(mod(sum, 60));
    TIME.tm_min += sum % 60;
  }
  else {
    TIME.tm_min = sum;
  }

  adjustUnixTime();
}

void Date::appendHours(int hours) {
  int sum = TIME.tm_hour + hours;

  if (sum > 60) {
    appendDate(mod(sum, 60));
    TIME.tm_hour += sum % 60;
  }
  else {
    TIME.tm_hour = sum;
  }

  adjustUnixTime();
}

void Date::appendDate(int date) {
  int sum = TIME.tm_mday + date;
  int days = daysInMonth[getMonth()];

  if (sum > days) {
    appendDate(mod(sum, days));
    TIME.tm_mday += sum % days;
  }
  else {
    TIME.tm_mday = sum;
  }

  adjustUnixTime();
}

void Date::appendMonth(int month) {
  int sum = TIME.tm_mon + month;

  if (sum > 11) {
    appendYear(mod(sum, 11));
    TIME.tm_mon += sum;
  }
  else {
    TIME.tm_mon = sum;
  }

  adjustUnixTime();
}

void Date::appendYear(int year) {
  TIME.tm_year += year;
  adjustUnixTime();
}

ostream& operator<<(ostream& out, Date& date) {
  out << date.getString();
  return out;
}

bool operator==(Date& first, Date& second) {
  if (first.getUnixTime() == second.getUnixTime()) {
    return true;
  }
  return false;
}

bool operator!=(Date& first, Date& second) {
  if (first.getUnixTime() != second.getUnixTime()) {
    return true;
  }
  return false;
}

bool operator<(Date& first, Date& second) {
  if (first.getUnixTime() < second.getUnixTime()) {
    return true;
  }
  return false;
}

bool operator>(Date& first, Date& second) {
  if (first.getUnixTime() > second.getUnixTime()) {
    return true;
  }
  return false;
}

bool operator<=(Date& first, Date& second) {
  if (first.getUnixTime() <= second.getUnixTime()) {
    return true;
  }
  return false;
}

bool operator>=(Date& first, Date& second) {
  if (first.getUnixTime() >= second.getUnixTime()) {
    return true;
  }
  return false;
}

Date::~Date() {
  // no need to free any date
}
