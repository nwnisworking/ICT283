#include "View.h"

void View::SetController(const Controller* controller){
  m_controller = controller;
}

void View::Render(const string& page) const{
  if(page == "1"){
    AvgWindSpeedAndDeviationForMonthAndYear();
  }
  else if(page == "2"){
    AvgAmbientAirTemperatureAndDeviationForYear();
  }
  else if(page == "3"){
    TotalSolarRadiationForYear();
  }
  else if(page == "4"){
    AWSAATAndTSR();
  }
  else if(page == "5"){
    return;
  }
  else if(page != "home"){
    cout << "Invalid option provided: " << page << endl << endl;
  }

  Home();
}

void View::Home() const{
  string option;
  cout << "Murdoch University Weather Station" << endl << endl;
  cout << "1. Average and Sample Deviation Wind Speed for a Specific Month and Year" << endl;
  cout << "2. Average and Sample Deviation Ambient Air Temperature for each Month of a specific Year" << endl;
  cout << "3. Total Solar Radiation in kWh/m2 for each Month of a specific Year" << endl;
  cout << "4. Average Wind Speed(SD), Average Ambient Air Temperature(SD), Total Solar Radiation" << endl;
  cout << "5. Exit" << endl;
  cout << "Please select an option: ";
  cin >> option;

  ClearBuffer();
  Render(option);
}

void View::AvgWindSpeedAndDeviationForMonthAndYear() const{
  unsigned month, year;
  SDResult result{};

  cout << endl << "Average and Sample Standard Deviation for Wind Speed" << endl;

  month = InputMonth();
  year = InputYear();

  m_controller->GetWindSpeed(result, month, year);

  cout << endl << MonthToString(month) << " " << year << ": ";

  if(result.size == 0){
    cout << "No Data";
  }
  else{
    cout << endl << "Average wind speed: " << fixed << setprecision(1) << result.average << " km/h";
    cout << endl << "Sample stdev: " << fixed << setprecision(1) << result.sample;
  }

  cout << endl;

  Continue();
}

void View::AvgAmbientAirTemperatureAndDeviationForYear() const{
  unsigned year;
  Vector<SDResult> result(12); // Array to hold results for each month

  year = InputYear();

  m_controller->GetTemperature(result, year);

  cout << endl << "Average and Sample Standard Deviation for Ambient Air Temperature for each Month of a specific Year" << endl;
  cout << endl << year;

  for(unsigned i = 0; i < 12; i++){
    cout << endl << MonthToString(i + 1) << ": ";

    // If no data for the month, print "No Data"
    if(result[i].size == 0){
      cout << "No Data";
    }
    else{
      cout << "average: " << fixed << setprecision(1) << result[i].average << " degrees C, ";
      cout << "stdev: " << fixed << setprecision(1) << result[i].sample;
    }
  }

  cout << endl;

  Continue();
}

void View::TotalSolarRadiationForYear() const{
  unsigned year;
  Vector<float> result;

  cout << endl << "Total Solar Radiation in kWh/m2 for each Month of a specific Year" << endl;
  year = InputYear();

  m_controller->GetTotalSolarRadiation(result, year);

  for(unsigned i = 0; i < 12; i++){
    cout << endl << MonthToString(i + 1) << ": ";

    if(result[i] == 0){
      cout << "No Data";
    }
    else{
      cout << fixed << setprecision(1) << result[i] << " kWh/m2";
    }
  }

  cout << endl;

  Continue();
}

void View::AWSAATAndTSR() const{
  unsigned year;
  Vector<SDResult> ws_result(12);
  Vector<SDResult> t_result(12);
  Vector<float> sr_result(12);
  ofstream out_file("data/WindTempSolar.csv");

  cout << endl << "Average Wind Speed(SD), Air Ambient Temperature(SD), and Total Solar Radiation for specific year" << endl << endl;

  year = InputYear();

  cout << endl;

  m_controller->GetAWSAATAndTST(ws_result, t_result, sr_result, year);

  out_file << year << endl;

  bool has_data = false; // Flag to check if there is any data for the year

  for(unsigned i = 0; i < 12; i++){
    // No data for this month. Ignore the data
    if(ws_result[i].size == 0 && t_result[i].size == 0 && sr_result[i] == 0){
      continue;
    }
    else{
      has_data = true;
    }

    out_file << MonthToString(i + 1) << ",";

    if(ws_result[i].size != 0){
      out_file << fixed << setprecision(1) << ws_result[i].average << "(" << fixed << setprecision(1) << ws_result[i].sample << ")";
    }

    out_file << ",";

    if(t_result[i].size != 0){
      out_file << fixed << setprecision(1) << t_result[i].average << "(" << fixed << setprecision(1) << t_result[i].sample << ")";
    }

    out_file << ",";

    if(sr_result[i] != 0){
      out_file << fixed << setprecision(1) << sr_result[i];
    }

    out_file << endl;
  }

  if(!has_data){
    out_file << "No Data" << endl;
    cout << "No data available for the specified year." << endl;
  }
  else{
    cout << "Data for " << year << " has been saved to data/WindTempSolar.csv" << endl;
  }

  out_file.close();

  Continue();
}

void View::Continue() const{
  cout << endl << "Press Enter to continue...";
  ClearBuffer();
  cout << endl;
}

void View::ClearBuffer() const{
  if(cin.fail()){
    cin.clear();
  }
  // Clear leftover characters in the input buffer
  while(cin.get() != '\n');
}

const string& View::MonthToString(unsigned month){
  if(month < 1 || month > 12){
    throw std::out_of_range("Month must be between 1 and 12");
  }

  static const string months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  };

  return months[month - 1];
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

    ClearBuffer();

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

    ClearBuffer();

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
