#include "Utils.h"

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
    std::runtime_error("Vectors must be the same size and non-empty.");
  }

  T mx = Mean(vec1);
  T my = Mean(vec2);
  T numerator = 0;
  T denominator = (size - 1) * Sample(vec1) * Sample(vec2);

  for(int i = 0; i < size; i++){
    numerator+= (vec1[i] - mx) * (vec2[i] - my)
  }

  return denominator == 0 ? 0 : numerator / denominator;
}