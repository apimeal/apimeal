#ifndef APIMEAL_IHTTPRESPONSE_HPP
#define APIMEAL_IHTTPRESPONSE_HPP

#include "IRequest.hpp"

namespace apimeal {
/**
 * \class IHttpResponse
 * \brief class for create an response request
 */
	class IHttpResponse : public IRequest {
	public:
	/**
	 * \brief setStatusCode
	 * \param int code : return code
	 */
		virtual void setStatusCode(int) = 0;
		/**
		 * \brief getStatusCode
		 * \return int : return code
		 */
		virtual int getStatusCode() const = 0;
		/**
		 * \brief setReasonPhrase
		 * \param std::string const & : the reason phrase
		 */
		virtual void setReasonPhrase(std::string const &) = 0;
		/**
		 * \brief getReasonPhrase
		 * \return std::string const & : the reason phrase
		 */
		virtual std::string const &getReasonPhrase() const = 0;
	};
}

#endif