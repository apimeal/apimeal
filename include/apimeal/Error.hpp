#ifndef APIMEAL_ERROR_HPP
#define APIMEAL_ERROR_HPP

#include <string>

namespace apimeal {

class Error {
private:
	int _code;
	std::string _message;

public:
	void setCode(int code) { code = _code; }
	int getCode() const { return _code; }
	void setMessage(std::string const &message) { _message = message; } 
	std::string const &getMessage() const { return _message; }
};

}

#endif