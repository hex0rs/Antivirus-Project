
#ifndef OSWINDOWS_H
#define OSWINDOWS_H

#include<string>
#include<iostream>
#include<windows.h>
#include<TlHelp32.h>
#include <tchar.h>
#include "../Shared.h"

using namespace std;

namespace OS
{
	int closeProcess(char* executablePath) {

		HANDLE hProcessSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
		if (hProcessSnapShot == INVALID_HANDLE_VALUE)
		{
			cout << "[-] Can't get the processes list" << endl;
			return -1;
		}
		PROCESSENTRY32 ProcessEntry = { 0 };
		ProcessEntry.dwSize = sizeof(ProcessEntry);
		BOOL Return = FALSE;
		Return = Process32First(hProcessSnapShot, &ProcessEntry);
		if (Return == false)

		{
			cout << "[-] Error retrieving info about processes" << endl;
			return -1;
		}
		do {
			if (!strcmp(ProcessEntry.szExeFile, executablePath)) {
				HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessEntry.th32ProcessID);
				TerminateProcess(proc, 0);
				CloseHandle(proc);
			}
		}

		while (Process32Next(hProcessSnapShot, &ProcessEntry));

		CloseHandle(hProcessSnapShot);
		return 1;
	}
	void hideFile(char* path)
	{
		SetFileAttributesA(path, FILE_ATTRIBUTE_HIDDEN);
	}
	void deleteFile(const char* path)
	{
		DeleteFileA(path);
	}
}

#endif /* OS_H_ */
