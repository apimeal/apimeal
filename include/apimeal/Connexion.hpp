#ifndef APIMEAL_CONNEXION_HPP
#define APIMEAL_CONNEXION_HPP

#include <string>

namespace apimeal {

class Connexion {
private:
	std::string const _hostname;
	std::string const _ip;
	int const _port;
	std::string &_request;
	
public:
	Connexion(std::string const &hostname, std::string const &ip, int const port = 80, std::string &request =  "")
		: _request(request), _hostname(hostname), _ip(ip), _port(port)
	{
	}

	std::string const &getHostname() { return _hostname; }
	std::string const &getIp() { return _ip; }
	int getPort() { return _port; }
	std::string const &getRequest() { return _request; }
	
	void setRequest(std::string const &request) { _request = request; }
	

};

}

#endif