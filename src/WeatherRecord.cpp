#include "WeatherRecord.h"

WeatherRecord::WeatherRecord(){
  m_speed = 0.0;
  m_radiation = 0.0;
  m_temperature = 0.0;
}

void WeatherRecord::SetSpeed(int speed) {
  m_speed = speed;
}

void WeatherRecord::SetRadiation(int radiation) {
  m_radiation = radiation;
}

void WeatherRecord::SetTemperature(float temperature) {
  m_temperature = temperature;
}

void WeatherRecord::SetDayOfMonth(unsigned day_of_month) {
  m_date.SetDayOfMonth(day_of_month);
}

void WeatherRecord::SetMonth(unsigned month) {
  m_date.SetMonth(month);
}

void WeatherRecord::SetYear(unsigned year) {
  m_date.SetYear(year);
}

void WeatherRecord::SetHours(unsigned hours) {
  m_time.SetHours(hours);
}

void WeatherRecord::SetMinutes(unsigned minutes) {
  m_time.SetMinutes(minutes);
}

int WeatherRecord::GetSpeed() const {
  return m_speed;
}

int WeatherRecord::GetRadiation() const {
  return m_radiation;
}

float WeatherRecord::GetTemperature() const {
  return m_temperature;
}

unsigned WeatherRecord::GetDayOfMonth() const {
  return m_date.GetDayOfMonth();
}

unsigned WeatherRecord::GetMonth() const {
  return m_date.GetMonth();
}

unsigned WeatherRecord::GetYear() const {
  return m_date.GetYear();
}

unsigned WeatherRecord::GetHours() const {
  return m_time.GetHours();
}

unsigned WeatherRecord::GetMinutes() const {
  return m_time.GetMinutes();
}
