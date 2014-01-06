#ifndef APIMEAL_REQUEST_HPP
#define APIMEAL_REQUEST_HPP

#include <map>
#include <string>

namespace apimeal {

class Request {
	protected:
		std::string _body;
		std::map<std::string, std::string> _headers;
		Version	 _httpVersion;

	public:
		void setBody(std::string const &);
		std::string const &getBody() const;
		std::map<std::string, std::string> const &getHeaders() const;
		void addHeader(std::string const &key, std::string const &value);
		void setHeaders(std::map<std::string, std::string> const &headers);
		void removeHeader(std::string const &key);
};

}

#endif