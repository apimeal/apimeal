#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "apimeal/ILogger.hpp"

class Logger : public apimeal::ILogger {
public:
		virtual void LogError(std::string const &);
		virtual void LogDebug(std::string const &);
		virtual void LogInfo(std::string const &);

};

#endif