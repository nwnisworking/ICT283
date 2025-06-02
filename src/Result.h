#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include "Unit.h"
#include "Date.h"

/**
 * \class Result
 * \brief Represents the outcome of a student's performance in a specific academic unit.
 *
 * The Result class encapsulates information pertaining to an individual academic result, 
 * including the marks obtained, the corresponding unit, and the date on which the result was recorded.
 */
class Result {
public:
  /**
   * \brief Default constructor.
   *
   * Initializes the result with default values.
   */
  Result();

  /**
   * \brief Parameterized constructor.
   *
   * Constructs a result with specified marks, unit, and date.
   * \param marks The marks obtained.
   * \param unit The academic unit associated with the result.
   * \param date The date the result was recorded.
   */
  Result(float marks, const Unit& unit, const Date& date);

  /**
   * \brief Virtual destructor.
   */
  virtual ~Result() {}

  /**
   * \brief Sets the marks obtained for the result.
   * \param marks The marks as a floating-point value.
   */
  void SetMarks(float marks);

  /**
   * \brief Retrieves the marks obtained for the result.
   * \return The marks as a floating-point value.
   */
  float GetMarks() const;

  /**
   * \brief Sets the unit associated with the result.
   * \param unit The academic unit.
   */
  void SetUnit(const Unit& unit);

  /**
   * \brief Retrieves the unit associated with the result.
   * \param unit Reference to a Unit object where the result's unit will be stored.
   */
  void GetUnit(Unit& unit) const;

  /**
   * \brief Sets the date of the result.
   * \param date The date when the result was recorded.
   */
  void SetDate(const Date& date);

  /**
   * \brief Retrieves the date of the result.
   * \param date Reference to a Date object where the result's date will be stored.
   */
  void GetDate(Date& date) const;

private:
  Unit m_unit;    /**< The academic unit associated with the result */
  float m_marks;  /**< The marks obtained */
  Date m_date;    /**< The date the result was recorded */
};


ostream& operator <<(ostream& output, const Result& result);
istream& operator >>(istream& input, Result& result);

#endif