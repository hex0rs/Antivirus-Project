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
	if (!input_file.good())
	{
		cout << "[-] Error processing the input file" << endl;
		return;
	}
	this->FileSize = input_file.tellg();
	input_file.seekg(0,ios::beg);
	this->BufferSize = this->FileSize;
	this->Buffer = new char[(int)this->FileSize];
	input_file.read(this->Buffer,this->BufferSize);
	input_file.close();
}



void Shared::Common::File::printFile(char* path)
{
	ifstream f(path);
	string line;
	while (getline(f, line))
		cout << line << endl;
}

string Shared::Common::File::getFileName(string path)
{
	string temp = "";
	for (int i = path.length(); i > -1; i--)
	{
		if (path[i] != '\\' && path[i] != '/') 
			temp = &path[i];
		else
			break;
	}
	return temp;
}

string Shared::Common::File::getLastLine(fstream* file)
{
	string lastline;
	file->seekg(0, file->end);
	int length = (int)file->tellg();
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
	if (key == 0)	return 1;
	FILE* f;
	fopen_s(&f, path, "rb+");
	if (f == NULL)
		return -1;
	fseek(f, 0, SEEK_END);
	long size = 1000; char c = 'a';
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
	if (key == 0)	return 1;
	FILE* f;
	fopen_s(&f, path, "rb+");
	if (f == NULL)
		return -1;
	fseek(f, 0, SEEK_END);
	long size = 1000; char c = 'a';
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
char* Shared::Common::File::addExt(char* name, char* ext)
{
	char* new_path = new char[strlen(name) + strlen(ext)];
	strcpy_s(new_path, strlen(name) + 1, name);
	strcat_s(new_path, strlen(name) + strlen(ext) + 1, ext);
	return new_path;
}
char* Shared::Common::File::removeExt(char* name, int len)
{
	char* new_path = new char[strlen(name) - len -1];
	memcpy(new_path, name, strlen(name) - len);
	new_path[strlen(name) - len] = '\0';
	return new_path;
}
string Shared::Common::File::getExt(char* path)
{
	string ext = "";
	string temp = "";
	for (int i = strlen(path)-1; i > 0 ; i--)
	{
		if (path[i] != '.')
		{
			temp = path[i];
			ext.append(temp);
		}
		else
			break;
	}
	return ext;
}