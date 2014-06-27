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


bool cmp(char* arg, char* opt1, char* opt2);

void printBanner();
void printHelp(char* opt);
void printVersion();
void printLatestVersion();

class scan_result
{
public:
	bool isInfected;
	char* virusName;

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
	static void add(char* path);
	static void restore(int qID);
	static void remove(int qID);
};
class iface_update
{
public:
	int UpdateCore();
	int UpdateDatabaseRemotely();
	int UpdateDatabaseLocally(char* db);

};
class iface_state
{
public:
	int GetCurrentVersion();
	int GetLatestVersion();
	int GetDatabaseCurrentVersion();
	int GetDatabaseLatestVersion();
	int GetQuarantineState();
};

#endif /* INTERFACE_H_ */
