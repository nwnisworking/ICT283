#include "Model.h"

Model::Model(const string& source){
  ifstream finput(source);
  string temp_str;
  Vector<string> headers;

  // Cannot do anything if the file is not found
  if(!finput){
    throw runtime_error("Data source file not found: " + source);
  }

  // We assume the source only contain a row
  getline(finput, temp_str);

  finput.close();
  finput.open("data/" + temp_str);

  if(!finput){
    throw runtime_error("Data file not found: data/" + temp_str);
  }

  // Process the first line as the header
  getline(finput, temp_str);
  AnalyzeHeader(headers, temp_str);

  // Check if the required headers are present
  int ws_index = FindAlias(headers, WIND_SPEED_ALIAS);
  int sr_index = FindAlias(headers, SOLAR_RADIATION_ALIAS);
  int t_index = FindAlias(headers, TEMPERATURE_ALIAS);

  // If any of the required headers are not found, throw an error
  // Either the header is not present or the alias is not found
  if(ws_index == -1 || sr_index == -1 || t_index == -1){
    throw runtime_error("Required headers not found in the data file.");
  }

  while(getline(finput, temp_str)){
    if(temp_str.empty()) continue;

    int row_size = temp_str.size();
    int count = 0;
    WeatherRecord record;

    for(int i = 0, start = 0; i <= row_size; i++){
      if(temp_str[i] == ',' || i == row_size){
        string value = temp_str.substr(start, i - start);
        start = i + 1;

        if(count == 0){
          Trim(value);
          int pos = 0, npos = 0;

          npos = value.find('/', pos);
          record.SetDayOfMonth(stoi(value.substr(pos, npos - pos)));
          pos = npos + 1;

          npos = value.find('/', pos);
          record.SetMonth(stoi(value.substr(pos, npos - pos)));
          pos = npos + 1;

          npos = value.find(' ', pos);
          record.SetYear(stoi(value.substr(pos, npos - pos)));
          pos = npos + 1;

          npos = value.find(':', pos);
          record.SetHours(stoi(value.substr(pos, npos - pos)));
          pos = npos + 1;

          record.SetMinutes(stoi(value.substr(pos)));
        }
        else if(count == ws_index){
          Trim(value);

          if(value == "N/A" || value.empty() || value == "NaN" || value == "offline"){
            value = "-9999"; // Treat N/A, NaN, and offline as 0
          }

          record.SetSpeed(stoi(value));

          // The wind speed cannot be negative
          if(record.GetSpeed() < 0){
            record.SetSpeed(-9999);
          }
        }
        else if(count == sr_index){
          Trim(value);

          if(value == "N/A" || value.empty() || value == "NaN" || value == "offline"){
            value = "-9999"; // Treat N/A, NaN, and offline as 0
          }

          record.SetRadiation(stoi(value));

          // The radiation cannot be negative or greater than 1500
          // 1500 is the maximum value for solar radiation in W/m2 with the highest value around 1361 W/m2
          if(record.GetRadiation() < 0 || record.GetRadiation() > 1500){
            record.SetRadiation(-9999);
          }
        }
        else if(count == t_index){
          Trim(value);

          if(value == "N/A" || value.empty() || value == "NaN" || value == "offline"){
            value = "-9999"; // Treat N/A, NaN, and offline as 0
          }

          record.SetTemperature(stof(value));

          // The temperature cannot be less than -100 or greater than 100
          // -100 is the minimum value for temperature in degrees Celsius. The minimum temperature on Earth is around -89.2 °C
          // 100 is the maximum value for temperature in degrees Celsius. The maximum temperature on Earth is around 56.7 °C
          if(record.GetTemperature() < -100 || record.GetTemperature() > 100){
            record.SetTemperature(-9999.0f); // Treat out of range values as -9999
          }
        }

        count++;
      }
    }

    weather_records.Insert(record);
  }

  finput.close();

}

void Model::SetController(const Controller* controller){
  m_controller = controller;
}

void Model::AnalyzeHeader(Vector<string> &headers, const string& line){
  for(int i = 0, size = line.size(), start = 0; i <= size; ++i){
    if(line[i] == ',' || i == size){
      string header = line.substr(start, i - start);
      start = i + 1;

      Trim(header);
      headers.Insert(header);
    }
  }
}

int Model::FindAlias(const Vector<string>& headers, const string* alias){
  for(int i = 0; i < headers.GetSize(); i++){
    for(int j = 0; alias[j] != ""; j++){
      if(headers[i] == alias[j]){
        return i;
      }
    }
  }

  return -1;
}

void Model::Trim(string& str){
  int size = str.size();
  int start = 0;
  int end = size - 1;

  while(start< size && str[start] == ' '){
    start++;
  }

  while(end > start && str[end] == ' '){
    end--;
  }

  if(start > end){
    str = "";
  }
  else{
    str = str.substr(start, end - start + 1);
  }
}

void Model::GetWindSpeed(SDResult& result, unsigned month, unsigned year) const{
  Vector<float> wind_speeds;
  StandardDeviation<float> sd(wind_speeds);

  for(int i = 0; i < weather_records.GetSize(); i++){
    WeatherRecord record = weather_records[i];

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
  int size = weather_records.GetSize();

  for(unsigned month = 0; month < 12; month++){
    Vector<float> temperatures;
    StandardDeviation<float> sd(temperatures);
    SDResult sd_result;

    for(; i < size; i++){
      WeatherRecord record = weather_records[i];

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

    sd_result.average = sd.Mean();
    sd_result.sample = sd.Sample();
    sd_result.size = temperatures.GetSize();

    result.Insert(sd_result);
  }
}

void Model::GetTotalSolarRadiation(Vector<float>& total, unsigned year) const{
  int i = 0;
  int size = weather_records.GetSize();

  for(unsigned month = 0; month < 12; month++){
    float sr = 0;

    for(; i < size; i++){
      WeatherRecord record = weather_records[i];

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
  int size = weather_records.GetSize();

  for(unsigned month = 0; month < 12; month++){
    Vector<float> ws;
    Vector<float> t;
    float sr = 0;
    StandardDeviation<float> ws_sd(ws);
    StandardDeviation<float> t_sd(t);

    for(; i < size; i++){
      WeatherRecord record = weather_records[i];

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

    SDResult t_sd_result;
    SDResult ws_sd_result;
    
    t_sd_result.average = t_sd.Mean();
    t_sd_result.sample = t_sd.Sample();
    t_sd_result.size = t.GetSize();
    
    ws_sd_result.average = ws_sd.Mean();
    ws_sd_result.sample = ws_sd.Sample();
    ws_sd_result.size = ws.GetSize();
    
    sr_result.Insert(sr);
    t_result.Insert(t_sd_result);
    ws_result.Insert(ws_sd_result);
  }
}
