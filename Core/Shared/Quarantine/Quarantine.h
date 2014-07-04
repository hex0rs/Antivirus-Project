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
	char* foundVirus;
	int key;
	static void printQfile(Qfile Qfile);

};


class Qdb
{
	char* add_qf(char* path);
	char* remove_qf(char* path);

public:
	Qdb();
	Qdb(char* QdbPath);
	char* QdbPath;
	int init();
	int add(char* path,char* foundVirus="UNKNOWN",int key=1);
	int restore(int qID,int key=1);
	int remove(int qID);
	void list();
};


#endif // !QUARANTINE_H
