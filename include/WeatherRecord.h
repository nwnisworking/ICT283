#ifndef WEATHERRECORD_H
#define WEATHERRECORD_H

#include "Date.h"
#include "Time.h"

/**
 * \brief WeatherRecord class to represent a weather record
 * \details This class encapsulates various weather parameters such as wind speed, solar radiation, temperature, date, and time.
 */
class WeatherRecord{
  public:
  /**
   * \brief Default constructor for WeatherRecord object
   */
  WeatherRecord();

  /**
   * \brief Sets the speed of the wind in m/s.
   * \param speed Speed of the wind in m/s
   */
  void SetSpeed(int speed);
  
  /**
   * \brief Sets the solar radiation
   * \param radiation Solar radiation in W/m2
   */
  void SetRadiation(int radiation);
  
  /**
   * \brief Sets the temperature 
   * \param temperature Temperature in degrees celsius
   */
  void SetTemperature(float temperature);

  /**
   * \brief Sets the day of the month
   * \param day_of_month Day of the month ranging from 1 to 31
   */
  void SetDayOfMonth(unsigned day_of_month);

  /**
   * \brief Sets the month
   * \param month Month ranging from 1 to 12
   */
  void SetMonth(unsigned month);

  /**
   * \brief Sets the year
   * \param year Year value
   */
  void SetYear(unsigned year);

  /**
   * \brief Sets the hours in a 24-hour format
   * \param hours Hours in a 24-hour format ranging from 0 to 23
   */
  void SetHours(unsigned hours);

  /**
   * \brief Sets the minutes
   * \param minutes Minutes ranging from 0 to 59
   */
  void SetMinutes(unsigned minutes);

  /**
   * \brief Gets the speed of the wind in m/s
   * \return Speed of the wind in m/s
   */
  int GetSpeed() const;
  
  /**
   * \brief Gets the solar radiation
   * \return Solar radiation in W/m2
   */
  int GetRadiation() const;
  
  /**
   * \brief Gets the temperature
   * \return Temperature in degrees celsius
   */
  float GetTemperature() const;

  /**
   * \brief Gets the day of the month
   * \return Day of the month ranging from 1 to 31
   */
  unsigned GetDayOfMonth() const;

  /**
   * \brief Gets the month
   * \return Month ranging from 1 to 12
   */
  unsigned GetMonth() const;

  /**
   * \brief Gets the year
   * \return Year value
   */
  unsigned GetYear() const;

  /**
   * \brief Gets the hours in a 24-hour format
   * \return Hours in a 24-hour format ranging from 0 to 23
   */
  unsigned GetHours() const;

  /**
   * \brief Gets the minutes
   * \return Minutes ranging from 0 to 59
   */
  unsigned GetMinutes() const;

  private:
  /**
   * \brief Speed of the wind in m/s
   */
  int m_speed;

  /**
   * \brief Solar radiation in W/m2
   */
  int m_radiation;

  /**
   * \brief Temperature in degrees celsius
   */
  float m_temperature;

  /**
   * \brief Date of the weather record
   */
  Date m_date;

  /**
   * \brief Time of the weather record
   */
  Time m_time;
};

#endif 