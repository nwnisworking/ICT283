#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>

#include "Unit.h"
#include "Result.h"

using std::stol;
using std::stoi;
using std::istream;
using std::ostream;

const unsigned MAX_RESULTS = 10;

/**
 * \class Registration
 * \brief Represents a student's course registration details, including academic results.
 *
 * The Registration class encapsulates information related to a student's 
 * enrollment for a particular semester, such as the student ID, the semester 
 * number, the count of results, and the results themselves.
 */
class Registration {
public:
  /**
   * \brief Default constructor for Registration.
   *
   * Initializes all member variables to default values.
   */
  Registration();

  /**
   * \brief Retrieves the total number of academic credits earned from results.
   * \return The total credits as an unsigned integer.
   */
  unsigned GetCredits() const;

  /**
   * \brief Sets the number of results stored.
   * \param count The number of results.
   */
  void SetCount(unsigned count);

  /**
   * \brief Gets the current number of stored results.
   * \return The number of results.
   */
  unsigned GetCount() const;

  /**
   * \brief Assigns a student ID to the registration.
   * \param id The unique student ID.
   */
  void SetStudentId(long id);

  /**
   * \brief Retrieves the student ID associated with the registration.
   * \return The student ID.
   */
  long GetStudentId() const;

  /**
   * \brief Sets the semester value.
   * \param semester The semester number or identifier.
   */
  void SetSemester(unsigned semester);

  /**
   * \brief Gets the semester associated with the registration.
   * \return The semester number.
   */
  unsigned GetSemester() const;

  /**
   * \brief Assigns a result to a specific index in the result array.
   * \param result The result to assign.
   * \param index The index at which to store the result.
   */
  void SetResult(const Result& result, unsigned index);

  /**
   * \brief Retrieves a result from a specified index.
   * \param result Reference where the result will be stored.
   * \param index The index from which to retrieve the result.
   */
  void GetResult(Result& result, unsigned index) const;

private:
  long m_studentId;
  unsigned m_semester;
  unsigned m_count;     
  Result m_results[MAX_RESULTS];
};

ostream& operator <<(ostream& output, const Registration& registration);
istream& operator >>(istream& input, Registration& registration);

#endif
