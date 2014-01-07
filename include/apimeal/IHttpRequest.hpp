#ifndef APIMEAL_IHTTPREQUEST_HPP
#define APIMEAL_IHTTPREQUEST_HPP

#include "IRequest.hpp"

namespace apimeal {

	class IHttpRequest : public IRequest {
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