#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::getline;

/**
 * 
 */
class Date{
  public:
  /**
   * \brief Default constructor for Date object
   */
  Date();
  
  /**
   * \brief Parametized constructor for Date object
   * \param day_of_month day of the month
   */
  Date(unsigned day_of_month, unsigned month, unsigned year);

  /**
   * \brief Date destructor 
   */
  virtual ~Date(){}

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

  private:
  unsigned m_day_of_month;
  unsigned m_month;
  unsigned m_year;
};

ostream& operator <<(ostream& output, const Date& date);
istream& operator >>(istream& input, Date& date);

#endif

// 420 756 344 313 4
// jt7JW3GZ
