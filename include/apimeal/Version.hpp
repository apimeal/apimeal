#ifndef APIMEAL_VERSION_HPP
#define APIMEAL_VERSION_HPP

#include <string>
#include <sstream> 

namespace apimeal {

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