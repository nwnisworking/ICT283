#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "WeatherRecord.h"
#include "Vector.h"

using std::string;
using std::ifstream;
using std::stof;
using std::runtime_error;

// Inform the compiler about the Controller class since Controller
// may not be defined yet. Forward declaration is used here.
class Controller;

// Define aliases for different weather parameters
const string WIND_SPEED_ALIAS[] = {"Wind_Speed", "S", ""};

const string SOLAR_RADIATION_ALIAS[] = {"Solar_Rad", "SR", ""};

const string TEMPERATURE_ALIAS[] = {"Ambient_Air_Temperature", "Temperature", "T", ""};

/**
 * \brief The Model class handles the weather data and provides methods to find records based on date.
 */
class Model{
  public:
  /**
   * \brief Constructor for the Model class.
   * \param source The source file containing weather data.
   */
  Model(const string& source);

  /**
   * \brief Sets the controller for the model.
   * \param controller Pointer to the Controller object.
   */
  void SetController(const Controller* controller);

  /**
   * \brief Finds weather records for a specific month and year.
   * \param data A vector of WeatherRecord pointers to append the results to.
   * \param month The month to search for (1-12).
   * \param year The year to search for.
   */
  void FindDate(Vector<WeatherRecord*>& data, unsigned month, unsigned year);

  /**
   * \brief Finds weather records for a specific year.
   * \param data A vector of WeatherRecord pointers to append the results to.
   * \param year The year to search for.
   */
  void FindDate(Vector<WeatherRecord*>& data, unsigned year);

  private:
  /**
   * \brief A vector to hold weather records.
   */
  Vector<WeatherRecord> weather_records;

  /**
   * \brief A pointer to the Controller object.
   */
  const Controller* m_controller;

  /**
   * \brief Trims leading and trailing whitespace from a string.
   * \param str The string to be trimmed.
   */
  static void Trim(string& str);

  /**
   * \brief Analyzes the header line of the data file and populates the headers vector.
   * \param headers A vector to hold the headers.
   * \param line The line to be analyzed.
   */
  void AnalyzeHeader(Vector<string> &headers, const string& line);

  /**
   * \brief Finds the index of an alias in the headers vector.
   * \param header The vector of headers.
   * \param alias The alias to be searched for from the list of aliases.
   * \return The index of the alias in the headers vector, or -1 if not found.
   */
  int FindAlias(const Vector<string>& header, const string* alias);
};

#endif
