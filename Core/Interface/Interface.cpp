/*
 * Interface.cpp
 *
 *  Created on: Jun 25, 2014
 *      Author: Ahmed Fouda
 */
#include "Interface.h"

using namespace std;

bool cmp(char* arg,char* opt)
{
	if(strcmp(arg,opt)== 0)
		return true;
	else
		return false;
}

void printHelp()
{
	ifstream f("help.txt");
	string line;
	while(getline(f,line))
		cout << line<<endl;;
}

void printVersion()
{
	cout << "test version ";
}

void printLatestVersion()
{

}

