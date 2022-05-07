#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

/**
 * Mod devision
 *
 * @param dev to division
 * @param divider divider
 */
int mod(int div, int divider) {
  return int(floor(div / divider));
}

/*
 * Date time
 */
class Date {
  private:
    /**
     * Adjust TIME to unixTime
     */
    void adjustUnixTime() {
      unixTime = mktime(&TIME);
    }

    /**
     * Tokenize string
     *
     * @param str string to check
     * @param delim delimiter
     * @param out pointer to vector for output
     */
    void tokenize(
      std::string const &str,
      const char delim,
      std::vector<std::string> &out
    ) {
      size_t start;
      size_t end = 0;

      while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
      {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
      }
    }

    /**
     * Check if value less that 10 then add 0 before the number
     *
     * @param num number to check
     */
    string checkZero(int num) {
      if (num < 10) {
        return '0' + to_string(num);
      }
      return to_string(num);
    }

  protected:
    int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    time_t unixTime;
    struct tm TIME;

  public:
    /**
     * Create data based on current time
     */
    Date() {
      unixTime = time(NULL);
      TIME = *localtime(&unixTime);
    }

    /**
     * Create date from string
     *
     * @param date string view datatime
     *
     * @overload
     */
    Date(string datetime) {
      // initialize time
      unixTime = time(NULL);
      TIME = *localtime(&unixTime);

      if (datetime.find('.') < datetime.length()) {
        string datePart = datetime.substr(0, datetime.find(' '));

        int parseDateIndex = 0;
        int year = 1970;
        int month = 0;
        int date = 1;

        // parse date part
        std::vector<std::string> dateOptions;
        tokenize(datePart, '.', dateOptions);

        year = stoi(dateOptions[0]) - 1900;
        month = stoi(dateOptions[1]);
        date = stoi(dateOptions[2]);

        TIME.tm_year = year;
        TIME.tm_mon = month + 1;
        TIME.tm_mday = date;
      } else {
        throw invalid_argument( "Required year.month.date properties" );
      }

      if (datetime.find(' ') < datetime.length() ) {
        string timePart = datetime.substr(datetime.find(' ') + 1, -1);
        int parseTimeIndex = 0;
        int hours = 0;
        int minutes = 0;
        int seconds = 0;

        // parse time part
        std::vector<std::string> timeOptions;
        tokenize(timePart, ':', timeOptions);

        hours = stoi(timeOptions[0]);
        minutes = stoi(timeOptions[1]);
        seconds = stoi(timeOptions[2]);

        TIME.tm_hour = hours;
        TIME.tm_min = minutes;
        TIME.tm_sec = seconds;
      } else {
        TIME.tm_hour = 1;
        TIME.tm_min = 0;
        TIME.tm_sec = 0;
      }

      adjustUnixTime();
    }

    /**
     * Create date from other date
     *
     * @param date Other date object
     *
     * @overload
     */
    Date(Date *datePtr) {
      unixTime = datePtr->getUnixTime();
      TIME = datePtr->getTime();
    }

    /**
     * Create date from numbers
     *
     * @param year year
     * @param month month
     * @param date date
     * @param hours hours
     * @param minutes minutes
     * @param seconds seconds
     *
     * @overload
     */
    Date(
      unsigned int year,
      unsigned int month = 0,
      unsigned int date = 1,
      unsigned int hours = 0,
      unsigned int minutes = 0,
      unsigned int seconds = 0
    ) {
      time_t current_time = time(NULL);
      TIME = *localtime(&current_time);

      TIME.tm_year = year - 1900;
      TIME.tm_mon = month;
      TIME.tm_mday = date;
      TIME.tm_hour = hours;
      TIME.tm_min = minutes;
      TIME.tm_sec = seconds;

      adjustUnixTime();
    }

    /**
     * Enter date from keyboard
     */
    void enter() {
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

      TIME.tm_year = year - 1900;
      TIME.tm_mon = month;
      TIME.tm_mday = date;
      TIME.tm_hour = hours;
      TIME.tm_min = minutes;
      TIME.tm_sec = seconds;

      unixTime = mktime(&TIME);
    }

    /**
     * Brow human readable time
     */
    void display() {
      cout << getString() << endl;
    }

    /**
     * Return human readable date
     */
    string getString() {
      return checkZero(getYear()) + '.'
        + checkZero(getMonth()) + '.'
        + checkZero(getDate()) + ' '
        + checkZero(getHours()) + ':'
        + checkZero(getMinutes()) + ':'
        + checkZero(getSeconds());
    }

    /**
     * Return seconds
     * @return seconds
     */
    int getSeconds() {
      return TIME.tm_sec;
    }

    /**
     * Return minutes
     * @return minutes
     */
    int getMinutes() {
      return TIME.tm_min;
    }

    /**
     * Return hours
     * @return hours
     */
    int getHours() {
      return TIME.tm_hour;
    }

    /**
     * Return date
     * @return date
     */
    int getDate() {
      return TIME.tm_mday;
    }

    /**
     * Return month
     * @return month
     */
    int getMonth() {
      return TIME.tm_mon + 1;
    }

    /**
     * Return year
     * @return year
     */
    int getYear() {
      return TIME.tm_year + 1900;
    }

    /**
     * Return count of seconds from UNIX epoch
     * @return seconds
     */
    long getUnixTime() {
      return unixTime;
    }

    /**
     * Return time struct
     * @return time object
     */
    tm getTime() {
      return TIME;
    }

    /**
     * Set seconds
     * @param seconds Count of seconds to set
     */
    void setSeconds(int seconds) {
      TIME.tm_sec = seconds;
      adjustUnixTime();
    }

    /**
     * Set minutes
     * @param minutes Count of minutes to set
     */
    void setMinutes(int minutes) {
      TIME.tm_min = minutes;
      adjustUnixTime();
    }

    /**
     * Set hours
     * @param hours Count of hours to set
     */
    void setHours(int hours) {
      TIME.tm_hour = hours;
      adjustUnixTime();
    }

    /**
     * Set date
     * @param date Date to set
     */
    void setDate(int date) {
      TIME.tm_mday = date;
      adjustUnixTime();
    }

    /**
     * Set month
     * @param date Date to set
     */
    void setMonth(int month) {
      TIME.tm_mon = month;
      adjustUnixTime();
    }

    /**
     * Set year
     * @param year Year to set
     */
    void setYear(int year) {
      TIME.tm_year = year - 1900;
      adjustUnixTime();
    }

    /**
     * Append seconds
     * @param seconds Seconds to append
     */
    void appendSeconds(int seconds) {
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

    /**
     * Append minutes
     * @param minutes Minutes to append
     */
    void appendMinutes(int minutes) {
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

    /**
     * Append hours
     * @param hours Hours to append
     */
    void appendHours(int hours) {
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

    /**
     * Append date
     * @param date Date to append
     */
    void appendDate(int date) {
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

    /**
     * Append month
     * @param month Month to append
     */
    void appendMonth(int month) {
      int sum = TIME.tm_mon + month;

      cout << sum << endl;

      if (sum > 11) {
        appendYear(mod(sum, 11));
        TIME.tm_mon = sum % 11 - 1;
      }
      else {
        TIME.tm_mon = sum % 11;
      }

      adjustUnixTime();
    }

    /**
     * Append year
     * @param year Year to append
     */
    void appendYear(int year) {
      TIME.tm_year = TIME.tm_year + year;
      adjustUnixTime();
    }

    /**
     * Overload << operator
     */
    friend ostream& operator<<(ostream& out, Date& date){
      out << date.getString();
      return out;
    }



    /**
     * Overload == operator
     */
    friend bool operator==(Date& first, Date& second) {
      if (first.getUnixTime() == second.getUnixTime()) {
        return true;
      }

      return false;
    }

    /**
     * Overload != operator
     */
    friend bool operator!=(Date& first, Date& second) {
      if (first.getUnixTime() != second.getUnixTime()) {
        return true;
      }

      return false;
    }

    /**
     * Overload < operator
     */
    friend bool operator<(Date& first, Date& second) {
      if (first.getUnixTime() < second.getUnixTime()) {
        return true;
      }

      return false;
    }

    /**
     * Overload > operator
     */
    friend bool operator>(Date& first, Date& second) {
      if (first.getUnixTime() > second.getUnixTime()) {
        return true;
      }

      return false;
    }

    /**
     * Overload <= operator
     */
    friend bool operator<=(Date& first, Date& second) {
      if (first.getUnixTime() <= second.getUnixTime()) {
        return true;
      }

      return false;
    }


    /**
     * Overload >= operator
     */
    friend bool operator>=(Date& first, Date& second) {
      if (first.getUnixTime() >= second.getUnixTime()) {
        return true;
      }

      return false;
    }

    /**
     * Destructor
     */
    ~Date() {
      // no need to free any date
    }
};

#endif /* End of DATE_H */
