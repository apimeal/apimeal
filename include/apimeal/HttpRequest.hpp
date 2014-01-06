#ifndef APIMEAL_HTTPREQUEST_HPP
#define APIMEAL_HTTPREQUEST_HPP

#include "Request.hpp"

namespace apimeal {

	class HttpRequest : public Request {
	private:
		std::string _method;
		std::string _requestURI;

	public:
		void setMethod(std::string const &);
		std::string const &getMethod() const;
		void setRequestURI(std::string const &);
		std::string const &getRequestURI() const;
	};
}

#endif