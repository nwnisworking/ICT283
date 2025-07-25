#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "View.h"
#include "Model.h"

class View;
class Model;

/**
 * \brief The Controller class acts as an intermediary between the View and Model.
 */
class Controller{
  public:
  /**
   * \brief Constructor for the Controller class.
   * \param view Reference to the View object.
   * \param model Reference to the Model object.
   */
  Controller(View &view, Model &model);

  /**
   * \brief Initialize the Controller.
   */
  void Init() const;

  /**
   * \brief Get the wind speed for a specific month and year.
   * \param date The date for which to retrieve the wind speed.
   * \param result A Vector to store the wind speed data.
   */
  void GetWindSpeed(const Date& date, Vector<float>& result) const;

  /**
   * \brief Get the temperature for a specific year.
   * \param date The date for which to retrieve the temperature.
   * \param result A Vector to store the temperature data.
   */
  void GetTemperature(const Date& date, Vector<float>& result) const;

  /**
   * \brief Get the Pearson Correlation Coefficient (SPCC) for a specific month.
   * \param date The date for which to retrieve the SPCC.
   * \param wind_speeds A Vector to store the wind speed data.
   * \param temperatures A Vector to store the temperature data.
   * \param solar_radiations A Vector to store the solar radiation data.
   */
  void GetSPCC(Date date, Vector<float>& wind_speeds, Vector<float>& temperatures, Vector<float>& solar_radiations) const;

  /**
   * \brief Save data for a specific year.
   * \param date The selected date to save data.
   * \param wind_speed_map A map to store wind speed data indexed by date.
   * \param temperature_map A map to store temperature data indexed by date.
   * \param solar_radiation_map A map to store solar radiation data indexed by date.
   */
  void GetDataForYear(Date date, Map<Date, Vector<float>>& wind_speed_map, Map<Date, Vector<float>>& temperature_map, Map<Date, Vector<float>>& solar_radiation_map) const;

  /**
   * \brief Get the first key in the model.
   * \return The first key as an integer.
   */
  int GetFirstKey() const;

  /**
   * \brief Get the last key in the model.
   * \return The last key as an integer.
   */
  int GetLastKey() const;

  private:
  /**
   * \brief Handles rendering of the view.
   */
  View& m_view;

  /**
   * \brief Handles the retrieval of data from the model.
   */
  Model& m_model;
};

#endif
