#ifndef APIMEAL_VERSION_HPP
#define APIMEAL_VERSION_HPP

#include <string>
#include <sstream> 

namespace apimeal {
/**
 * \struct Version
 * \brief Set the slice versions compatible with the module
 * 
 * \param int max
 * \param int min
 */
	struct Version
	 {
	 public:
		Version(int ma, int mi)
			: Major(ma), Minor(mi) {}
		int Major;
		int Minor;
	 };
	
}

#endif