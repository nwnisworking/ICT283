#ifndef MTIME_H
#define MTIME_H

/**
 * \brief Time class to represent time in a 24-hour format
 * \details This class encapsulates time in a 24-hour format with hours and minutes. Since this breaks the Time class, it is renamed.
 */
class MTime{
  public:
  /**
   * \brief Default constructor for Time object
   */
  MTime();

  /**
   * \brief Parametized constructor for Time object
   * \param hours hours in a 24-hour format
   * \param minutes time in minutes
   */
  MTime(unsigned hours, unsigned minutes);

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

#endif