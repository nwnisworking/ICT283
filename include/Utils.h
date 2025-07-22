#ifndef Utils_H
#define Utils_H

#include "Vector.h"
#include <cmath>
#include <stdexcept>

using std::sqrt;
using std::pow;

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
};


#endif