/**
 * @file NotFoundException.h
 *
 * @brief Declaration of the base exception class.
 *
 * @author   Carlos Chacon <chacon.carlosj@gmail.com>
 * @date     Mar 21, 2018
 * @revision $Revision: 1$.
 */

#ifndef EXAMPLES_NOTFOUNDEXCEPTION_H_
#define EXAMPLES_NOTFOUNDEXCEPTION_H_

/* INCLUDES ******************************************************************/

#include "BaseException.h"

/* DECLARATION ***************************************************************/

namespace Examples
{

/**
 * @brief Base exception class.
 */
class NotFoundException : public BaseException
{
  public:

    /**
     * @brief Initializes a new instance of the BaseException class.
     *
     * @param message The description message.
     */
    explicit NotFoundException(const std::string& message)
    : BaseException(message)
    {
    }

    /**
     * @brief Initializes a new instance of the NotFoundException class.
     *
     * @param code    The error code.
     * @param message The description message.
     */
    NotFoundException(int code, const std::string& message)
    : BaseException(code, message)
    {
    }

    /**
     * @brief Finalizes an instance of the BaseException class.
     */
    virtual ~NotFoundException() throw() {}
};

} /* namespace Examples */

#endif /* EXAMPLES_NOTFOUNDEXCEPTION_H_ */
