#ifndef Utils_H
#define Utils_H

#include "Vector.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

using std::sqrt;
using std::pow;
using std::abs;
using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * \brief Utility methods for handling misc activities.
 */

namespace Utils{
  /**
   * \brief Calculate the mean of a vector
   * \param vec Vector containing the data
   * \return Mean of the data in the vector
   */
  template <class T>
  T Mean(const Vector<T>& vec);

  /**
   * \brief Calculate the sample standard deviation of a vector
   * \param vec Vector containing the data
   * \return Sample standard deviation of the data in the vector
   */
  template <class T>
  T Sample(const Vector<T>& vec);

  /**
   * \brief Calculate the Pearson correlation coefficient between two vectors
   * \param vec1 First vector containing the data
   * \param vec2 Second vector containing the data
   * \return Pearson correlation coefficient between the two vectors
   */
  template <class T>
  T PearsonCorrelation(const Vector<T>& vec1, const Vector<T>& vec2);

  /**
   * \brief Calculate the mean absolute deviation of a vector
   * \param vec Vector containing the data
   * \return Mean absolute deviation of the data in the vector
   */
  template <class T>
  T MeanAbsoluteDeviation(const Vector<T>& vec);

  /**
   * \brief Calculate the sum of a vector
   * \param vec Vector containing the data
   * \return Sum of the data in the vector
   */
  template <class T>
  T Sum(const Vector<T>& vec);

  /**
   * \brief Trim leading and trailing whitespace from a string
   * \param str The string to be trimmed
   */
  void Trim(string& str);

  /**
   * \brief Displays a message to continue.
   */
  void Continue();

  /**
   * \brief Clears the input buffer.
   */
  void ClearBuffer();
};

template <class T>
T Utils::Mean(const Vector<T>& vec){
  int size = vec.GetSize();

  if(size == 0){
    return 0;
  }

  T total = 0;
  for(int i = 0; i < size; i++){
    total += vec[i];
  }

  return total / size;
}

template <class T>
T Utils::Sample(const Vector<T>& vec){
  int size = vec.GetSize();

  if(size == 0){
    return 0;
  }

  T sum = 0;
  T mean = Mean(vec);

  for(int i = 0; i < size; i++){
    sum += pow(vec[i] - mean, 2);
  }

  return sqrt(sum / (size - 1));
}

template <class T>
T Utils::PearsonCorrelation(const Vector<T>& vec1, const Vector<T>& vec2){
  int size = vec1.GetSize();

  if(size == 0 || size != vec2.GetSize()){
    return -1;
  }

  T mx = Mean(vec1);
  T my = Mean(vec2);
  T numerator = 0;
  T denominator = (size - 1) * Sample(vec1) * Sample(vec2);

  for(int i = 0; i < size; i++){
    numerator+= (vec1[i] - mx) * (vec2[i] - my);
  }

  return denominator == 0 ? 0 : numerator / denominator;
}

template <class T>
T Utils::MeanAbsoluteDeviation(const Vector<T>& vec){
  if(vec.GetSize() == 0){
    return 0;
  }

  T mean = Mean(vec);
  T deviation = 0;

  for(int i = 0; i < vec.GetSize(); i++){
    deviation += abs(vec[i] - mean);
  }

  return deviation / vec.GetSize();
}

template <class T>
T Utils::Sum(const Vector<T>& vec){
  T total = 0;

  for(int i = 0; i < vec.GetSize(); i++){
    total += vec[i];
  }
  return total;
}

#endif
