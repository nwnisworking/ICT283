#ifndef MAP_H
#define MAP_H

#include <map>
#include <iostream>

using std::map;

/**
 * \brief A simple Map class that provides minimal but complete functionality.
 */
template <class K, class V>
class Map{
  private:
  /**
   * \brief A map to hold key-value pairs.
   */
  map<K, V> m_map;

  public:
  /**
   * \brief Default constructor of the Map class.
   */
  Map() = default;

  /**
   * \brief Copy constructor of the Map class.
   */
  Map(const Map<K, V>& other);

  /**
   * \brief Assignment operator of the Map class.
   * \param other The Map object to be copied.
   * \return Reference to the current Map object.
   */
  Map& operator=(const Map<K, V>& other);

  /**
   * \brief Insert a key-value pair into the map.
   * \param key The key to be inserted.
   * \param value The value associated with the key.
   */
  void Insert(const K& key, const V& value);

  /**
   * \brief Search for a key in the map.
   * \param key The key to be searched.
   * \return True if the key exists, otherwise false.
   */
  bool Search(const K& key) const;

  /**
   * \brief Get the value associated with a key.
   * \param key The key to be searched.
   * \return Pointer to the value if found, otherwise nullptr.
   */
  V* Get(const K& key);

  /**
   * \brief Get the value associated with a key (const version).
   * \param key The key to be searched.
   * \return Reference to the value if found, otherwise throws an exception.
   */
  const V* Get(const K& key) const;

  /**
   * \brief Remove a key-value pair from the map.
   * \param key The key to be removed.
   */
  void Remove(const K& key);
};

template <class K, class V>
Map<K, V>::Map(const Map<K, V>& other) : m_map(other.m_map){}

template <class K, class V>
Map<K, V>& Map<K, V>::operator=(const Map<K, V>& other){
  if(this != &other){
    m_map = other.m_map;
  }

  return *this;
}

template <class K, class V>
void Map<K, V>::Insert(const K& key, const V& value){
  m_map[key] = value;
}

template <class K, class V>
bool Map<K, V>::Search(const K& key) const{
  return m_map.find(key) != m_map.end();
}

template <class K, class V>
V* Map<K, V>::Get(const K& key){
  typename map<K,V>::iterator iter = m_map.find(key);

  if(iter != m_map.end()){
    return &iter->second;
  }

  return nullptr;
}

template <class K, class V>
const V* Map<K, V>::Get(const K& key) const{
  typename map<K,V>::const_iterator iter = m_map.find(key);

  if(iter != m_map.end()){
    return &iter->second;
  }

  return nullptr;
}

template <class K, class V>
void Map<K, V>::Remove(const K& key){
  m_map.erase(key);
}

#endif
