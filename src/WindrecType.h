#ifndef WindRecType_H
#define WindRecType_H

#include <iostream>
#include <string>

#include "Date.h"
#include "Time.h"

using std::istream;
using std::ostream;
using std::string;

class WindRecType{

  public:
  /**
   * \brief Set day of the month
   * \param day_of_month Day of the month ranging from 1 to 31
   */
  void SetDayOfMonth(unsigned day_of_month);

  /**
   * \brief Get day of the month
   * \return Day of the month ranging from 1 to 31
   */
  unsigned GetDayOfMonth() const;

  /**
   * Set the month
   * \param month Month ranging from 1 to 12
   */
  void SetMonth(unsigned month);

  /**
   * \brief Get the month
   * \return Month ranging from 1 to 12
   */
  unsigned GetMonth() const;

  /**
   * \brief Set the year
   * \param year Year value
   */
  void SetYear(unsigned year);

  /**
   * \brief Get the year
   * \return Year value
   */
  unsigned GetYear() const;

  /**
   * \brief Set hours in a 24-hour format
   * \param hours Hours in a 24-hour format ranging from 0 to 23
   */
  void SetHours(unsigned hours);

  /**
   * \brief Get hours in a 24-hour format
   * \return Hours in a 24-hour format ranging from 0 to 23
   */
  unsigned GetHours() const;

  /**
   * \brief Set the minutes
   * \param minutes Minutes ranging from 0 to 59
   */
  void SetMinutes(unsigned minutes);

  /**
   * \brief Get the minutes
   * \return Minutes ranging from 0 to 59
   */
  unsigned GetMinutes() const;

  /**
   * \brief Set the wind speed
   * \param speed Wind speed value
   */
  void SetSpeed(float speed);

  /**
   * \brief Get the wind speed
   * \return Wind speed value
   */
  float GetSpeed() const;

  /**
   * \brief Set the date of the wind record
   * \param date Date object representing the date of the wind record
   */
  void SetDate(const Date& date);

  /**
   * \brief Set the time of the wind record
   * \param time Time object representing the time of the wind record
   */
  void SetTime(const Time& time);

  /**
   * \brief Get the date of the wind record
   * \param date Date object to populate with the wind record's date
   */
  void GetDate(Date &date) const;

  /**
   * \brief Get the time of the wind record
   * \param time Time object to populate with the wind record's time
   */
  void GetTime(Time &time) const;

  private:
  /**
   * \brief Date of the wind record
   */
  Date m_date;

  /**
   * \brief Time of the wind record
   */
  Time m_time;

  /**
   * \brief Wind speed
   */
  float m_speed;
};

/**
 * \brief Input stream operator for WindRecType
 * \param input Input stream to read from
 * \param rec WindRecType object to read into
 * \return Reference to the input stream
 */
istream& operator >>(istream &input, WindRecType &rec);

/**
 * \brief Output stream operator for WindRecType
 * \param output Output stream to write to
 * \param rec WindRecType object to write
 * \return Reference to the output stream
 */
ostream& operator <<(ostream &output, const WindRecType &rec);

#endif
