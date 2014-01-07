#ifndef APIMEAL_IHTTPREQUEST_HPP
#define APIMEAL_IHTTPREQUEST_HPP

#include "IRequest.hpp"

namespace apimeal {

/**
 * \class IHttpRequest
 * \brief class for managing request
 */
	class IHttpRequest : public IRequest {
	public:
	/**
	 * \brief Destructor
	 */
	virtual ~IHttpRequest() {}
	/**
	 * \brief Setter for _method
	 * \param std::string const & method
	 */
		virtual void setMethod(std::string const &) = 0;
		/**
		 * \brief Getter for _method
		 * \return std::string const & : method
		 */
		virtual std::string const &getMethod() const = 0;
		/**
		 * \brief Setter for _requestURI
		 * \param std::string const & requestURI
		 */
		virtual void setRequestURI(std::string const &) = 0;
		/**
		 * \brief Getter for _requestURI
		 * \return std::string const & : requestURI
		 */
		virtual std::string const &getRequestURI() const = 0;
	};
}

#endif