/*
 * Interface.h
 *
 *  Created on: Jun 25, 2014
 *      Author: Ahmed Fouda
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Shared/Quarantine/Quarantine.h"
#include "../Techniques/Techniques.h"
#include "../Techniques/BMH/BMH.h"
#include "../Techniques/Aho-Corasick Search/Aho-Corasick.h"
#include "../Shared/SigDb/Database.h"
#ifdef WIN32
#include "../Shared/OS/Windows/Windows.h"
#else
#include "../Shared/OS/Linux.h"
#endif

extern string QuarantinePath;
extern string VersionPath;
extern string VersionURL;
extern  string bmdbPath;
extern  string acdbPath;
extern  string bmdbURL;
extern  string acdbURL;
bool cmp(char* arg, char* opt1, char* opt2);
void initSet();
void printBanner();
void printHelp(char* opt);

class scan_result
{
public:
	bool isInfected;
	char* virusName;
	void printResult();

};

class iface_scan
{
public:
	char* scanMethod;
	int ScanMethodNum;
	void setScanMethod();
	char* path;
	void scan_file();
	void scan_directory();
	int parseFile();
};
class iface_quarantine
{
public:
	static void list();
	static void add(char* path, char* foundVirus, int key);
	static void restore(int qID);
	static void remove(int qID);
	static void clear();
};
class iface_update
{
public:
	static int UpdateCore();
	static int UpdateGUI();
	static int UpdateDbRemotely();
	static int UpdateBMHDBLocally(char* bmdb);
	static int UpdateACDBLocally(char* acdb);

};
class iface_state
{
public:
	static int GetCurrentVersion();
	static int GetLatestVersion();
	static void GetQuarantineState();
};



#endif /* INTERFACE_H_ */
