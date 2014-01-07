#ifndef APIMEALEXAMPLE_CGIMODULE_HPP
#define APIMEALEXAMPLE_CGIMODULE_HPP

#include "apimeal/AModule.hpp"
#include "apimeal/Version.hpp"

class CgiModule : public apimeal::AModule {
public:
	CgiModule();

	std::list<apimeal::eTypeModule> getType() const;
	std::list<apimeal::ePriority> getPriority() const;
	apimeal::Version const &getVersion() const;
	std::string const &getName() const;

	void CGIModule(apimeal::IHttpRequest *, apimeal::Error &);
private:
	apimeal::Version _version;
	std::string _name;

};

#endif