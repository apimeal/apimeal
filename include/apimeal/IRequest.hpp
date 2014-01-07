#ifndef APIMEAL_IREQUEST_HPP
#define APIMEAL_IREQUEST_HPP

#include <map>
#include <string>

namespace apimeal {

/**
 * \class IRequest
 * \brief content of a query
 */
class IRequest {
	public:
	/**
	 * \brief Destructor
	 */
		virtual ~IRequest() {}
		/**
		 * \brief setBody : set the body
		 * \param std::string const & body
		 */
		virtual void setBody(std::string const &) = 0;
		/**
		 * \brief getBody : get the body
		 * \return std::string const & body
		 */
		virtual	std::string const &getBody() const = 0;
		/**
		 * \brief getHeaders : get the headers
		 * \return std::map<std::string, std::string> const & header : example (key : "User-Agent" val : "curl")
		 */
		virtual	std::map<std::string, std::string> const &getHeaders() const = 0;
		/**
		 * \brief addHeaders : adding a line in the header
		 * \param std::string const& key
		 * \param std::string const& value
		 */
		virtual	void addHeader(std::string const &key, std::string const &value) = 0;
		/**
		 * \brief setHeaders : set the header
		 * \param std::map<std::string, std::string> const & header : example (key : "User-Agent" val : "curl")
		 */
		virtual	void setHeaders(std::map<std::string, std::string> const &headers) = 0;
		/**
		 * \brief removeHeader : removing a line in the header
		 * \param std::string const &key
		 */
		virtual	void removeHeader(std::string const &key) = 0;
};

}

#endif