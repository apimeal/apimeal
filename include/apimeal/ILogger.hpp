#ifndef APIMEAL_ILOGGER_HPP
#define APIMEAL_ILOGGER_HPP

#include <string>

namespace apimeal {
/**
 * \class ILogger
 * \brief class for logger
 */
	class ILogger {
	public:
	/**
	 * \brief Destructor
	 */
		virtual ~ILogger() {}
		/**
		 * \brief LogError : method to write in the Error mode
		 * \param std::string const &
		 */
		virtual void LogError(std::string const &) = 0;
		/**
		 * \brief LogDebug : method to write in the Debug mode
		 * \param std::string const &
		 */
		virtual void LogDebug(std::string const &) = 0;
		/**
		 * \brief LogInfo : method to write in the Info mode
		 * \param std::string const &
		 */
		virtual void LogInfo(std::string const &) = 0;

	};
}

#endif
