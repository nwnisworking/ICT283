#ifndef STANDARDDEVIATION_H
#define STANDARDDEVIATION_H
#include <cmath>

#include "Vector.h"

template <class T>
class StandardDeviation{
  public:
  StandardDeviation(const Vector<T>& data){
    m_size = data.GetSize();
    m_data = data;
  }

  T Sample();

  T Population();

  T Mean();

  private:
  Vector<T> m_data;
  unsigned m_size;
};

template <class T>
T StandardDeviation<T>::Sample(){
  T sum = 0;
  T mean = Mean();

  for(unsigned i = 0; i < m_size; i++){
    sum+= pow(m_data[i] - mean, 2);
  }

  return sqrt(sum / (m_size - 1));
}

template <class T>
T StandardDeviation<T>::Population(){
  T sum = 0;
  T mean = Mean();

  for(unsigned i = 0; i < m_size; i++){
    sum+= pow(m_data[i] - mean, 2);
  }

  return sqrt(sum / m_size);
}

template <class T>
T StandardDeviation<T>::Mean(){
  T total = 0;

  for(unsigned i = 0; i < m_size; i++){
    total+= m_data[i];
  }

  return total / m_size;
}

#endif
