/**
 * @file HashTable.cpp
 *
 * @brief Implementation of the HashTable container class.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 * @revision $Revision: 1$.
 */

/* INCLUDES ******************************************************************/

#include "HashTable.h"

#include "../Exceptions/NotFoundException.h"

#include <algorithm>

/* USINGS ********************************************************************/

/* DEFINITIONS ***************************************************************/

/* STATIC IMPLEMENTATIONS ****************************************************/

/* CLASS IMPLEMENTATION ******************************************************/

namespace Examples
{

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

std::string 
HashTable::get(const std::string& key)
{
  const size_t index = getValueIndex(key);
  return m_values[index];
}

void 
HashTable::put(const std::string& key, const std::string& value)
{
  m_keys.push_back(key);
  m_values.push_back(value);
}

size_t
HashTable::getValueIndex(const std::string& key)
{
  size_t                                         index   = 0;
  const std::vector<std::string>::const_iterator element = std::find(m_keys.begin(), m_keys.end(), key);

  if (element != m_keys.end())
  {
    index = element - m_keys.begin();
  }
  else
  {
    const std::string message = "Element with key '" + key + "' not found.";
    throw NotFoundException(message);
  }

  return index;
}

} /* namespace Examples */
