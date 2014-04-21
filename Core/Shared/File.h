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
<<<<<<< HEAD
	int BufferSize;
=======
	streamoff BufferSize;
>>>>>>> 1f930ae55d8650c119252bf39d58b7ad3417eea8
	File();
	File(char* FilePath);
	void Process();
	void Process(char* FilePath);

};
