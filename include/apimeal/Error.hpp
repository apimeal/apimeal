#ifndef APIMEAL_ERROR_HPP
#define APIMEAL_ERROR_HPP

#include <string>

namespace apimeal {

/**
 * \struct Error
 * \brief Struct for error handling
 * bool IsError (true if there was an error)
 * int Code (error code)
 * std::string Message (Message print)
 */
struct Error {
public:
	Error()
		: IsError(false), Code(0), Message("")
	 {}

	bool IsError;
	int Code;
	std::string Message;
};

}

#endif