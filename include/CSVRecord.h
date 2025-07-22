#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include "Vector.h"
#include "WeatherRecord.h"

using std::string;
using std::ifstream;
using std::to_string;
using std::stringstream;
using std::runtime_error;
using std::invalid_argument;

// Define aliases for different weather parameters
const string WIND_SPEED_ALIAS[] = {"Wind_Speed", "S", ""};

const string SOLAR_RADIATION_ALIAS[] = {"Solar_Rad", "SR", ""};

const string TEMPERATURE_ALIAS[] = {"Ambient_Air_Temperature", "Temperature", "T", ""};

class CSVRecord{
  public:
  static void Load(const string& path, Vector<WeatherRecord>& records);

  /**
   * \brief Trims leading and trailing whitespace from a string.
   * \param str The string to be trimmed.
   */
  static void Trim(string& str);

  /**
   * \brief Extracts data from a line and populates the data vector.
   * \param data A vector to hold the extracted data.
   * \param line The line from which data is to be extracted.
   */
  static void ExtractData(Vector<string>& data, const string& line);

  /**
   * \brief Finds the index of an alias in the headers vector.
   * \param header The vector of headers.
   * \param alias The alias to be searched for from the list of aliases.
   * \return The index of the alias in the headers vector, or -1 if not found.
   */
  static int FindAlias(const Vector<string>& header, const string* alias);
};

#endif