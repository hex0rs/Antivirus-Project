#include "Quarantine.h"
#include "../../Interface/Interface.h"




using namespace std;
using namespace Shared::Common;



void Qfile::printQfile(Qfile qf)
{
	cout << "----------------------------------------------------------" << endl;
	cout << "[+] Name : " << Qdb::remove_qf((char*)File::getFileName(qf.path).c_str()) << endl;
	cout << "[+] ID : " << qf.qID << endl;
	cout << "[+] Path : " << qf.path << endl;
	cout << "[+] Virus : " << qf.foundVirus << endl;
	cout << "[+] Key : " << qf.key << endl;
	cout << "----------------------------------------------------------" << endl;
}

Qdb::Qdb()
{
	this->QdbPath = QuarantinePath;
	if (this->init() == -1)
	{
		cout << "[-] Error Initializing Quarantine.qdb file" << endl;
	}
}
Qdb::Qdb(char* Path)
{
	this->QdbPath = Path;
	if (this->init() == -1)
	{
		cout << "[-] Error Initializing passed qdb file" << endl;
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
	if (OS::closeProcess(path) == -1)
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
	OS::hideFile(new_path);
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
	OS::deleteFile(temp.c_str());
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
void Qdb::list()
{
	ifstream quarantine(this->QdbPath, ios::ate);
	if (!quarantine.good())
	{
		cout << "[-] Error openning quarantine database" << endl;
	}
	int size = quarantine.tellg();
	Qfile temp; string garb;
	quarantine.seekg(ios::beg);
	while (!quarantine.eof())
	{
		getline(quarantine, temp.qID ,'|');
		getline(quarantine, temp.path  , '|');
		getline(quarantine, temp.foundVirus , '|');
		getline(quarantine, temp.key, '|');
		getline(quarantine, garb);
		Qfile::printQfile(temp);
	}
}

char* Qdb::add_qf(char* path)
{
	char* new_path = File::addExt(path, ".qf");
	return new_path;
}
char* Qdb::remove_qf(char* path)
{
	char* new_path = File::removeExt(path,3);
	return new_path;
}

