/*
 * File.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Ahmed
 */
#include "Shared.h"
#include <fstream>
class Shared::Common::File{
protected:

public:
	char* FilePath;
	streamoff FileSize;
	char* Buffer;
	int BufferSize;
	File();
	File(char* FilePath);
	void Process();
	void Process(char* FilePath);

};
