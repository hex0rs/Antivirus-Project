// Interface for database management classes weather these databases are local or remote
#include "../Shared.h"
#include "Signature.h"
#include <vector>

using namespace std;

#ifndef Database_H
#define Database_H

class Shared::SigDb::Database
{
protected:
	string  SigNum;

public:
	char* Path;
	string Version;
	string UpdateDate;
	int  SignaturesNumber;
	Signature* SignaturesList;
	//constructors
	Database();
	Database(char* Path);
	//functions
	int init();

};
#endif
