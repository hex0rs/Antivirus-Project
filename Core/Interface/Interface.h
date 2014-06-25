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
#include <string.h>
#include <stdio.h>

bool cmp(char* arg, char* opt);

void printHelp();
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
	bool isFile = false;
	bool isDirectory = false;
	int scanMethod;
	scan_result result;
	void scan();


};
class iface_quarantine
{
public:
	void list();
	void add(char* path);
	void restore(int qID);
	void remove(int qID);
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
	int GetLatestVeersion();
	int GetDatabaseCurrentVersion();
	int GetDatabaseLatestVersion();
	int GetQuarantineState();
};

#endif /* INTERFACE_H_ */
