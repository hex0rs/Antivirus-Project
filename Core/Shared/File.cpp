/*
 * file.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: Ahmed
 */
#include "Shared.h"
#include "File.h"
#include <iostream>
#include <fstream>


using namespace std;
using namespace Shared;



// Constructors
Shared::Common::File::File()
{

}
Shared::Common::File::File(char* FilePath)
{
	this->FilePath = FilePath;
	this->Process();

}

void Shared::Common::File::Process()
{

	ifstream input_file(this->FilePath, ios::in | ios::binary | ios::ate);
	this->FileSize = input_file.tellg();
	input_file.seekg(0,ios::beg);
	this->BufferSize = this->FileSize;
	this->Buffer = new char[(int)this->FileSize];
	input_file.read(this->Buffer,this->BufferSize);
	input_file.close();
}

void Shared::Common::File::Process(char* FilePath)
{
	this->FilePath = FilePath;
	this->Process();

}

