#ifndef APIMEAL_AMODULE_HPP
#define APIMEAL_AMODULE_HPP

#include "Version.hpp"
#include "eTypeModule.hpp"
#include "ePriority.hpp"
#include "Connexion.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

namespace apimeal {

class AModule {
public:
	virtual ~AModule() {};

	virtual std::list<eTypeModule> getType() const = 0;
	virtual std::list<float> getPriority() const = 0;
	virtual Version const &getVersion() const = 0;
	virtual std::string const &getName() const = 0;

	virtual void preConnexion(Connexion &, Error &) { };
	virtual void postConnexion(Connexion &, Error &) { };
	virtual void preParseRequest(HttpRequest &, Error &) { };
	virtual void postParseRequest(HttpRequest&, Error &) { };
	virtual void contentModule(HttpRequest &, Error &) { };
	virtual void CGIModule(HttpRequest &, Error &) { };
	virtual void postGenerateResponse(HttpResponse &, Error &) { };
	virtual void preSendRequest(HttpResponse &, Error &) { };

};


}

#endif
