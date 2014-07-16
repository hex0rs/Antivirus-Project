/*
 * Signature.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Ahmed
 */
#include "../Shared.h"
#include <vector>

using namespace std;

#ifndef Signature_H
#define Signature_H
class Shared::SigDb::Signature
{
public:
	string VirusName;
	string HexSignature;
	int SignatureSize;
	string SignatureType;
	char* AsciiSignature;
	//constructors
	Signature();
	Signature(char* HexSignature);
	//Processing
	int SigHextoASCII();
	int SigHextoASCII(char* HexSignature);
};
#endif
