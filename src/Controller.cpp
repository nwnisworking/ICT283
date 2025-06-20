#include "Controller.h"

Controller::Controller(View &view, Model &model) : m_view(view), m_model(model){
  m_view.SetController(this);
  m_model.SetController(this);
}

void Controller::Init(){
  m_view.Render("home");
}

void Controller::GetTemperature(Vector<SDResult>& result, unsigned year) const {
  m_model.GetTemperature(result, year);
}

void Controller::GetWindSpeed(SDResult& result, unsigned month, unsigned year) const{
  m_model.GetWindSpeed(result, month, year);
}

void Controller::GetTotalSolarRadiation(Vector<float>& result, unsigned year) const {
  m_model.GetTotalSolarRadiation(result, year);
}

void Controller::GetAWSAATAndTST(Vector<SDResult>& ws_result, Vector<SDResult>& t_result, Vector<float>& sr_result, unsigned year) const {
  m_model.GetAWSAATAndTST(ws_result, t_result, sr_result, year);
}