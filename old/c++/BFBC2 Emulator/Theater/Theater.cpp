// BFBC2 Emulator - Plasma
// Made by Freaky123
// With help from Domo
// � Freaky (Freaky123) 2010-2011

#include "stdafx.h"
#include "CFramework.h"

CFramework* fw;
void serverListener(LPVOID lpParam);
void clientListener(LPVOID lpParam);


int _tmain(int argc, _TCHAR* argv[])
{
	fw		= new CFramework( );

	//Load the config
	fw->config->setFile(".\\theater_config.ini");
	fw->loadConfig();

	//Connect to the database
	fw->database->Connect();

	//Create the server listener
	_beginthread(serverListener, 0, NULL);

	//Create the client socket
	_beginthread(clientListener, 0, NULL);

	//Keep alive
	while(true)
	{

	}
	
	delete fw;

	return 0;
}