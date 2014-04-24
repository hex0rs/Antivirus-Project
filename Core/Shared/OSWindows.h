/*
 * OS.h
 *
 *  Created on: Apr 18, 2014
 *      Author: abd-el-rahman
 */
#include<string>
#include<iostream>
#include<windows.h>
#include<TlHelp32.h>
#include <tchar.h>

#ifndef OS_H_
#define OS_H_
using namespace std;

namespace OS {

void closeProcess(std::string executablePath) {

	HANDLE hProcessSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32 ProcessEntry = { 0 };
	ProcessEntry.dwSize = sizeof(ProcessEntry);
	BOOL Return = FALSE;
	Return = Process32First(hProcessSnapShot, &ProcessEntry);
	if(Return == false)
		return ;
	do {
		if (!strcmp(ProcessEntry.szExeFile, executablePath.c_str())) {
			cout << "Found running";
			HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS,0,ProcessEntry.th32ProcessID);
			TerminateProcess(proc,0);
			CloseHandle(proc);
		}
	}

	while (Process32Next(hProcessSnapShot, &ProcessEntry));

	CloseHandle(hProcessSnapShot);
}
}

#endif /* OS_H_ */
