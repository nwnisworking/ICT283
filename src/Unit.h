#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::stoi;
using std::getline;

/**
 * \class Unit
 * \brief Represents an academic unit or subject, including its identifier, name, and credit value.
 *
 * The Unit class encapsulates the essential details of an academic course unit,
 * such as its unique identifier, its formal name, and the number of academic credits it carries.
 */
class Unit {
public:
  /**
   * \brief Default constructor.
   *
   * Initializes the unit with default values.
   */
  Unit();

  /**
   * \brief Parameterized constructor.
   *
   * Constructs a Unit with the specified name, identifier, and credit value.
   * \param name The name of the academic unit.
   * \param uid The unique identifier for the unit.
   * \param credits The number of credits the unit carries.
   */
  Unit(const string& name, const string& uid, unsigned credits);

  /**
   * \brief Retrieves the name of the unit.
   * \param name Reference where the unit name will be stored.
   */
  void GetName(string& name) const;

  /**
   * \brief Sets the name of the unit.
   * \param name The unit name.
   */
  void SetName(const string& name);

  /**
   * \brief Retrieves the unit's identifier.
   * \param id Reference where the unit ID will be stored.
   */
  void GetId(string& id) const;

  /**
   * \brief Sets the unit's identifier.
   * \param id The unique identifier for the unit.
   */
  void SetId(const string& id);

  /**
   * \brief Retrieves the number of credits for the unit.
   * \return The credit value.
   */
  unsigned GetCredits() const;

  /**
   * \brief Sets the number of credits for the unit.
   * \param credits The credit value.
   */
  void SetCredits(unsigned credits);

private:
  string m_name;     
  string m_id;       
  unsigned m_credits;
};

/**
 * \brief Overloads the output stream operator for Unit objects.
 * \param output The output stream.
 * \param unit The Unit object to be output.
 * \return A reference to the output stream.
 */
ostream& operator<<(ostream& output, const Unit& unit);

/**
 * \brief Overloads the input stream operator for Unit objects.
 * \param input The input stream.
 * \param unit The Unit object to be populated.
 * \return A reference to the input stream.
 */
istream& operator>>(istream& input, Unit& unit);

#endif
