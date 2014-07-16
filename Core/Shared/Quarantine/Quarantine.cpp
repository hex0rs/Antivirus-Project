#include "Quarantine.h"
#include "../../Interface/Interface.h"




using namespace std;
using namespace Shared::Common;



Qdb::Qdb(string QdbPath)
{
	this->QdbPath = (char*)QdbPath.c_str();
}



int Qdb::add(char* path,char* foundVirus,int key)
{
	if (OS::closeProcess(path) == -1)
	{
		cout << "[-] Error closing file"<<endl;
		return -1;
	}
	fstream quarantine(this->QdbPath,ios::ate | ios::in |ios::out | ios::app);
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
	quarantine << endl << lqID  << '|' << new_path << '|' << foundVirus << '|' << key ;
	quarantine.close();
	return 1;
}
int Qdb::restore(int qID)
{
	//find the file record
	fstream quarantine(this->QdbPath, ios::ate | ios::in);
	if (!quarantine.good())
	{
		cout << "[-] Error openning quarantine database" << endl;
		return -1;
	}
	string lastLine = File::getLastLine(&quarantine);
	int lastqID = atoi(lastLine.substr(0, lastLine.find("|")).c_str());
	quarantine.seekg(ios::beg);
	int size = 100; int i;
	string temp; string* records = new string[size]; int curqID=-1; string filerecord;
	for (i = 0; lastqID != curqID; i++)
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
	size = i;
	if (filerecord.length() == 0)
	{
		cout << "[-] Error finding the corresponding file" << endl;
		return -1;
	}
	string key_s, path;
	stringstream stream(filerecord);
	getline(stream, temp, '|'); //get qID
	getline(stream, path, '|'); //get path
	getline(stream, temp, '|'); //get virus name
	getline(stream, key_s);
	int key = atoi(key_s.c_str());
	File::decryptFile((char*)(path.c_str()), key); // decrypt file
	char* path_c = (char*)path.c_str();
	char* new_path = remove_qf(path_c);
	//rename the file
	rename(path_c, new_path);
	//unhide file
	OS::unhideFile(new_path);
	//return the quarantine records back to quarantine file
	quarantine.close();
	ofstream new_quarantine(this->QdbPath, ios::out);
	new_quarantine << records[0];
	for (int i = 1; i < size - 1; i++)
	{
		new_quarantine << endl << records[i];
	}
	new_quarantine.close();
	return 1;
}
int Qdb::remove(int qID)
{
	//find the file record
	fstream quarantine(this->QdbPath, ios::ate | ios::in);
	if (!quarantine.good())
	{
		cout << "[-] Error openning quarantine database" << endl;
		return -1;
	}
	string lastLine = File::getLastLine(&quarantine);
	int lastqID = atoi(lastLine.substr(0, lastLine.find("|")).c_str());
	quarantine.seekg(ios::beg);
	int size = 100; int i;
	string temp; string* records = new string[size]; int curqID = -1; string filerecord;
	for (i = 0; lastqID != curqID; i++)
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
	size = i;
	if (filerecord.length() == 0)
	{
		cout << "[-] Error finding the corresponding file" << endl;
		return -1;
	}
	string path;
	stringstream stream(filerecord);
	getline(stream, temp, '|'); //get qID
	getline(stream, path, '|'); //get path
	const char* path_c = path.c_str();
	//delete file
	OS::deleteFile(path_c);
	//return the quarantine records back to quarantine file
	quarantine.close();
	ofstream new_quarantine(this->QdbPath, ios::out);
	new_quarantine << records[0];
	for (int i = 1; i < size - 1; i++)
	{
		new_quarantine << endl << records[i];
	}
	new_quarantine.close();
	return 1;
}
int Qdb::clear()
{
	fstream quarantine(this->QdbPath, ios::in);
	if (!quarantine.good())
	{
		cout << "[-] Error openning quarantine database" << endl;
		return -1;
	}
	string filerecord; string path; const char* c_path;
	while (!quarantine.eof())
	{
		getline(quarantine, filerecord);
		stringstream stream(filerecord);
		getline(stream, path, '|');//get qID
		getline(stream, path, '|');//get path
		c_path = path.c_str();
		//delete file
		if(OS::closeProcess((char*)c_path) == -1) return -1;
		OS::deleteFile(c_path);
	}
	quarantine.close();
	fstream new_q(this->QdbPath, ios::out | ios::trunc);
	new_q << "ID	|	path	|	Virus Name	|	Encryption Key";
	new_q.close();
	return 1;
}
void Qdb::list()
{
	ifstream quarantine(this->QdbPath, ios::ate);
	if (!quarantine.good())
	{
		cout << "[-] Error openning quarantine database" << endl;
	}
	streamoff size = quarantine.tellg();
	Qfile temp; 
	quarantine.seekg(ios::beg);
	while (!quarantine.eof())
	{
		getline(quarantine, temp.qID ,'|');
		getline(quarantine, temp.path  , '|');
		getline(quarantine, temp.foundVirus , '|');
		getline(quarantine, temp.key);
		Qfile::printQfile(temp);
	}
}

void Qfile::printQfile(Qfile qf)
{
	string name = File::getFileName(qf.path);
	const char* filename = name.c_str();
	cout << "----------------------------------------------------------" << endl;
	cout << "[+] Name	: " << File::removeExt((char*)filename,3) << endl;
	cout << "[+] ID		: " << qf.qID << endl;
	cout << "[+] Path	: " << qf.path << endl;
	cout << "[+] Virus	: " << qf.foundVirus << endl;
	cout << "[+] Key		: " << qf.key << endl;
	cout << "----------------------------------------------------------" << endl;
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

