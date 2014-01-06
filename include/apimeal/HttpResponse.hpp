#ifndef APIMEAL_HTTPREQUEST_HPP
#define APIMEAL_HTTPREQUEST_HPP

#include "Request.hpp"

namespace apimeal {

	class HttpResponse : public Request {
	private:
		int _statusCode;
		std::string _reasonPhrase;

	public:
		void setStatusCode(int);
		int getStatusCode() const;
		void setReasonPhrase(std::string const &);
		std::string const &getReasonPhrase() const;
	};
}

#endif