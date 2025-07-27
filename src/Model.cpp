#include "Model.h"

Model::Model(const string& source){
  ifstream finput(source);
  string temp_str;

  // Cannot do anything if the file is not found
  if(!finput){
    throw runtime_error("Data source file not found: " + source);
  }
  m_earliest_year = 0;
  m_latest_year = 0;

  while(getline(finput, temp_str)){
    CSVRecord::Load(temp_str, m_weather_records, m_earliest_year, m_latest_year);
  }

  finput.close();
}

int Model::GetFirstKey(){
  return m_earliest_year;
}

int Model::GetLastKey(){
  return m_latest_year;
}

const AVL<WeatherRecord>* Model::Get(const Date& date) const{
  return m_weather_records.Get(((date.GetYear() - 1970) * 372 + date.GetMonth() * 31));
}
