/*
 * file.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: Ahmed
 */
#include "../Shared.h"
#include "File.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
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
char* Shared::Common::File::openFile(string path,streampos* size)
{
	return "";
}
string Shared::Common::File::getFileName(string path) {

	string temp = "";
	string reversed = "";
	for (int i = path.length(); i > -1; i--) {
		if (path[i] != '\\' && path[i] != '/') {
			temp += path[i];
		} else
			break;
	}

	for (int i = temp.length() - 1; i > -1; i--)
		reversed += temp[i];

	return reversed;
}

string Shared::Common::File::getLastLine(fstream* file)
{
	string lastline;
	file->seekg(0, file->end);
	int length = file->tellg();
	file->seekg(0, file->beg);
	char c = ' ';
	for (int i = length - 2; i > 0; i--)
	{
		file->seekg(i);
		c = file->get();
		if (c == '\r' || c == '\n')
			break;
	}
	getline(*file, lastline);
	return lastline;
}
int Shared::Common::File::encryptFile(char* path,int key)
{
	FILE* f;
	fopen_s(&f, path, "rb+");
	if (f == NULL)
		return -1;
	fseek(f, 0, SEEK_END);
	long size = ftell(f); char c = 'a';
	rewind(f);
	for (long i = 0; i < size; i++)
	{
		fseek(f, i, SEEK_SET);
		c = fgetc(f); c+=key;
		fseek(f, i, SEEK_SET);
		fputc(c, f);
	}
	fclose(f);
	return 1;
}
int Shared::Common::File::decryptFile(char* path,int key)
{
	FILE* f;
	fopen_s(&f, path, "rb+");
	if (f == NULL)
		return -1;
	fseek(f, 0, SEEK_END);
	long size = ftell(f); char c = 'a';
	rewind(f);
	for (long i = 0; i < size; i++)
	{
		fseek(f, i, SEEK_SET);
		c = fgetc(f); c-=key;
		fseek(f, i, SEEK_SET);
		fputc(c, f);
	}
	fclose(f);
	return 1;
}