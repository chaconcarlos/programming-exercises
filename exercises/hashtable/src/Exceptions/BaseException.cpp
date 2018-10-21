/**
 * @file BaseException.cpp
 *
 * @brief Implementation of the base exception class.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 * @revision $Revision: 1$.
 */

/* INCLUDES ******************************************************************/

#include "BaseException.h"

/* IMPLEMENTATION ************************************************************/

namespace Examples
{

BaseException::BaseException(const std::string& message)
: m_code(0)
, m_what(message)
{
}

BaseException::BaseException(const int code, const std::string& message)
: m_code(code)
, m_what(message)
{
}

BaseException::BaseException(const BaseException& other)
: std::exception(other)
, m_code(other.m_code)
, m_what(other.m_what)
{
}

BaseException::~BaseException() throw()
{
}

const char*
BaseException::what() const throw()
{
  return m_what.c_str();
}

std::string
BaseException::getMessage() const
{
  return m_what;
}

int
BaseException::getCode() const
{
  return m_code;
}

BaseException&
BaseException::operator=(const BaseException& rhs)
{
  m_code = rhs.m_code;
  m_what = rhs.m_what;
  std::exception::operator=(rhs);

  return *this;
}

} /* namespace Examples */
