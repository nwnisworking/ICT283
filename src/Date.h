#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::getline;


class Date{
  public:
  Date();
  
  Date(unsigned day_of_month, unsigned month, unsigned year);

  virtual ~Date(){}

  void SetYear(unsigned year);
  unsigned GetYear() const;

  void SetMonth(unsigned month);
  unsigned GetMonth() const;

  void SetDayOfMonth(unsigned day_of_month);
  unsigned GetDayOfMonth() const;

  private:
  unsigned m_day_of_month;
  unsigned m_month;
  unsigned m_year;
};

ostream& operator <<(ostream& output, const Date& date);
istream& operator >>(istream& input, Date& date);

#endif
