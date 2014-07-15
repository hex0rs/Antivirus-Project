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
public:
	//public variables
	char* FilePath; //path of the file
	streamoff FileSize; //size of the file
	char* Buffer; //pointer to the beginning of the file buffer in memory
	streamoff BufferSize; //size of the buffer in memory
	//constructors
	File(); //normal constructor
	File(char* FilePath); //constructor with file path
	//functions
	void Process(); //process function to process the file filling the public variables
	//static functions 
	static string getFileName(string path); //get the file name from a path
	static string getLastLine(fstream* file); //get the last line from a fstream object
	static void printFile(char* path); //print the contents of a file
	static int encryptFile(char* path, int key); //encrypt a file with a key
	static int decryptFile(char* path, int key); //decrypt a file with a key
	static char* addExt(char* name, char* ext); //add extension to file path
	static char* removeExt(char* name, int len); //remove extension from file path
	static string getExt(char* path); //get extension of a file path
};
#endif