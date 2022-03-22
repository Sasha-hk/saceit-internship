#pragma once
#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <string>
#include <chrono>

/*
 * Date object
 */
class Date {
  private:
  protected:
    int daysInMonth[12];
    long unixTime;
    int leapYears;
    int days;
    int year;
    int month;
    int date;
    int hours;
    int minutes;
    int seconds;

  public:
    /**
     * Create from current time
     */
    Date();

    // /**
    //  * Create date from string
    //  *
    //  * @param date Date string
    //  *
    //  * @overload
    //  */
    // Date(string date);

    // /**
    //  * Create date from other date
    //  *
    //  * @param date Other date object
    //  *
    //  * @overload
    //  */
    // Date(Date *date);

    // /**
    //  * Create date from numbers
    //  *
    //  * @param year year
    //  * @param month month
    //  * @param date date
    //  * @param hours hours
    //  * @param minutes minutes
    //  * @param seconds seconds
    //  *
    //  * @overload
    //  */
    // Date(
    //   unsigned int year,
    //   unsigned int month = 0,
    //   unsigned int date = 1,
    //   unsigned int hours = 0,
    //   unsigned int minutes = 0,
    //   unsigned int seconds = 0
    // );
    // void enter();
    // void display();

    int getSeconds();
    int getMinutes();
    int getHours();
    int getDate();
    int getMonth();
    int getYear();
};

#endif
