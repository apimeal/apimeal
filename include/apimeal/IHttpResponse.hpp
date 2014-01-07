#ifndef APIMEAL_IHTTPRESPONSE_HPP
#define APIMEAL_IHTTPRESPONSE_HPP

#include "IRequest.hpp"

namespace apimeal {

	class IHttpResponse : public IRequest {
	public:
		virtual void setStatusCode(int) = 0;
		virtual int getStatusCode() const = 0;
		virtual void setReasonPhrase(std::string const &) = 0;
		virtual std::string const &getReasonPhrase() const = 0;
	};
}

#endif