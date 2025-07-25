#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "WeatherRecord.h"
#include "AVL.h"
#include "Map.h"
#include "CSVRecord.h"

using std::string;
using std::ifstream;
using std::runtime_error;
using std::invalid_argument;

// Inform the compiler about the Controller class since Controller
// may not be defined yet. Forward declaration is used here.
class Controller;

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
   * \brief Get the first key in the model.
   * \return The first int key.
   */
   int GetFirstKey();

   /**
    * \brief Get the last key in the model.
    * \return The last unsigned key.
    */
   int GetLastKey();

   /**
    * \brief Get weather records for a specific date.
    * \param date The date for which to retrieve records.
    * \return A reference to the AVL tree containing weather records for the specified date.
    */
   const AVL<WeatherRecord>* Get(const Date& date) const;
  private:
  /**
   * \brief A map to hold weather records indexed by year and month.
   */
  Map<int, AVL<WeatherRecord>> m_weather_records;

  /**
   * \brief The earliest year in the weather records.
   */
  int m_earliest_year;

  /**
   * \brief The latest year in the weather records.
   */
  int m_latest_year;
};

#endif
