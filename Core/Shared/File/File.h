/*
 * File.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Ahmed
 */
#ifndef FILE_H
#define FILE_H
#include "../Shared.h"
#include <fstream>
class Shared::Common::File
{
protected:

public:
	char* FilePath;
	streamoff FileSize;
	char* Buffer;
	streamoff BufferSize;
	File();
	File(char* FilePath);
	void Process();
	void Process(char* FilePath);
	static string getFileName(string path);
	static string getLastLine(fstream* file);
	static void printFile(char* path);
	static int encryptFile(char* path, int key);
	static int decryptFile(char* path, int key);
	static char* addExt(char* name, char* ext);
	static char* removeExt(char* name, int len);
};
#endif