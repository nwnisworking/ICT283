#include "Controller.h"

Controller::Controller(View &view, Model &model) : m_view(view), m_model(model){
  m_view.SetController(this);
  m_model.SetController(this);
}

void Controller::Init(){
  m_view.Render("home");
}

void Controller::FindDate(Vector<WeatherRecord*>& data, unsigned month, unsigned year) const{
  m_model.FindDate(data, month, year);
}

void Controller::FindDate(Vector<WeatherRecord*>& data, unsigned year) const{
  m_model.FindDate(data, year);
}