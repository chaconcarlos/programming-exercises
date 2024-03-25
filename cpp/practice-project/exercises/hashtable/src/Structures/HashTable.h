/**
 * @file HashTable.h
 *
 * @brief Declaration of the HashTable container class.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 * @revision $Revision: 1$.
 */

#ifndef EXAMPLES_HASHTABLE_H_
#define EXAMPLES_HASHTABLE_H_

/* INCLUDES ******************************************************************/

#include <string>
#include <vector>

/* FORWARD DECLARATIONS ******************************************************/

/* CLASS DECLARATION *********************************************************/

namespace Examples
{

/**
 * @brief Container structure that can map keys to values.
 */
class HashTable
{
  public:

    /**
     * @brief Initializes an instance of the HashTable class.
     */
    HashTable();

    /**
     * @brief Finalizes an instance of the HashTable class.
     */
    ~HashTable();

  public:

    /**
     * @brief Gets a value from the hashtable. 
     *
     * @param key The key of the value.
     *
     * @return The value mapped to the given key.
     *
     * @throw NotFoundException if the value is not in the hashtable.
     */
    std::string get(const std::string& key);

    /**
     * @brief Puts a value in the hashtable. 
     *
     * @param key The key of the value.
     * @param value The value mapped to the given key.
     *
     * @remarks If the value is already in the hashtable, it will be modified with the new value.
     */
    void put(const std::string& key, const std::string& value);

  private:

    /**
     * @brief Gets the index of an element given its key.
     *
     * @return The index of the value.
     *
     * @throw NotFoundException if the
     */
    size_t getValueIndex(const std::string& key);

  private:

    std::vector<std::string> m_keys;
    std::vector<std::string> m_values;
};

} /* namespace Examples */

#endif /* EXAMPLES_HASHTABLE_H_ */
