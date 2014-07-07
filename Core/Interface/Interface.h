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
#include "../Shared/OS/Windows.h"
#else
#include "../Shared/OS/Linux.h"
#endif

#define QuarantinePath "Quarantine/quarantine.qdb"
#define VersionPath "Version"
#define VersionURL ""
#define bmdbPath ""
#define acdbPath ""
#define bmdbURL ""
#define acdbURL ""
bool cmp(char* arg, char* opt1, char* opt2);

void printBanner();
void printHelp(char* opt);

class scan_result
{
public:
	bool isInfected;
	char* virusName;
	static void printResult(scan_result result);

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


};
class iface_quarantine
{
public:
	static void list();
	static void add(char* path, char* foundVirus="UNKNOWN", int key=1);
	static void restore(int qID, int key=1);
	static void remove(int qID);
};
class iface_update
{
public:
	static int UpdateVersion();
	static int UpdateDatabaseRemotely();
	static int UpdateDatabaseLocally(char* db);

};
class iface_state
{
public:
	static int GetCurrentVersion();
	static int GetLatestVersion();
	static int GetQuarantineState();
};

#endif /* INTERFACE_H_ */
