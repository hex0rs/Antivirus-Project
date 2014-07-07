#ifndef QUARANTINE_H
#define QUARANTINE_H
#include <string>
#include <iostream>
#include <fstream>
#include "../File/File.h"
#include "../Shared.h"
#include <sstream>
#ifdef WIN32
#include "../OS/Windows.h"
#else
#include "../OS/Linux.h"
#endif
class Qfile
{
public:
	string qID;
	string path;
	string foundVirus;
	string key;
	static void printQfile(Qfile qfile);
};


class Qdb
{
public:
	Qdb();
	Qdb(char* QdbPath);
	char* QdbPath;
	int init();
	int add(char* path,char* foundVirus="UNKNOWN",int key=1);
	int restore(int qID,int key=1);
	int remove(int qID);
	void list();
	static char* add_qf(char* path);
	static char* remove_qf(char* path);
};


#endif // !QUARANTINE_H
