#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::getline;
using std::stoi;

/**
 * \brief Time class to represent time in a 24-hour format
 * \details This class encapsulates time in a 24-hour format with hours and minutes.
 */
class Time{
  public:
  /**
   * \brief Default constructor for Time object
   */
  Time();

  /**
   * \brief Parametized constructor for Time object
   * \param hours hours in a 24-hour format
   * \param minutes time in minutes
   */
  Time(unsigned hours, unsigned minutes);

  /**
   * \brief Time destructor
   */
  virtual ~Time(){}

  /**
   * \brief Get the hours in a 24-hour format
   * \return Hours in a 24-hour format
   */
  unsigned GetHours() const;

  /**
   * \brief Set the hours in a 24-hour format
   * \param hours Hours in a 24-hour format ranging from 0 to 23
   */
  void SetHours(unsigned hours);

  /**
   * \brief Get the minutes
   * \return Minutes ranging from 0 to 59
   */
  unsigned GetMinutes() const;

  /**
   * \brief Set the minutes
   * \param minutes Minutes ranging from 0 to 59
   */
  void SetMinutes(unsigned minutes);

  private:
  /**
   * \brief Hours in a 24-hour format
   */
  unsigned m_hours;
  
  /**
   * \brief Minutes ranging from 0 to 59
   */
  unsigned m_minutes;
};


/**
 * \brief Overloaded output operator for Time object
 * \param output Output stream
 * \param time Time object to output
 * \return Output stream
 */
ostream& operator <<(ostream& output, const Time& time);

/**
 * \brief Overloaded input operator for Time object
 * \param input Input stream
 * \param time Time object to input
 * \return Input stream
 */
istream& operator >>(istream& input, Time& time);

#endif
