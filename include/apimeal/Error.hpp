#ifndef APIMEAL_ERROR_HPP
#define APIMEAL_ERROR_HPP

#include <string>

namespace apimeal {

struct Error {
public:
	Error()
		: Error(false), Code(0), Message("")
	 {}

	bool Error
	int Code;
	std::string Message;
};

}

#endif