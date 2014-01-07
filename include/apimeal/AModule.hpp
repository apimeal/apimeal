#ifndef APIMEAL_AMODULE_HPP
#define APIMEAL_AMODULE_HPP

#include <list>
#include "Version.hpp"
#include "eTypeModule.hpp"
#include "ePriority.hpp"
#include "IConnexion.hpp"
#include "IHttpRequest.hpp"
#include "IHttpResponse.hpp"
#include "Error.hpp"

namespace apimeal {

class AModule {
public:
	virtual ~AModule() {};

	virtual std::list<eTypeModule> getType() const = 0;
	virtual std::list<ePriority> getPriority() const = 0;
	virtual Version const &getVersion() const = 0;
	virtual std::string const &getName() const = 0;

	virtual void preConnexion(IConnexion *, Error &) { };
	virtual void postConnexion(IConnexion *, Error &) { };
	virtual void preParseRequest(IHttpRequest *, Error &) { };
	virtual void postParseRequest(IHttpRequest *, Error &) { };
	virtual void contentModule(IHttpRequest *, Error &) { };
	virtual void CGIModule(IHttpRequest *, Error &) { };
	virtual void postGenerateResponse(IHttpResponse *, Error &) { };
	virtual void preSendRequest(IHttpResponse *, Error &) { };

};


}

#endif
