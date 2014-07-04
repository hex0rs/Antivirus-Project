#include "Quarantine.h"
#include "../File/File.h"
#ifdef WIN32
#include "../OS/Windows.h"
#else
#include "../OS/Linux.h"
#endif
#include "../File/File.h"
#include "../Shared.h"
#include <time.h>
using namespace std;
using namespace Shared::Common;
using namespace OS;

void Qfile::printQfile(Qfile file)
{
	cout << "[+] File ID : " << file.qID << endl;
	cout << "[+] File Name : " << File::getFileName(file.path) << endl;
	cout << "[+] File Path : " << file.path << endl;
}
Qdb::Qdb()
{
	this->QdbPath = "Quarantine\Quarantine.qdb";
	if (this->init() == -1)
	{
		cerr << "Error Initializing Quarantine.qdb file";
	}
}
Qdb::Qdb(char* Path)
{
	this->QdbPath = Path;
	if (this->init() == -1)
	{
		cerr << "Error Initializing passed qdb file";
	}
}
int Qdb::init()
{
	ifstream qdb(this->QdbPath,ios::in | ios::ate);
	if (!qdb.good())
		return -1;
	else
		return 1;
}

int Qdb::add(char* path,char* foundVirus)
{
	if(closeProcess(path)==-1)
		return -1;
	fstream quarantine(this->QdbPath,ios::ate | ios::out | ios::app);
	if (!quarantine.good())
		return -1;
	//encrypt file

	//add qf extension to path
	char* new_path = new char[strlen(path) + 3];
	strcpy_s(new_path, strlen(path) + 1, path);
	strcat_s(new_path, strlen(path) + 4, ".qf");
	//rename file
	rename(path, new_path);
	//hide file
	hideFile(new_path);
	// add file in qdb
	// parse last entry to get last qID
	string lastline = File::getLastLine(&quarantine);
	string lastqID;
	lastqID = lastline.substr(0,lastline.find("|"));
	int lqID = atoi(lastqID.c_str());
	lqID++;
	quarantine.seekg(0, quarantine.end);
	quarantine << lqID  << '|' << new_path << endl;
	quarantine.close();
	

}
