#pragma once
#ifndef DATE_H
#define DATE_H

#include <string>

using std::string;

/*
 * Date object
 */
class Date {
  private:
    void adjustUnixTime();

  protected:
    time_t unixTime;
    struct tm TIME;

  public:
    /**
     * Create data based on current time
     */
    Date();

    /**
     * Create date from string
     *
     * @param date Date string
     *
     * @overload
     */
    Date(string date);

    /**
     * Create date from other date
     *
     * @param date Other date object
     *
     * @overload
     */
    Date(Date *datePtr);

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
    );

    /**
     * Enter date from keyboard
     */
    void enter();

    /**
     * Brow human readable time
     */
    void display();

    /**
     * Return human readable date
     */
    string getString();

    /**
     * Return seconds
     * @return seconds
     */
    int getSeconds();

    /**
     * Return minutes
     * @return minutes
     */
    int getMinutes();

    /**
     * Return hours
     * @return hours
     */
    int getHours();

    /**
     * Return date
     * @return date
     */
    int getDate();

    /**
     * Return month
     * @return month
     */
    int getMonth();

    /**
     * Return year
     * @return year
     */
    int getYear();

    /**
     * Return count of seconds from UNIX epoch
     * @return seconds
     */
    long getUnixTime();

    /**
     * Return time struct
     * @return time object
     */
    tm getTime();

    /**
     * Set seconds
     * @param seconds Count of seconds to set
     */
    void setSeconds(int seconds);

    /**
     * Set minutes
     * @param minutes Count of minutes to set
     */
    void setMinutes(int minutes);

    /**
     * Set hours
     * @param hours Count of hours to set
     */
    void setHours(int hours);

    /**
     * Set date
     * @param date Date to set
     */
    void setDate(int date);

    /**
     * Set month
     * @param date Date to set
     */
    void setMonth(int month);

    /**
     * Set year
     * @param year Year to set
     */
    void setYear(int year);

    /**
     * Overload << operator
     */
    friend std::ostream& operator<<(std::ostream& out, const Date& date);

    /**
     * Overload == operator
     */
    friend bool operator==(Date& first, Date& second);

    /**
     * Overload != operator
     */
    friend bool operator!=(Date& first, Date& second);

    /**
     * Overload < operator
     */
    friend bool operator<(Date& first, Date& second);

    /**
     * Overload > operator
     */
    friend bool operator>(Date& first, Date& second);

    /**
     * Overload <= operator
     */
    friend bool operator<=(Date& first, Date& second);


    /**
     * Overload >= operator
     */
    friend bool operator>=(Date& first, Date& second);

    /**
     * Destructor
     */
    ~Date();
};

#endif /* End of DATE_H */
