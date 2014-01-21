#ifndef APIMEAL_ICONNEXION_HPP
#define APIMEAL_ICONNEXION_HPP

#include <string>

#ifdef WIN32 
#include <winsock2.h> 
#elif defined (linux) 
typedef int SOCKET;
#else
#error not defined for this platform
#endif


namespace apimeal {

/**
 * \class IConnexion
 * \brief Class for connecting a client
 */
class IConnexion {
public:
	/**
  	 * \brief Destructor virtuel
	 */
	virtual ~IConnexion() {}
	/**
	 * \brief getHostname
	 * \return std::string const & : Hostname client
	 */
	virtual std::string const &getHostname() const = 0;
	/**
	 * \brief getIp
	 * \return std::string const & : Ip client ex (192.168.0.1)
	 */
	virtual std::string const &getIp() const = 0;
	/**
	 * \brief getPort
	 * \return int : Port client
	 */
	virtual int getPort() const = 0;
	/**
	 * \brief get the Request
	 * \return std::string  const & : Request client
	 */
	virtual std::string const &getRequest() const = 0;
	/**
	 * \brief set the Request
	 * \param std::string const & request : The request
	 * \return void
	 */
	virtual void setRequest(std::string const &request) = 0;

	/**
	 * \brief set the socket
	 * \param SOCKET : The socket
	 * \return void
	 */
	virtual void setSocket(SOCKET) = 0;

	/**
         * \brief get the socket 
	 * \return SOCKET: the socket
	 */
	virtual SOCKET getSocket() = 0;
};

}

#endif
