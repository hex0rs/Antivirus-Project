#ifndef QUARANTINE_H
#define QUARANTINE_H
#include <string>
#include <iostream>
#include <fstream>
class Qfile
{
public:
	int qID;
	char* path;
	static void printQfile(Qfile Qfile);

};


class Qdb
{
public:
	Qdb();
	Qdb(char* QdbPath);
	char* QdbPath;
	int init();
	int add(char* path,char* foundVirus);
	int restore(int qID);
	int remove(int qID);
	void list();
};


#endif // !QUARANTINE_H
