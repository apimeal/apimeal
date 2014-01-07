#include <dlfcn.h>
#include <iostream>
#include "apimeal/AModule.hpp"

using namespace std;


/**
* EXEMPLE : Seulement compatible linux
*/
int main(int argc, char **argv)
{
  if (argc != 2) {
	cerr << "no lib" << endl;   
  }
  
  void* handle = dlopen(argv[1], RTLD_LAZY);
  if (!handle) {
      cerr << "Cannot open library: " << dlerror() << '\n';
      return 1;
  }

  apimeal::AModule* (*create)();
  create = (apimeal::AModule* (*)())dlsym(handle, "LoadModule");

  const char *dlsym_error = dlerror();
  if (dlsym_error) {
     cerr << "Cannot load symbol 'LoadModule': " << dlsym_error << std::endl;
     dlclose(handle);
     return 1;
  }

  std::cout << create()->getVersion().Minor << std::endl;

  return 0;
}

