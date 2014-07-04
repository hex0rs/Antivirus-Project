#include "Quarantine.h"
#include "../File/File.h"
#ifdef WIN32
#include "../OS/Windows.h"
#else
#include "../OS/Linux.h"
#endif
#include "../File/File.h"
#include "../Shared.h"
#include <sstream>
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

int Qdb::add(char* path,char* foundVirus,int key)
{
	if (closeProcess(path) == -1)
	{
		cout << "[-] Error closing file"<<endl;
		return -1;
	}
	fstream quarantine(this->QdbPath,ios::ate | ios::out | ios::app);
	if (!quarantine.good())
	{
		cout << "[-] Error openning quarantine database" << endl;
		return -1;
	}
	//encrypt file
	if (File::encryptFile(path, key) == -1)
	{
		cout << "[-] Error encrypting file, check file path !!" << endl;
		return -1;
	}
	//add qf extension to path
	char* new_path = add_qf(path);
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
		//add qf to qdb
	quarantine.seekg(0, quarantine.end);
	quarantine << lqID  << '|' << new_path << '|' << foundVirus << '|' << key << endl;
	quarantine.close();
	return 1;
}

int Qdb::remove(int qID)
{
	ifstream quarantine(this->QdbPath, ios::ate);
	if (!quarantine.good())
	{
		cout << "[-] Error openning quarantine database" << endl;
		return -1;
	}
	int size = quarantine.tellg();
	quarantine.seekg(ios::beg);
	string temp; string* records = new string[size]; int curqID; string filerecord;
	for (int i = 0; i < size; i++)
	{
		getline(quarantine, temp);
		curqID = atoi((temp.substr(0, temp.find('|'))).c_str());
		if (curqID != qID)
		{
			records[i] = temp;
		}
		else
		{
			filerecord = temp;
		}
	}
	if (filerecord.length() == 0)
	{
		cout << "[-] Error finding the corresponding file" << endl;
		return -1;
	}
	stringstream stream(filerecord);
	getline(stream, temp, '|'); //get qID
	getline(stream, temp, '|'); //get path
	deleteFile(temp.c_str());
	//return the quarantine records back to quarantine file
	quarantine.close();
	ofstream new_quarantine(this->QdbPath, ios::out);
	for (int i = 0; i < size-1; i++)
	{
		new_quarantine << records[i];
	}
	new_quarantine.close();
	return 1;
}
int Qdb::restore(int qID,int key)
{
	//find the file record
	ifstream quarantine(this->QdbPath, ios::ate);
	if (!quarantine.good())
	{
		cout << "[-] Error openning quarantine database" << endl;
		return -1;
	}
	int size = quarantine.tellg();
	quarantine.seekg(ios::beg);
	string temp; string* records = new string[size]; int curqID; string filerecord;
	for (int i = 0; i < size; i++)
	{
		getline(quarantine, temp);
		curqID = atoi((temp.substr(0, temp.find('|'))).c_str());
		if (curqID != qID)
		{
			records[i] = temp;
		}
		else
		{
			filerecord = temp;
		}
	}
	if (filerecord.length() == 0)
	{
		cout << "[-] Error finding the corresponding file" << endl;
		return -1;
	}
	stringstream stream(filerecord);
	getline(stream, temp, '|'); //get qID
	getline(stream, temp, '|'); //get path
	File::decryptFile((char*)(temp.c_str()), key); // decrypt file
	char* new_path = remove_qf((char*)temp.c_str());
	//return the quarantine records back to quarantine file
	quarantine.close();
	ofstream new_quarantine(this->QdbPath, ios::out);
	for (int i = 0; i < size - 1; i++)
	{
		new_quarantine << records[i];
	}
	new_quarantine.close();
	return 1;
}

char* Qdb::add_qf(char* path)
{
	char* new_path = new char[strlen(path) + 3];
	strcpy_s(new_path, strlen(path) + 1, path);
	strcat_s(new_path, strlen(path) + 4, ".qf");
	return new_path;
}
char* Qdb::remove_qf(char* path)
{
	char* new_path = new char[strlen(path) - 2];
	memcpy(new_path, path, strlen(path) - 3);
	new_path[strlen(path) - 3] = '\0';
	return new_path;
}