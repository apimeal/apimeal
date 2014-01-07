#ifndef APIMEAL_ICONNEXION_HPP
#define APIMEAL_ICONNEXION_HPP

#include <string>

namespace apimeal {

class IConnexion {
public:
	virtual ~IConnexion() {}
	virtual std::string const &getHostname() const = 0;
	virtual std::string const &getIp() const = 0;
	virtual int getPort() const = 0;
	virtual std::string const &getRequest() const = 0;
	virtual void setRequest(std::string const &request) = 0;
};

}

#endif