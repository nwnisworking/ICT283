#include "View.h"

void View::SetController(const Controller* controller){
  m_controller = controller;
}

void View::Render() const{
  string option;

  while(option != "5"){
    cout << "Murdoch University Weather Station" << endl << endl;
    cout << "1. Average and Sample Deviation Wind Speed for a Specific Month and Year" << endl;
    cout << "2. Average and Sample Deviation Ambient Air Temperature for each Month of a specific Year" << endl;
    cout << "3. Get Sample Pearson Correlation Coefficient" << endl;
    cout << "4. Average Wind Speed(SD), Average Ambient Air Temperature(SD), Total Solar Radiation" << endl;
    cout << "5. Exit" << endl;
    cout << "Please select an option: ";
    cin >> option;

    Utils::ClearBuffer();

    if(option == "1"){
      WindSpeedPage();
    }
    else if(option == "2"){
      AirTemperaturePage();
    }
    else if(option == "3"){
        SPCCPage();
    }
    else if(option == "4"){
        SaveDataForYear();
    }
    else if(option == "5"){
      return;
    }
    else{
      cout << "Invalid option provided: " << option << endl << endl;
    }
  }
}

void View::WindSpeedPage() const{
  Date date;
  Vector<float> result(12);

  cout << endl << "Average and Sample Standard Deviation for Wind Speed" << endl;

  date.SetMonth(InputMonth());
  date.SetYear(InputYear());

  m_controller->GetWindSpeed(date, result);

  cout << endl << Date::MonthToString(date.GetMonth()) << ' ' << date.GetYear() << ": ";

  if(result.GetSize() == 0){
    cout << "No data" << endl;
  }
  else{
    cout << endl;
    cout << "Average speed: " << fixed << setprecision(1) << Utils::Mean(result) << " km/h" << endl;
    cout << "Sample stdev: " << fixed << setprecision(1) << Utils::Sample(result) << endl;
  }

  Utils::Continue();
}

void View::AirTemperaturePage() const{
  Date date;
  Vector<float> result;

  date.SetYear(InputYear());

  cout << endl << "Average and Sample Standard Deviation for Ambient Air Temperature for each Month of a specific Year" << endl;
  cout << endl << date.GetYear() << endl;

  for(int i = 0; i < 12; i++){
    date.SetMonth(i + 1);
    m_controller->GetTemperature(date, result);

    cout << Date::MonthToString(i + 1) << ": ";

    if(result.GetSize() == 0){
      cout << " No data" << endl;
    }
    else{
      cout << "average: " << fixed << setprecision(1) << Utils::Mean(result) << " degrees C, ";
      cout << "stdev: " << fixed << setprecision(1) << Utils::Sample(result) << endl;
    }

    result.Clear();
  }

  Utils::Continue();
}

void View::SPCCPage() const{
  Vector<float> wind_speeds;
  Vector<float> temperatures;
  Vector<float> solar_radiations;
  Date date;

  date.SetMonth(InputMonth());
  m_controller->GetSPCC(date, wind_speeds, temperatures, solar_radiations);

  cout << endl << "Sample Pearson Correlation Coefficient for " << Date::MonthToString(date.GetMonth()) << endl;

  // The last character denotes l for left and r for right
  Vector<float> S_T_L, S_T_R;
  Vector<float> S_R_L, S_R_R;
  Vector<float> T_R_L, T_R_R;
  int result_size = wind_speeds.GetSize();

  if(temperatures.GetSize() != result_size || solar_radiations.GetSize() != result_size){
    cout << "Data size mismatch. Cannot calculate SPCC." << endl;
    Utils::Continue();
    return;
  }

  for(int i = 0; i < result_size; i++){
    if(solar_radiations[i] >= 100){
      S_R_L.Insert(wind_speeds[i]);
      S_R_R.Insert(solar_radiations[i]);
      T_R_L.Insert(temperatures[i]);
      T_R_R.Insert(solar_radiations[i]);
    }

    S_T_L.Insert(wind_speeds[i]);
    S_T_R.Insert(temperatures[i]);
  }

  cout << "Wind Speed and Radiation: " << Utils::PearsonCorrelation(S_R_L, S_R_R) << endl;
  cout << "Wind Speed and Temperature: " << Utils::PearsonCorrelation(S_T_L, S_T_R) << endl;
  cout << "Temperature and Radiation: " << Utils::PearsonCorrelation(T_R_L, T_R_R) << endl;

  Utils::Continue();
}

void View::SaveDataForYear() const{
  Date date;
  Map<Date, Vector<float>> wind_speed_map;
  Map<Date, Vector<float>> temperature_map;
  Map<Date, Vector<float>> solar_radiation_map;
  ofstream out_file("data/WindTempSolar.csv");
  int fail_count = 0;

  date.SetYear(InputYear());

  cout << endl << "Saving data for year: " << date.GetYear() << endl;
  m_controller->GetDataForYear(date, wind_speed_map, temperature_map, solar_radiation_map);

  out_file << date.GetYear() << endl;

  for(int i = 0; i < 12; i++){
      date.SetMonth(i+1);
    if(!wind_speed_map.Search(date) || !temperature_map.Search(date) || !solar_radiation_map.Search(date)){
      fail_count++;
      continue;
    }

    Vector<float> wind_speeds = *wind_speed_map.Get(date);
    Vector<float> temperatures = *temperature_map.Get(date);
    Vector<float> solar_radiations = *solar_radiation_map.Get(date);

    if(wind_speeds.GetSize() == 0 || temperatures.GetSize() == 0 || solar_radiations.GetSize() == 0){
      fail_count++;
      continue;
    }

    out_file << Date::MonthToString(i + 1) << ", ";
    out_file << fixed << setprecision(1) << Utils::Mean(wind_speeds) << '(';
    out_file << fixed << setprecision(1) << Utils::Sample(wind_speeds) << ", ";
    out_file << fixed << setprecision(1) << Utils::MeanAbsoluteDeviation(wind_speeds) << "), ";

    out_file << fixed << setprecision(1) << Utils::Mean(temperatures) << '(';
    out_file << fixed << setprecision(1) << Utils::Sample(temperatures) << ", ";
    out_file << fixed << setprecision(1) << Utils::MeanAbsoluteDeviation(temperatures) << "), ";

    out_file << fixed << setprecision(1) << Utils::Sum(solar_radiations) << endl;
  }

  if(fail_count == 12){
    out_file << "No Data" << endl;
  }

  out_file.close();

  Utils::Continue();
}

unsigned View::InputMonth() const{
  string temp_str;
  bool is_valid = true;
  unsigned month;
  do{
    is_valid = true;
    cout << "Please enter the month (1-12): ";
    cin >> temp_str;

    for(int i = 0, size = temp_str.length(); i < size; i++){
      if(!isdigit(temp_str[i])){
        is_valid = false;
        break;
      }
    }

    Utils::ClearBuffer();

    if(is_valid){
      // Catch out of range exception in case it breaks the range of unsigned int
      try{
        month = stoi(temp_str);

        if(month < 1 || month > 12){
          is_valid = false;
          cout << "Invalid month. Please enter a number between 1 and 12." << endl << endl;
        }
      }
      catch(const out_of_range& e){
        is_valid = false;
        cout << "Invalid month. Please enter a number between 1 and 12." << endl << endl;
      }
    }
    else{
      cout << "Invalid input. Please enter a valid month." << endl << endl;
    }
  }
  while(!is_valid);

  return month;
}

unsigned View::InputYear() const{
  string temp_str;
  bool is_valid = true;
  unsigned year;

  do{
    is_valid = true;

    cout << "Please enter the year: ";
    cin >> temp_str;

    for(int i = 0, size = temp_str.length(); i < size; i++){
      if(!isdigit(temp_str[i])){
        is_valid = false;
        break;
      }
    }

    Utils::ClearBuffer();

    if(is_valid){
      // Catch for out of range exception in case it breaks the range of unsigned int
      try{
        year = stoi(temp_str);

        if(year < 1 || year > 9999){
          is_valid = false;
          cout << "Invalid year. Year must be between 1 and 9999." << endl << endl;
        }
      }
      catch(const out_of_range& e){
        is_valid = false;
        cout << "Invalid year. Year must be between 1 and 9999." << endl << endl;
      }
    }
    else{
      cout << "Invalid input. Please enter a valid year." << endl << endl;
    }
  }
  while(!is_valid);

  return year;
}
