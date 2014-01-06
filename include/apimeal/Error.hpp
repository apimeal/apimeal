#ifndef APIMEAL_ERROR_HPP
#define APIMEAL_ERROR_HPP

#include <string>

namespace apimeal {

class Error {
private:
	int _code;
	std::string _message;

public:
	void setCode(int code);
	int getCode() const;
	void setMessage(std::string const &message); 
	std::string const &getMessage() const;
};

}

#endif