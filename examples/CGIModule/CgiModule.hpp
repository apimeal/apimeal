#ifndef APIMEALEXAMPLE_CGIMODULE_HPP
#define APIMEALEXAMPLE_CGIMODULE_HPP

#include "apimeal/AModule.hpp"
#include "apimeal/Version.hpp"

class CgiModule : public apimeal::AModule {
public:
	CgiModule();

	std::list<apimeal::eTypeModule> getType() const;
	std::list<apimeal::ePriority> getPriority() const;
	Version const &getVersion() const;
	std::string getName() const;

	void CGIModule(IHttpRequest *, Error &);
private:
	Version _version;
	std::string _name;

};

#endif