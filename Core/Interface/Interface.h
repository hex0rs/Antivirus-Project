// Contains core engine interface, this engine scans a file queue and return the result back
#include "../Shared/Shared.h"

using namespace std;

#ifndef Interface_h
#define Interface_h
#endif
class Engine
{
protected:
public:
	//constructors
	Engine();
	//global vars
	bool SCAN_FILE;
	bool SCAN_DIR;

	//functions
	int init();
	int scan();
};
