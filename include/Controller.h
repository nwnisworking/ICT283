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
   * \brief Initializes the Controller.
   */
  void Init();

  /**
   * \brief Gets the wind speed for a specific month and year.
   * \param result A Result object to store the calculated wind speed data.
   * \param month The month to search for (1-12).
   * \param year The year to search for.
   */
  void GetWindSpeed(SDResult& result, unsigned month, unsigned year) const;

  /**
   * \brief Gets the temperature for each month of a specific year.
   * \param result An array of Result objects to store the calculated temperature data for each month.
   * \param year The year to search for.
   */
  void GetTemperature(Vector<SDResult>& result, unsigned year) const;

  /**
   * \brief Gets the total solar radiation for each month of a specific year.
   * \param result An array of Result objects to store the total solar radiation data for each month.
   * \param year The year to search for.
   */
  void GetTotalSolarRadiation(Vector<float>& result, unsigned year) const;

  /**
   * \brief Gets the average wind speed, average ambient air temperature, and total solar radiation for each month of a specific year.
   * \param ws_result An array of Result objects to store the average wind speed data for each month.
   * \param t_result An array of Result objects to store the average ambient air temperature data for each month.
   * \param sr_result An array of Result objects to store the total solar radiation data for each month.
   * \param year The year to search for.
   */
  void GetAWSAATAndTST(Vector<SDResult>& ws_result, Vector<SDResult>& t_result, Vector<float>& sr_result, unsigned year) const;

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
