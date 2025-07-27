#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>

#include "Controller.h"
#include "Date.h"
#include "Utils.h"
#include "AVL.h"
#include "WeatherRecord.h"

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
   * \brief Sets the controller.
   */
  void SetController(const Controller* controller);

  /**
   * \brief Renders the specified page.
   */
  void Render() const;

  private:
  /**
   * \brief Display the wind speed for a specific year and month.
   */
  void WindSpeedPage() const;

  /**
   * \brief Display air temperature for a specific year.
   */
  void AirTemperaturePage() const;

  /**
   * \brief Display Sample Pearson Correlation Coefficient.
   */
  void SPCCPage() const;

  /**
   * \brief Save data of the wind speed, air temperature, and solar radiation alongside average, sample deviation, and mean absolute deviation.
   */
  void SaveDataForYear() const;

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
   * \brief A pointer to the Controller object.
   */
  const Controller* m_controller;
};

#endif
