#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <vector>

using std::vector;

/**
 * \brief Vector class to represent a dynamic array
 * \details This class provides methods to insert, delete, and access elements in a vector-like structure.
 */
template<class T>
class Vector{
	public:
  /**
   * \brief Default constructor for the Vector object
   */
  Vector() = default;

  /**
   * \brief Parametized constructor for the Vector object
   * \param size Size of the vector array
   */
  Vector(int size);

  /**
   * \brief Copy constructor for the Vector object
   * \param vec The vector to copy from
   */
  Vector(const Vector<T>& vec);

  /**
   * \brief Insert data into the vector at the last index
   * \param data Data to be inserted
   * \return true if insertion is successful, false otherwise
   */
	bool Insert(const T& data);

  /**
   * \brief Insert data into the vector at a specific index
   * \param data Data to be inserted
   * \param index Index at which the data should be inserted
   * \return true if insertion is successful, false otherwise
   */
	bool Insert(const T& data, int index);

  /**
   * \brief Delete data from the vector at a specific index
   * \param index Index from which the data should be deleted
   * \return true if deletion is successful, false otherwise
   */
  bool Delete(int index);

  /**
   * \brief Get the size of the vector
   * \return Size of the vector
   */
	int GetSize() const;

  /**
   * \brief Subscript operator to access elements in the vector as a readonly reference
   * \param index Index of the element to access
   * \return Reference to the element at the specified index
   */
 const T& operator [](int index) const;

  /**
   * \brief Subscript operator to access elements in the vector as a modifiable reference
   * \param index Index of the element to access
   * \return Reference to the element at the specified index
   */
  T& operator [](int index);

  /**
   * \brief Assignment operator to copy the contents of another vector
   * \param vec The vector to copy from
   * \return Reference to the current vector after copying
   */
  Vector<T>& operator =(const Vector<T>& vec);

  /**
   * \brief Clear the vector by removing all elements
   */
  void Clear();

  private:
  vector<T> m_vector;
};

template <class T>
Vector<T>::Vector(int size){
  if(size >= 1){
    m_vector.reserve(size);
  }
}

template <class T>
Vector<T>::Vector(const Vector<T>& vec){
  m_vector = vec.m_vector;
}

template <class T>
int Vector<T>::GetSize() const{
  return m_vector.size();
}

template <class T>
bool Vector<T>::Insert(const T& data){
  return Insert(data, GetSize());
}

template <class T>
bool Vector<T>::Insert(const T& data, int index){
  if(index < 0 || index > GetSize()){
    return false;
  }

  try{
    if(index == GetSize()){
      m_vector.push_back(data);
    }
    else{
      m_vector.insert(m_vector.begin() + index, data);
    }
  }
  catch(...){
    return false;
  }

  return true;
}

template <class T>
bool Vector<T>::Delete(int index){
  if(GetSize() == 0 || index < 0 || index >= GetSize()){
    return false;
  }

  m_vector.erase(m_vector.begin() + index);
  return true;
}

template <class T>
const T& Vector<T>::operator [](int index) const{
  return m_vector[index];
}

template <class T>
T& Vector<T>::operator [](int index){
  return m_vector[index];
}

template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& vec){
  if(this != &vec){
    m_vector = vec.m_vector;
  }

  return *this;
}

template <class T>
void Vector<T>::Clear(){
  m_vector.clear();
}

#endif
