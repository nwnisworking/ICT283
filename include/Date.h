#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>

using std::string;
using std::out_of_range;

/**
 * \brief The Date class representing a specific date.
 */
class Date{
  public:
  /**
   * \brief Default constructor for Date object
   */
  Date();

  /**
   * \brief Parametized constructor for Date object
   * \param day_of_month Day of the month
   * \param month Month
   * \param year Year 
   */
  Date(unsigned day_of_month, unsigned month, unsigned year);

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
   * \brief Set the month
   * \param month Month value
   */
  void SetMonth(unsigned month);

  /**
   * \brief Get the month
   * \return Month value
   */
  unsigned GetMonth() const;

  /**
   * \brief Set day of the month
   * \param day_of_month Day of the month
   */
  void SetDayOfMonth(unsigned day_of_month);

  /**
   * \brief Get day of the month
   * \return Get day of the month
   */
  unsigned GetDayOfMonth() const;

  /**
   * \brief Converts a month number to its string representation.
   * \param month The month number (1-12).
   */
  static const string& MonthToString(unsigned month);

  private:
  /**
   * \brief The day of the month (1-31).
   */
  unsigned m_day_of_month;

  /**
   * \brief The month (1-12).
   */
  unsigned m_month;

  /**
   * \brief The year (e.g., 2023).
   */
  unsigned m_year;
};

#endif