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
   * \brief Finds weather records for a specific month and year.
   * \param data A vector of WeatherRecord pointers to append the results to.
   * \param month The month to search for (1-12).
   * \param year The year to search for.
   */
  void FindDate(Vector<WeatherRecord*>& data, unsigned month, unsigned year) const;

  /**
   * \brief Finds weather records for a specific year.
   * \param data A vector of WeatherRecord pointers to append the results to.
   * \param year The year to search for.
   */
  void FindDate(Vector<WeatherRecord*>& data, unsigned year) const;

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
