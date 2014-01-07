#include "CgiModule.hpp"

CgiModule::CgiModule(apimeal::ILogger *log)
 : AModule(log), _version(0,1), _name("CgiModule")
{

}

std::list<apimeal::eTypeModule> CgiModule::getType() const {
	// création d'une liste qui contiendra
	// notre point d'insertion pour l'api
	std::list<apimeal::eTypeModule> list;
	// on ajoute dans notre liste le CGIMODULE pour pouvoir l'utiliser
	list.push_back(apimeal::CGIMODULE);
	return list;
}

std::list<apimeal::ePriority> CgiModule::getPriority() const {
	std::list<apimeal::ePriority> list;
	// on definie une priorité de 0.5 pour notre module
	list.push_back(0.5f);
	return list;
}

apimeal::Version const &CgiModule::getVersion() const {
	return _version;
}

std::string const &CgiModule::getName() const {
	return _name;
}

void CgiModule::CGIModule(apimeal::IHttpRequest *request, apimeal::Error &error) {

	// On recupere le contenu de notre fichier qu'on va 
	// envoyer a notre module CGI
	std::string body = request->getBody();

	std::string result;
	// TODO: Le module CGI prends en charge le body
	// est le renvoi transformé dans la variable result

	// Si result == "" on concidère qu'il y'a une erreur 404
	if (result == "") {
		error.IsError = true;
		error.Code = 404;
		error.Message = "La page est vide donc introuvable à nos yeux";
		return;
	}


	/** on set le nouveau body
	* EXAMPLE de contenu de la variable result :
	* X-Powered-By: PHP/5.5.3-1ubuntu2.1
	* Cache-Control: no-cache, must-revalidate
	* Content-type: text/html
	* 
	* <html>
	*    <head><title>APIMEAL</title></head>
	*    <body>
	*         <h1>APIMEAL</h1>
	*         <h3>L'api qui vous simplifie la vie</h3>
	*    </body>
	* </html>
	*/
	request->setBody(result);

	// INFO : c'est le kernel du zia qui se charge de parser les headers

	return;
}

extern "C" apimeal::AModule *LoadModule(apimeal::ILogger *log) {
		return new CgiModule(log);
}

