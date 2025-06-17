#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <string>

using std::string;

const int INITIAL_CAPACITY = 10;

template<class T>
class Vector{
	public:
  /**
   * \brief Default constructor for the Vector object
   */
  Vector();

  /**
   * \brief Parametized constructor for the Vector object
   * \param size Size of the vector array
   */
  Vector(int size);

  /**
   * \brief Destructor for the Vector object
   */
  virtual ~Vector();

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
   * \brief Erase data from the vector
   */
  void Erase();

  /**
   * \brief Get the size of the vector
   * \return Size of the vector
   */
	int GetSize() const;

  /**
   * \brief Get the capacity of the vector
   * \return Capacity of the vector
   */
	int GetCapacity() const;

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

 private:
 T *m_vector;
 int m_size;
 int m_capacity;

 /**
  * \brief Resize the vector to double its capacity
  */
 void Resize();
};

template <class T>
Vector<T>::Vector(){
  m_capacity = INITIAL_CAPACITY;
  m_vector = new T[m_capacity];
  m_size = 0;
}

template <class T>
Vector<T>::Vector(int size){
  m_capacity = size <= 0 ? INITIAL_CAPACITY : size; // Prevents assigning negative sizes

  m_vector = new T[m_capacity];

  if(m_vector == nullptr){
    m_capacity = 0;
  }

  m_size = 0;
}

template <class T>
Vector<T>::~Vector(){
  if(m_vector != nullptr){
    delete[] m_vector;
  }

  m_vector = nullptr;
}

template <class T>
int Vector<T>::GetSize() const{
  return m_size;
}

template <class T>
int Vector<T>::GetCapacity() const{
  return m_capacity;
}

template <class T>
bool Vector<T>::Insert(const T& data){
  return Insert(data, m_size);
}

template <class T>
bool Vector<T>::Insert(const T& data, int index){
  // Index should be between 0 and size
  if(index < 0 || index > m_size){
    return false;
  }

  // Vector is more than half full, resize it
  // If resize fails, then just use the space m_vector have left
  if(m_size > m_capacity / 2){
    Resize();
  }

  // Shifts element from the current index to the right by + 1
  // We start from the right to avoid any override, saving
  if(m_size < m_capacity){
    for(int i = m_size - 1; i >= index; i--){
      m_vector[i + 1] = m_vector[i];
    }

    m_vector[index] = data;
    m_size++;

    return true;
  }

  return false;
}

template <class T>
bool Vector<T>::Delete(int index){
  // Index should be between 0 and size - 1
  // In the case of size being 0, this if statement will stop it from proceeding.
  if(index < 0 || index >= m_size){
    return false;
  }

  // Shifts the item to the left
  for(int i = index; i < m_size - 1; i++){
    m_vector[i] = m_vector[i + 1];
  }

  m_size--;

  return true;
}

template <class T>
void Vector<T>::Erase(){
 m_size = 0;
}

template <class T>
const T& Vector<T>::operator [](int index) const{
  if(index < 0 || index >= m_size){
    throw std::out_of_range("Index must be from 0 to size - 1");
  }

  return m_vector[index];
}

template <class T>
T& Vector<T>::operator [](int index){
  if(index < 0 || index >= m_size){
    throw std::out_of_range("Index must be from 0 to size - 1");
  }

  return m_vector[index];
}

template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& vec){
  // Check if vector is not the same as the one being assigned to
  if(this == &vec){
    return *this;
  }

  // Delete the current vector if there are items
  if(m_vector != nullptr){
    delete[] m_vector;
  }

  m_size = vec.m_size;
  m_capacity = vec.m_capacity;
  m_vector = new T[m_capacity];

  for(int i = 0; i < m_size; i++){
    m_vector[i] = vec.m_vector[i];
  }

  return *this;
}

template<class T>
void Vector<T>::Resize(){
  T* temp = new T[m_capacity * 2];

  // Guard clause where if temp is not allocated, return straight away
  if(temp == nullptr){
    return;
  }

  for(int i = 0; i < m_size; i++){
    temp[i] = m_vector[i];
  }

  delete[] m_vector;
  m_vector = temp;
  m_capacity*= 2; // Shorthand for m_capacity = m_capacity * 2
}

#endif
