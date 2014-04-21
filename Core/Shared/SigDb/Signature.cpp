/*
 * Signature.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: Ahmed
 */
#include "Signature.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Shared::SigDb::Signature::Signature()
{
}

Shared::SigDb::Signature::Signature(char* HexSignature)
{
	this->HexSignature = HexSignature;
}

int Shared::SigDb::Signature::SigHextoASCII()
{
	if(this->HexSignature != "")
	{
	char* ASCII_Sig_Beg = this->AsciiSignature;
	int len = this->HexSignature.length()/2;
	const char *c = this->HexSignature.c_str();
	unsigned int x;
	 while(len > 0)
	 {
		sscanf(c, "%2X", &x);
		*(this->AsciiSignature) = (unsigned char)x;
		this->AsciiSignature++;
	    c += 2;
		len--;
	}
	this->AsciiSignature= ASCII_Sig_Beg;
	return 0;
	}
	else
	{
		return -1;
	}
}

int Shared::SigDb::Signature::SigHextoASCII(char* HexSignature)
{
	this->HexSignature = HexSignature;
	return this->SigHextoASCII();
}




