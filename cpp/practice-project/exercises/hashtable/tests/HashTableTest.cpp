/**
 * @file HashTableTest.h
 *
 * @brief Implementation of the HashTable class tests.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 * @revision $Revision: 1$.
 */

/* INCLUDES ******************************************************************/

#include "../src/Structures/HashTable.h"

#include <gmock/gmock.h>
#include <string>

/* USINGS ********************************************************************/

using namespace Examples;
using namespace testing;

/* IMPLEMENTATION ************************************************************/

TEST(HashTableTest, add_and_query_element)
{
  HashTable         container;
  const std::string key   = "key";
  const std::string value = "value";

  container.put(key, value);

  ASSERT_THAT(container.get(key), Eq(value));
}

TEST(HashTableTest, add_and_query_multiple_elements)
{
  HashTable container;

  container.put("key1", "value1");
  container.put("key2", "value2");
  container.put("key3", "value3");
  container.put("key4", "value4");
  container.put("key5", "value5");

  ASSERT_THAT(container.get("key1"), Eq("value1"));
  ASSERT_THAT(container.get("key2"), Eq("value2"));
  ASSERT_THAT(container.get("key3"), Eq("value3"));
  ASSERT_THAT(container.get("key4"), Eq("value4"));
  ASSERT_THAT(container.get("key5"), Eq("value5"));
}
