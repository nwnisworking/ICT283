#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "AVL.h"
#include "WeatherRecord.h"
#include "Map.h"
#include "Vector.h"
#include "Utils.h"

using std::string;
using std::ifstream;
using std::to_string;
using std::stringstream;
using std::runtime_error;
using std::invalid_argument;

class CSVRecord{
  private:
  /**
   * \brief Wind speed aliases used in the CSV file.
   */
  static const string WIND_SPEED_ALIAS[];

  /**
   * \brief Solar radiation aliases used in the CSV file.
   */
  static const string SOLAR_RADIATION_ALIAS[];

  /**
   * \brief Temperature aliases used in the CSV file.
   */
  static const string TEMPERATURE_ALIAS[];
  public:
  /**
   * \brief Load weather records from a CSV file and populate the records map. The earliest and latest years are also retrieved.
   */
  static void Load(const string& path, Map<int, AVL<WeatherRecord>>& records, int& earliest_year, int& latest_year);

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
