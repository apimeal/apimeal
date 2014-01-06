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
protected:
	virtual std::list<eTypeModule> getType() const = 0;
	virtual std::list<float> getPriority() const = 0;
	virtual Version const &getVersion() const = 0;
	virtual std::string getName() const = 0;

	virtual void* preConnexion(Connexion &, Error &) { return NULL };
	virtual void* postConnexion(Connexion &, Error &) { return NULL };
	virtual void* preParseRequest(HttpRequest &, Error &) { return NULL };
	virtual void* postParseRequest(HttpRequest&, Error &) { return NULL };
	virtual void* contentModule(HttpRequest &, Error &) { return NULL };
	virtual void* CGIModule(HttpRequest &, Error &) { return NULL };
	virtual void* postGenerateResponse(HttpResponse &, Error &) { return NULL };
	virtual void* preSendRequest(HttpResponse &, Error &) { return NULL };

};


}

#endif
