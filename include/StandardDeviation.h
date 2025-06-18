#ifndef STANDARDDEVIATION_H
#define STANDARDDEVIATION_H
#include <cmath>

#include "Vector.h"

/**
 * \brief StandardDeviation class to calculate the standard deviation of a dataset.
 * \param T Type of the data in the dataset (e.g., int, float, double)
 * \details This class provides methods to calculate both sample and population standard deviations.
 * \see https://www.calculator.net/standard-deviation-calculator.html to perform calculations and see if the result matches the method's output.
 */
template <class T>
class StandardDeviation{
  public:
  /**
   * \brief Default constructor for the StandardDeviation object
   * \param data Vector containing the numbers to calculate the standard deviation from
   */
  StandardDeviation(const Vector<T>& data);

  /**
   * \brief Calculate the sample standard deviation
   * \return Sample standard deviation of the data
   */
  T Sample();

  /**
   * \brief Calculate the population standard deviation
   * \return Population standard deviation of the data
   */
  T Population();

  /**
   * \brief Calculate the mean of the data
   * \return Mean of the data
   */
  T Mean();

  private:
  /**
   * \brief Data to calculate the standard deviation from
   */
  const Vector<T>& m_data;

  /**
   * \brief Size of the data
   */
  unsigned m_size;
};

template <class T>
StandardDeviation<T>::StandardDeviation(const Vector<T>& data) : m_data(data){
  m_size = data.GetSize();
}

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
