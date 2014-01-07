#ifndef APIMEAL_IREQUEST_HPP
#define APIMEAL_IREQUEST_HPP

#include <map>
#include <string>

namespace apimeal {

class IRequest {
	public:
		virtual ~IRequest() {};
		virtual void setBody(std::string const &) = 0;
		virtual	std::string const &getBody() const = 0;
		virtual	std::map<std::string, std::string> const &getHeaders() const = 0;
		virtual	void addHeader(std::string const &key, std::string const &value) = 0;
		virtual	void setHeaders(std::map<std::string, std::string> const &headers) = 0;
		virtual	void removeHeader(std::string const &key) = 0;
};

}

#endif