#ifndef SDRESULT_H
#define SDRESULT_H

/**
 * \brief The SDResult struct representing the result of a standard deviation calculation.
 */
struct SDResult{
  /**
   * \brief Average value of the dataset.
   */
  float average;

  /**
   * \brief Sample standard deviation of the dataset.
   */
  float sample;

  /**
   * \brief Size of the dataset.
   */
  unsigned size;
};

#endif
