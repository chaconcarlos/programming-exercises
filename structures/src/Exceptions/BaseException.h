/**
 * @file BaseException.h
 *
 * @brief Declaration of the base exception class.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 * @revision $Revision: 1$.
 */

#ifndef EXAMPLES_BASEEXCEPTION_H_
#define EXAMPLES_BASEEXCEPTION_H_

/* INCLUDES ******************************************************************/

#include <exception>
#include <string>

/* DECLARATION ***************************************************************/

namespace Examples
{

/**
 * @brief Base exception class.
 */
class BaseException : public virtual std::exception
{
  public:

    /**
     * @brief Initializes a new instance of the BaseException class.
     *
     * @param message The description message.
     */
    explicit BaseException(const std::string& message);

    /**
     * @brief Initializes a new instance of the BaseException class.
     *
     * @param code    The error code.
     * @param message The description message.
     */
    BaseException(int code, const std::string& message);

    /**
     * @brief Initializes a new instance of the BaseException class.
     *
     * @param other The exception to copy.
     */
    BaseException(const BaseException& other); /* throw() */

    /**
     * @brief Finalizes an instance of the BaseException class.
     */
    virtual ~BaseException() throw();

  public:

    /**
     * @brief Gets the explanatory message.
     *
     * @return The explanatory string.
     */
    virtual const char* what() const throw();

    /**
     * @brief Gets the full message (code and explanatory message).
     *
     * @return The full message string.
     */
    std::string getMessage() const;

    /**
     * @brief Gets the error code.
     *
     * @return The code.
     */
    int getCode() const;

    /**
     * @brief Assignment operator overload for the BaseException class.
     *
     * @param rhs The BaseException being assigned.
     *
     * @return A reference to this instance.
     */
    BaseException& operator=(const BaseException& rhs);

  private:

    int         m_code;
    std::string m_what;
};

} /* namespace Examples */

#endif /* EXAMPLES_BASEEXCEPTION_H_ */
