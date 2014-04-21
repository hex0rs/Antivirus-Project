/*
 * Database.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: Ahmed
 */


#include "Database.h"
#include "Signature.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

Shared::SigDb::Database::Database()
{
	this->Version = "";
	this->Path = "";
	this->UpdateDate = "";
	this->SignaturesNumber=0;
}
Shared::SigDb::Database::Database(char* Path)
{
	this->Path = Path;
	this->Version = "";
	this->UpdateDate = "";
	this->SignaturesNumber=0;

}

int Shared::SigDb::Database::init()
{
		if(!this->Path)
		{
			return -1;
		}
		ifstream dbFile(this->Path,ios::in);
		dbFile.seekg(ios::beg);
		//Header Parsing
		getline(dbFile, this->Version,':');
		getline(dbFile, this->UpdateDate,':');
		getline(dbFile, this->SigNum, ':');
		string x; getline(dbFile, x);
		//Signature list filling
		this->SignaturesNumber = atoi(this->SigNum.c_str());
		this->SignaturesList = new Signature[this->SignaturesNumber];
		for(int i=0; i<this->SignaturesNumber; i++)
		{
			getline(dbFile, (this->SignaturesList[i]).VirusName,':');
			getline(dbFile, (this->SignaturesList[i]).HexSignature, ':');
			this->SignaturesList[i].SigHextoASCII();
			getline(dbFile, x);
		}
		return 0;
}



