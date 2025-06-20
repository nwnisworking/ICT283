#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>

#include "Controller.h"
#include "StandardDeviation.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;
using std::fixed;
using std::ofstream;
using std::isdigit;
using std::out_of_range;
class Controller;

/**
 * \brief The View class handles the user interface and displays information to the user.
 */
class View{
  public:
  /**
   * \brief Constructor for the View class.
   */
  void SetController(const Controller* controller);

  /**
   * \brief Renders the specified page.
   * \param page The page to render.
   */
  void Render(const string& page) const;

  private:
  /**
   * \brief Displays a message to continue.
   */
  void Continue() const;

  /**
   * \brief Clears the input buffer.
   */
  void ClearBuffer() const;

  /**
   * \brief Displays the home page.
   */
  void Home() const;

  /**
   * \brief Displays the average wind speed and sample standard deviation for a specific month and year.
   */
  void AvgWindSpeedAndDeviationForMonthAndYear() const;

  /**
   * \brief Displays the average ambient air temperature and sample standard deviation for each month of a specific year.
   */
  void AvgAmbientAirTemperatureAndDeviationForYear() const;

  /**
   * \brief Displays the total solar radiation in kWh/m2 for each month of a specific year.
   */
  void TotalSolarRadiationForYear() const;

  /**
   * \brief Displays the Average Wind Speed, Air Ambient Temperature, and the Total Solar Radiation for each month of a specific year
   */
  void AWSAATAndTSR() const;

  /**
   * \brief Gets the input month from the user.
   * \return The month number (1-12).
   */
  unsigned InputMonth() const;

  /**
   * \brief Gets the input year from the user.
   * \return The year number (positive integer).
   */
  unsigned InputYear() const;

  /**
   * \brief Converts a month number to its string representation.
   * \param month The month number (1-12).
   */
  static const string& MonthToString(unsigned month);

  /**
   * \brief A pointer to the Controller object.
   */
  const Controller* m_controller;
};

#endif
