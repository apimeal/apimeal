#ifndef APIMEAL_AMODULE_HPP
#define APIMEAL_AMODULE_HPP

#include "Version.hpp"
#include "eTypeModule.hpp"
#include "ePriority.hpp"

namespace apimeal {

class AModule {
protected:
	virtual eTypeModule getType() = 0;
	virtual float getPriority() = 0;
	virtual std::string getVersion() = 0;

	virtual void* preConnexion() {return NULL};
	virtual void* postConnexion() {return NULL};
	virtual void* preParseRequest() {return NULL};
	virtual void* postParseRequest() {return NULL};
	virtual void* contentModule() {return NULL};
	virtual void* preGenerateeRsponse() {return NULL};
	virtual void* postGenerateResponse() {return NULL};
	virtual void* sendRequest() {return NULL};

};


}

#endif
