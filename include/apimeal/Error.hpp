#ifndef APIMEAL_ERROR_HPP
#define APIMEAL_ERROR_HPP

#include <string>

namespace apimeal {

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