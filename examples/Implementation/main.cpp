#if defined (_WIN32)
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#include <iostream>
#include "apimeal/AModule.hpp"
#include "Logger.hpp"

using namespace std;


apimeal::AModule *Load(Logger *log, char **argv);

int main(int argc, char **argv)
{
  if (argc != 2) {
	cerr << "no lib" << endl;
	return 1;
  }

  Logger *log = new Logger();

  apimeal::AModule *mod = Load(log, argv);
  if (mod == NULL)
    return 1;

  std::cout << mod->getVersion().Minor << std::endl;

  return 0;
}


#if defined (_WIN32)

//WINDOWS MODE
apimeal::AModule *Load(Logger *log, char **argv) {

  HMODULE library = LoadLibrary(argv[1]);
  if (library == NULL) {
      cerr << "Cannot open library" << endl;
      return NULL;
  } 

  apimeal::AModule* (*create)(apimeal::ILogger *);
  create = apimeal::AModule* (*)(apimeal::ILogger *))GetProcAddress(library,"LoadModule");
  if (create == NULL) {
       cerr << "Cannot load symbol 'LoadModule'" << endl;
       FreeLibrary(library);
  }

  return create(log);
}

#else
//LINUX MODE
apimeal::AModule *Load(Logger *log, char **argv) 
{

  void* handle = dlopen(argv[1], RTLD_LAZY);
  if (!handle) {
      cerr << "Cannot open library: " << dlerror() << endl;
      return NULL;
  }

  apimeal::AModule* (*create)(apimeal::ILogger *);
  create = (apimeal::AModule* (*)(apimeal::ILogger *))dlsym(handle, "LoadModule");

  const char *dlsym_error = dlerror();
  if (dlsym_error) {
     cerr << "Cannot load symbol 'LoadModule': " << dlsym_error << endl;
     dlclose(handle);
     return NULL;
  }

  return create(log);
}
#endif
