#include "Date.h"
#include "Vector.h"
#include "Time.h"
#include "StandardDeviation.h"
#include "WindrecType.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stof;
using std::stringstream;

typedef Vector<WindRecType> WindLogType;

const string RAW_FILE_INPUT = "data/MetData_Mar01-2014-2015-All.csv";
//const string RAW_FILE_INPUT = "data/MetData-31-3.csv";
const string WIND_SPEED_FILE = "data/wind_data.csv";

int findColumn(const Vector<string> &header, const string &text);
void extractWindSpeed();

int main(){
  extractWindSpeed();

  ifstream finput(WIND_SPEED_FILE);
  WindLogType log;
  Vector<float> wind_speed;
  // Multiply this to get km/h since the wind speed is calculated
  // by m/s
  float km_per_h = (float) 3600 / (float) 1000;

  while(finput.peek() != EOF){
    WindRecType rec;

    finput >> rec;

    log.Insert(rec);
    wind_speed.Insert(rec.GetSpeed() * km_per_h);
  }

  StandardDeviation<float> wind_speed_sd(wind_speed);
  float mean = wind_speed_sd.Mean();

  cout << "Average(km/h):                   " << mean << endl;
  cout << "Standard Deviation Sample(km/h): " << wind_speed_sd.Sample() << endl;
  cout << "Date that matches the average" << endl;
  for(int i = 0; i < log.GetSize(); i++){
    float log_speed = log[i].GetSpeed() * km_per_h;

    if(log_speed == mean){
      Date date;
      Time time;
      log[i].GetDate(date);
      log[i].GetTime(time);

      cout << date << time << endl;
    }
  }

  finput.close();
  return 0;
}

void extractWindSpeed(){
  ifstream finput(RAW_FILE_INPUT);
  ofstream foutput(WIND_SPEED_FILE);
  Vector<string> header;
  string temp_str;
  stringstream ss;
  WindLogType log;
  WindRecType rec;

  // Get CSV heading
  getline(finput, temp_str);
  ss.str(temp_str);

  while(getline(ss, temp_str, ',')){
    header.Insert(temp_str);
  }

  // Column needed to process the data
  const int WAST = findColumn(header, "WAST");
  const int S = findColumn(header, "S");

  // Get each rows
  while(getline(finput, temp_str)){
    int col_index = 0;
    bool valid = true;

    ss.clear();
    ss.str(temp_str);

    while(getline(ss, temp_str, ',')){
      if(col_index == WAST){
        stringstream ss_wast(temp_str);

        getline(ss_wast, temp_str, '/');
        rec.SetDayOfMonth(stoi(temp_str));

        getline(ss_wast, temp_str, '/');
        rec.SetMonth(stoi(temp_str));

        getline(ss_wast, temp_str, ' ');
        rec.SetYear(stoi(temp_str));

        getline(ss_wast, temp_str, ':');
        rec.SetHours(stoi(temp_str));

        getline(ss_wast, temp_str);
        rec.SetMinutes(stoi(temp_str));
      }
      // This row is invalid and should not be recorded since it might mess up the average
      else if(col_index == S && temp_str == "N/A"){
        valid = false;
        break;
      }
      else if(col_index == S && temp_str != "N/A"){
        rec.SetSpeed(stof(temp_str));
      }

      col_index++;
    }

    // Log the record if it is valid (i.e. speed is not N/A)
    if(valid){
      log.Insert(rec);
      rec = {};
    }
  }

  finput.close();

  for(int i = 0, size = log.GetSize(); i < size; i++){
    foutput << log[i] << '\n';
  }

  foutput.close();
}

int findColumn(const Vector<string> &header, const string &text){
  for(int i = 0; i < header.GetSize(); i++)
    if(header[i] == text) return i;

  return -1;
}
