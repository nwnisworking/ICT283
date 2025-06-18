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
    cout << endl << "Invalid option provided." << endl << endl;
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
  Vector<WeatherRecord*> data;
  Vector<float> wind_speeds;

  cout << endl << "Average and Sample Standard Deviation for Wind Speed" << endl;

  month = InputMonth();
  year = InputYear();

  // Find the weather records for the specified month and year
  m_controller->FindDate(data, month, year);

  cout << endl << MonthToString(month) << " " << year << ": ";

  if(data.GetSize() == 0){
    cout << "No Data" << endl << endl;
  }
  else{
    for(int i = 0; i < data.GetSize(); i++){
      WeatherRecord* record = data[i];

      if(record->GetSpeed() != -9999){
        wind_speeds.Insert(record->GetSpeed() * 3.6); // Convert m/s to km/h
      }
    }

    StandardDeviation<float> deviation(wind_speeds);

    cout << endl << endl;
    cout << "Average Wind Speed: " << deviation.Mean() << " km/h" << endl;
    cout << "Sample stdev: " << deviation.Sample() << endl;
  }

  Continue();
}

void View::AvgAmbientAirTemperatureAndDeviationForYear() const{
  unsigned year;
  Vector<WeatherRecord*> data;

  cout << endl << "Average and Sample Standard Deviation for Ambient Air Temperature for specific year" << endl;

  year = InputYear();

  // Find the weather records for the specified year
  m_controller->FindDate(data, year);

  cout << endl << "Year "<< year << endl;

  // Guard clause to prevent code from executing any further
  if(data.GetSize() == 0){
    cout << ": " << "No Data" << endl << endl;

    Continue();
    return;
  }

  unsigned j = 0;

  for(unsigned i = 0; i < 12; i++){
    Vector<float> temperatures;

    // Loops through the weather records for the specified month
    for(unsigned size = data.GetSize(); j < size; j++){
      WeatherRecord* record = data[j];

      // Months must match along with the temperature not being a sentinel value
      if(record->GetMonth() == i + 1){
        if(record->GetTemperature() != -9999){
          temperatures.Insert(record->GetTemperature());
        }
      }
      else{
        break;
      }
    }

    cout << MonthToString(i + 1) << ": ";

    // No temperature recorded for the month
    if(temperatures.GetSize() == 0){
      cout << "No Data" << endl;
    }
    else{
      StandardDeviation<float> sd(temperatures);
      printf("average: %.1f degrees C, stdev: %.1f\n", sd.Mean(), sd.Sample());
    }
  }

  Continue();
}

void View::TotalSolarRadiationForYear() const{
  unsigned year;
  Vector<WeatherRecord*> data;

  cout << "Total Solar Radiation in kWh/m2 for each Month of a specific Year" << endl;

  year = InputYear();

  // Find the weather records for the specified year
  m_controller->FindDate(data, year);

  cout << endl << "Year "<< year << endl;

  if(data.GetSize() == 0){
    cout << ": " << "No Data" << endl << endl;

    Continue();
    return;
  }

  unsigned j = 0;

  for(unsigned i = 0; i < 12; i++){
    float total_sr = 0;

    for(unsigned size = data.GetSize(); j < size; j++){
      WeatherRecord* record = data[j];

      if(record->GetMonth() == i + 1){
        // Calculate total solar radiation for the month
        // As per the assignment, solar radiation is only counted if it is greater than or equal to 100 W/m2
        if(record->GetRadiation() != -9999 && record->GetRadiation() >= 100){
          // Convert W/m2 to kWh/m2 for the month
          total_sr+= (record->GetRadiation() * (10.0f / 60.0f)) / 1000.0f;
        }
      }
      else{
        // Escape the loop since the month has been processed
        break;
      }
    }

    cout << MonthToString(i + 1) << ": ";

    if(total_sr == 0){
      cout << "No Data" << endl;
    }
    else{
      printf("%.1f kWh/m2\n", total_sr);
    }
  }

  Continue();
}

void View::AWSAATAndTSR() const{
  unsigned year;
  Vector<WeatherRecord*> data;

  cout << "Average Wind Speed(SD), Air Ambient Temperature(SD), and Total Solar Radiation for specific year" << endl;

  year = InputYear();

  m_controller->FindDate(data, year);

  unsigned j = 0;

  cout << endl << "Year "<< year << endl;

  if(data.GetSize() == 0){
    cout << ": " << "No Data" << endl << endl;

    Continue();
    return;
  }

  for(unsigned i = 0; i < 12; i++){
    float total_sr = 0;
    Vector<float> temperature;
    Vector<float> wind_speed;

    for(unsigned size = data.GetSize(); j < size; j++){
      WeatherRecord* record = data[j];

      if(record->GetMonth() == i + 1){
        // Calculate total solar radiation for the month
        // As per the assignment, solar radiation is only counted if it is greater than or equal to 100 W/m2
        if(record->GetRadiation() != -9999 && record->GetRadiation() >= 100){
          total_sr+= (record->GetRadiation() * (10.0f / 60.0f)) / 1000.0f;
        }

        if(record->GetTemperature() != -9999){
          temperature.Insert(record->GetTemperature());
        }

        if(record->GetSpeed() != -9999){
          wind_speed.Insert(record->GetSpeed() * 3.6);
        }
      }
      else{
        // Escape the loop since the month has been processed
        break;
      }
    }

    cout << MonthToString(i + 1) << ",";

    if(total_sr == 0){
      cout << "No Data" << endl;
    }
    else{

      if(wind_speed.GetSize() > 0){
        StandardDeviation<float> ws_sd(wind_speed);
        printf("%.1f(%.1f),", ws_sd.Mean(), ws_sd.Sample());
      }
      else{
        cout << ",";
      }

      if(temperature.GetSize() > 0){
        StandardDeviation<float> t_sd(temperature);
        printf("%.1f(%.1f),", t_sd.Mean(), t_sd.Sample());
      }
      else{
        cout << ",";
      }

      if(total_sr == 0){
        cout << "" << endl;
      }
      else{
        printf("%.1f\n", total_sr);
      }
    }
  }

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
  unsigned month;

  do{
    cout << "Please enter the month (1-12): ";
    cin >> month;

    ClearBuffer();
  }
  while(month < 1 || month > 12);

  return month;
}

unsigned View::InputYear() const{
  unsigned year;

  do{
    cout << "Please enter the year: ";
    cin >> year;

    ClearBuffer();
  }
  while(year < 0);

  return year;
}
