#ifndef APIMEAL_VERSION_HPP
#define APIMEAL_VERSION_HPP

#include <string>
#include <sstream> 

namespace apimeal {

	class Version {
	private:
		int _major;
		int _minor;

	public:
		Version(major = 0, minor = 0)
			: _major(major), _minor(minor) {
		}

		std::string getName() {
			std::ostringstream convertMajor;
			std::ostringstream convertMinor;
			convertMinor << _minor;
			convertMajor << _major;
			return convertMajor.str() + '.' + convertMinor.str();
		}

		int getMajor() { return _major; }
		int getMinor() { return _minor; }
	};
}

#endif