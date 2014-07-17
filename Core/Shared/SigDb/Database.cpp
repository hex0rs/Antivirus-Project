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
			cout << "[-] Error locating bmdb database !!" << endl;
			return -1;
		}
		cout << "[+] Intializing BMDB . . ."<< endl; 
		double perc = 0;
		ifstream dbFile(this->Path,ios::in);
		if (!dbFile.good())
			return -1;
		dbFile.seekg(ios::beg);
		//Header Parsing
		getline(dbFile, this->Version,':');
		getline(dbFile, this->UpdateDate,':');
		getline(dbFile, this->SigNum, ':');
		string x; getline(dbFile, x);
		//Signature list filling
		this->SignaturesNumber = atoi(this->SigNum.c_str());
		for(int i=0; i<this->SignaturesNumber; i++)
		{
			
			printf("[+] Progress : %2d %% || %d signatures loaded\r", i * 100 / (this->SignaturesNumber)+1,i);
			getline(dbFile, (this->SignaturesList[i]).VirusName,':');
			getline(dbFile, (this->SignaturesList[i]).SignatureType, ':');
			getline(dbFile, (this->SignaturesList[i]).HexSignature, ':'); 
			getline(dbFile, x);
			(this->SignaturesList[i]).SignatureSize = stoi(x);
			this->SignaturesList[i].SigHextoASCII();
		}
		cout << endl << "[+] BMDB Intailization finished successfully !!" << endl;
		return 0;
}



