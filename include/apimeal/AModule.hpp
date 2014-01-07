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

class AModule {
protected:
	ILogger *_logger;

public:
	AModule(ILogger *log)
		: _logger(log)
	 {}
	virtual ~AModule() {}

	virtual std::map<eTypeModule, ePriority> getPriority() const = 0;
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
