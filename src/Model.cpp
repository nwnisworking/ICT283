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
        }
        else if(count == sr_index){
          Trim(value);

          if(value == "N/A" || value.empty() || value == "NaN" || value == "offline"){
            value = "-9999"; // Treat N/A, NaN, and offline as 0
          }

          record.SetRadiation(stoi(value));
        }
        else if(count == t_index){
          Trim(value);

          if(value == "N/A" || value.empty() || value == "NaN" || value == "offline"){
            value = "-9999"; // Treat N/A, NaN, and offline as 0
          }

          record.SetTemperature(stof(value));
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

void Model::FindDate(Vector<WeatherRecord*>& data, unsigned month, unsigned year){
  for(int i = 0; i < weather_records.GetSize(); i++){
    WeatherRecord& record = weather_records[i];

    if(record.GetMonth() == month && record.GetYear() == year){
      data.Insert(&record);
    }
  }
}

void Model::FindDate(Vector<WeatherRecord*>& data, unsigned year){
  for(int i = 0; i < weather_records.GetSize(); i++){
    WeatherRecord& record = weather_records[i];

    if(record.GetYear() == year){
      data.Insert(&record);
    }
  }
}
