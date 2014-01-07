#ifndef APIMEAL_AMODULE_HPP
#define APIMEAL_AMODULE_HPP

#include <map>
#include "Version.hpp"
#include "eTypeModule.hpp"
#include "ePriority.hpp"
#include "IConnexion.hpp"
#include "IHttpRequest.hpp"
#include "IHttpResponse.hpp"
#include "Error.hpp"
#include "ILogger.hpp"

namespace apimeal {

/**
* \class AModule
* \brief class which represent the module
*/
class AModule {
protected:
	/**
	* Logger
	*/
	ILogger *_logger;

public:
	/**
	* \brief Constructor
	* Constructor of class AModule
	* \param log : Logger link with the module
	*/
	AModule(ILogger *log)
		: _logger(log)
	 {}
	 /**
	 * \brief Destructor
	 * Destructor of class AModule
	 */
	virtual ~AModule() {}

	/**
	* \brief Get map of module's priority
	* \return Map of priority of module 
	*/
	virtual std::map<eTypeModule, ePriority> getPriority() const = 0;
	/**
	* \brief Get version of the module
	* \return Version of the module
	*/
	virtual Version const &getVersion() const = 0;
	/**
	* \brief Get name of module
	* \return String with the module's name
	*/
	virtual std::string const &getName() const = 0;

	/**
	* \brief Before connexion
	* \param IConnexion : Class for connecting a client
	* \param Error : Class for manage an error
	*/
	virtual void preConnexion(IConnexion *, Error &) { };
	/**
	* \brief After connexion
	* \param IConnexion : Class for connecting a client
	* \param Error : Class for manage an error
	*/
	virtual void postConnexion(IConnexion *, Error &) { };
	/**
	* \brief Before parsing a query
	* \param IHttpRequest : Class for manage a query
	* \param Error : Class for manage an error
	*/
	virtual void preParseRequest(IHttpRequest *, Error &) { };
	/**
	* \brief After parsing a request
	* \param IHttpRequest : Class for manage a query
	* \param Error : Class for manage an error
	*/
	virtual void postParseRequest(IHttpRequest *, Error &) { };
	/**
	* \brief Get body of the request
	* \param IHttpRequest : Class for manage a query
	* \param Error : Class for manage an error
	*/
	virtual void contentModule(IHttpRequest *, Error &) { };
	/**
	* \brief Manage of Common Gateway Interface
	* \param IHttpRequest : Class for manage a query
	* \param Error : Class for manage an error
	*/
	virtual void CGIModule(IHttpRequest *, Error &) { };
	/**
	* \brief After generation of the response
	* \param IHttpResponse : Class with the query response
	* \param Error : Class for manage an error
	*/
	virtual void postGenerateResponse(IHttpResponse *, Error &) { };
	/**
	* \brief Before sending the response
	* \param IHttpResponse : Class with the query response
	* \param Error : Class for manage an error
	*/
	virtual void preSendRequest(IHttpResponse *, Error &) { };

	/**
	* \brief Free memory
	*/
	virtual void release() { delete this; }
};

}

#if defined (_WIN32)
#if defined(DllApimeal)
#define DLLAPIMEAL __declspec(dllexport)
#else
#define DLLAPIMEAL __declspec(dllimport)
#endif
#else
#define DLLAPIMEAL
#endif

#endif
