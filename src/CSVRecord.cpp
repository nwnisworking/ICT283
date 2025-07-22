#include "CSVRecord.h"

void CSVRecord::Load(const string& path, Vector<WeatherRecord>& records){
  ifstream finput("data/" + path);
  stringstream ss;
  WeatherRecord record;
  string temp_str;
  Vector<string> headers;

  if(!finput){
    throw runtime_error("Data file not found: data/" + path);
  }

  getline(finput, temp_str);

  if(temp_str.empty()){
    throw runtime_error("Unable to process header");
  }

  ExtractData(headers, temp_str);

  int ws_index = FindAlias(headers, WIND_SPEED_ALIAS);
  int sr_index = FindAlias(headers, SOLAR_RADIATION_ALIAS);
  int t_index = FindAlias(headers, TEMPERATURE_ALIAS);

  if(ws_index == -1 || sr_index == -1 || t_index == -1){
    throw runtime_error("Required header not found");
  }

  while(getline(finput, temp_str)){
    if(temp_str.empty()) continue;

    Vector<string> data;

    ExtractData(data, temp_str);

    string wast = data[0];
    string ws = data[ws_index];
    string sr = data[sr_index];
    string temp = data[t_index];

    if(!wast.empty()){
      ss.clear();
      ss.str(wast);

      getline(ss, temp_str, '/');
      record.SetDayOfMonth(stoi(temp_str));
      
      getline(ss, temp_str, '/');
      record.SetMonth(stoi(temp_str));
      
      getline(ss, temp_str, ' ');
      record.SetYear(stoi(temp_str));
      
      getline(ss, temp_str, ':');
      record.SetHours(stoi(temp_str));

      getline(ss, temp_str);
      record.SetMinutes(stoi(temp_str));
    }

    if(ws.empty() || ws == "N/A" || ws == "NaN" || ws == "offline"){
      record.SetSpeed(-9999);
    }
    else{
      try{
        record.SetSpeed(stoi(ws));

        if(record.GetSpeed() < 0){
          record.SetSpeed(-9999);
        }
      }
      catch(const invalid_argument& e){
        record.SetSpeed(-9999);
      }
    }

    if(sr.empty() || sr == "N/A" || sr == "NaN" || sr == "offline"){
      record.SetRadiation(-9999);
    }
    else{
      try{
        record.SetRadiation(stoi(sr));

        // Note: Highest radiation value on Earth is around 1361 W/m2
        // 1500 is used as a threshold to filter out unrealistic values
        if(record.GetRadiation() < 0 || record.GetRadiation() > 1500){
          record.SetRadiation(-9999);
        }
      }
      catch(const invalid_argument& e){
        record.SetRadiation(-9999);
      }
    }

    if(temp.empty() || temp == "N/A" || temp == "NaN" || temp == "offline"){
      record.SetTemperature(-9999.0f);
    }
    else{
      try{
        record.SetTemperature(stof(temp));

        // The temperature cannot be less than -100 or greater than 100
        // -100 is the minimum value for temperature in degrees Celsius. The minimum temperature on Earth is around -89.2 C
        // 100 is the maximum value for temperature in degrees Celsius. The maximum temperature on Earth is around 56.7 C
        if(record.GetTemperature() < -100 || record.GetTemperature() > 100){
          record.SetTemperature(-9999.0f); // Treat out of range values as -9999
        }
      }
      catch(const invalid_argument& e){
        record.SetTemperature(-9999);
      }
    }
  
    records.Insert(record);
  }

  finput.close();
}

void CSVRecord::Trim(string& str){
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

void CSVRecord::ExtractData(Vector<string>& data, const string& line){
  for(int i = 0, size = line.size(), start = 0; i <= size; i++){
    if(line[i] == ',' || i == size){
      string value = line.substr(start, i - start);
      start = i + 1;

      Trim(value);
      data.Insert(value);
    }
  }
}

int CSVRecord::FindAlias(const Vector<string>& headers, const string* alias){
  for(int i = 0; i < headers.GetSize(); i++){
    for(int j = 0; alias[j] != ""; j++){
      if(headers[i] == alias[j]){
        return i;
      }
    }
  }

  return -1;
}