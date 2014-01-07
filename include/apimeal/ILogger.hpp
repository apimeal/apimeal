#ifndef APIMEAL_ILOGGER_HPP
#define APIMEAL_ILOGGER_HPP

#include <string>

namespace apimeal {

	class ILogger {
	public:
		virtual ~ILogger() {}
		virtual void LogError(std::string const &) = 0;
		virtual void LogDebug(std::string const &) = 0;
		virtual void LogInfo(std::string const &) = 0;

	};
}

#endif