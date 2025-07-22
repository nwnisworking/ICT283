#include "Model.h"

Model::Model(const string& source){
  ifstream finput(source);
  string temp_str;

  // Cannot do anything if the file is not found
  if(!finput){
    throw runtime_error("Data source file not found: " + source);
  }

  while(getline(finput, temp_str)){
    CSVRecord::Load(temp_str, m_weather_records);
  }

  finput.close();
}

void Model::GetWindSpeed(SDResult& result, unsigned month, unsigned year) const{
  Vector<float> wind_speeds;
  StandardDeviation<float> sd(wind_speeds);

  for(int i = 0; i < m_weather_records.GetSize(); i++){
    WeatherRecord record = m_weather_records[i];

    if(record.GetMonth() == month && record.GetYear() == year && record.GetSpeed() != -9999){
      // Convert m/s to km/h
      wind_speeds.Insert(record.GetSpeed() * 3.6);
    }
  }

  result.average = sd.Mean();
  result.sample = sd.Sample();
  result.size = wind_speeds.GetSize();
}

void Model::GetTemperature(Vector<SDResult>& result, unsigned year) const{
  int i = 0;
  int size = m_weather_records.GetSize();

  for(unsigned month = 0; month < 12; month++){
    Vector<float> temperatures;
    StandardDeviation<float> sd(temperatures);

    for(; i < size; i++){
      WeatherRecord record = m_weather_records[i];

      // Ignore records that do not match the year
      if(record.GetYear() != year){
        continue;
      }
      // Year matches, check the month next to get the temperature
      else if(record.GetMonth() == month + 1){
        if(record.GetTemperature() != -9999){
          temperatures.Insert(record.GetTemperature());
        }
      }
      // Month does not match, break the loop
      else{
        break;
      }
    }

    result.Insert(SDResult{
      .average = sd.Mean(),
      .sample = sd.Sample(),
      .size = (unsigned) temperatures.GetSize()
    });
    // result.Insert(SDResult(sd.Mean(), sd.Sample(), temperatures.GetSize()));
  }
}

void Model::GetTotalSolarRadiation(Vector<float>& total, unsigned year) const{
  int i = 0;
  int size = m_weather_records.GetSize();

  for(unsigned month = 0; month < 12; month++){
    float sr = 0;

    for(; i < size; i++){
      WeatherRecord record = m_weather_records[i];

      // Ignore records that do not match the year
      if(record.GetYear() != year){
        continue;
      }
      else if(record.GetMonth() == month + 1){
        // Calculate total solar radiation for the month
        // As per the assignment, solar radiation is only counted if it is greater than or equal to 100 W/m2
        if(record.GetRadiation() != -9999 && record.GetRadiation() >= 100){
          sr+= ((float) record.GetRadiation() * (10.0f / 60.0f)) / 1000.0f; // Convert W/m2 to kWh/m2
        }
      }
      else{
        break;
      }
    }

    total.Insert(sr);
  }
}

void Model::GetAWSAATAndTST(Vector<SDResult>& ws_result, Vector<SDResult>& t_result, Vector<float>& sr_result, unsigned year) const{
  int i = 0;
  int size = m_weather_records.GetSize();

  for(unsigned month = 0; month < 12; month++){
    Vector<float> ws;
    Vector<float> t;
    float sr = 0;
    StandardDeviation<float> ws_sd(ws);
    StandardDeviation<float> t_sd(t);

    for(; i < size; i++){
      WeatherRecord record = m_weather_records[i];

      // Ignore records that do not match the year
      if(record.GetYear() != year){
        continue;
      }
      // Year matches, check the month next to get the wind speed and temperature
      else if(record.GetMonth() == month + 1){
        if(record.GetSpeed() != -9999){
          ws.Insert(record.GetSpeed() * 3.6); // Convert m/s to km/h
        }

        if(record.GetTemperature() != -9999){
          t.Insert(record.GetTemperature());
        }

        if(record.GetRadiation() != -9999 && record.GetRadiation() >= 100){
          sr+= ((float) record.GetRadiation() * (10.0f / 60.0f)) / 1000.0f; // Convert W/m2 to kWh/m2
        }
      }
      else{
        break;
      }
    }

    sr_result.Insert(sr);
    t_result.Insert(SDResult{
      .average = t_sd.Mean(),
      .sample = t_sd.Sample(),
      .size = (unsigned) t.GetSize()
    });

    ws_result.Insert(SDResult{
      .average = ws_sd.Mean(),
      .sample = ws_sd.Sample(),
      .size = (unsigned) ws.GetSize()
    });
  }
}
