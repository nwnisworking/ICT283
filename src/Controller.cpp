#include "Controller.h"

Controller::Controller(View &view, Model &model) : m_view(view), m_model(model){
  m_view.SetController(this);
}

void Controller::Init() const{
  m_view.Render();
}

void Controller::GetWindSpeed(const Date& date, Vector<float>& result) const{
  const AVL<WeatherRecord>* tree = m_model.Get(date);

  if(tree == nullptr || tree->IsEmpty()){
    return;
  }

  Vector<WeatherRecord> data = tree->InOrder([](const WeatherRecord& record){
    return record.GetSpeed() != -9999;
  });

  for(int i = 0; i < data.GetSize(); i++){
    result.Insert(data[i].GetSpeed() * 3.6);
  }
}

void Controller::GetTemperature(const Date& date, Vector<float>& result) const{
  const AVL<WeatherRecord>* tree = m_model.Get(date);

  if(tree == nullptr || tree->IsEmpty()){
    return;
  }

  Vector<WeatherRecord> data = tree->InOrder([](const WeatherRecord& record){
    return record.GetTemperature() != -9999;
  });

  for(int i = 0; i < data.GetSize(); i++){
    result.Insert(data[i].GetTemperature());
  }
}

void Controller::GetSPCC(Date date, Vector<float>& wind_speeds, Vector<float>& temperatures, Vector<float>& solar_radiations) const{
  int i = m_model.GetFirstKey() / 372 + 1970;
  int size = m_model.GetLastKey() / 372 + 1970;

  const AVL<WeatherRecord>* tree = nullptr;

  for(; i <= size; i++){
    date.SetYear(i);

    tree = m_model.Get(date);

    if(tree == nullptr || tree->IsEmpty()){
      continue;
    }

    Vector<WeatherRecord> data = tree->InOrder(CollectValidData);

    for(int i = 0; i < data.GetSize(); i++){
      wind_speeds.Insert(data[i].GetSpeed() * 3.6);
      temperatures.Insert(data[i].GetTemperature());
      solar_radiations.Insert(data[i].GetRadiation());
    }
  }
}

void Controller::GetDataForYear(Date date, Map<Date, Vector<float>>& wind_speed_map, Map<Date, Vector<float>>& temperature_map, Map<Date, Vector<float>>& solar_radiation_map) const{
  Vector<float> wind_speeds;
  Vector<float> temperatures;
  Vector<float> solar_radiations;

  // Loop through each month of the year
  for(int i = 0; i < 12; i++){
    date.SetMonth(i + 1);

    const AVL<WeatherRecord>* tree = m_model.Get(date);

    if(tree == nullptr || tree->IsEmpty()){
      continue;
    }

    Vector<WeatherRecord> data = tree->InOrder(CollectValidData);

    for(int i = 0; i < data.GetSize(); i++){
      wind_speeds.Insert(data[i].GetSpeed() * 3.6);
      temperatures.Insert(data[i].GetTemperature());

      if(data[i].GetRadiation() >= 100){
        solar_radiations.Insert((data[i].GetRadiation() * (10.0f / 60.0f)) / 1000.0f);
      }
    }

    wind_speed_map.Insert(date, wind_speeds);
    temperature_map.Insert(date, temperatures);
    solar_radiation_map.Insert(date, solar_radiations);

    wind_speeds.Clear();
    temperatures.Clear();
    solar_radiations.Clear();
  }
}

bool Controller::CollectValidData(const WeatherRecord& record){
  return record.GetSpeed() != -9999 &&
         record.GetTemperature() != -9999 &&
         record.GetRadiation() != -9999;
}