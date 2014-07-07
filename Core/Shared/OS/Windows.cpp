#include "Windows.h"

using namespace Shared::Common;
using namespace std; 


int OS::closeProcess(char* executablePath)
{

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
		if (!strcmp(ProcessEntry.szExeFile, executablePath))
		{
			HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, 0, ProcessEntry.th32ProcessID);
			TerminateProcess(proc, 0);
			CloseHandle(proc);
		}
	}


	while (Process32Next(hProcessSnapShot, &ProcessEntry));
	CloseHandle(hProcessSnapShot);
	return 1;
}
void OS::hideFile(char* path)
{
	SetFileAttributesA(path, FILE_ATTRIBUTE_HIDDEN);
}
void OS::deleteFile(const char* path)
{
	DeleteFileA(path);
}
int OS::downloadFile(char* url, char* path2save)
{
	char* tempPath = File::addExt(path2save, ".backup");
	rename(path2save, tempPath);
	HRESULT result = URLDownloadToFileA(NULL, url, path2save, 0, NULL);
	if (result != S_OK)
	{
		rename(tempPath, path2save);
		return -1;
	}
	else
		return 1;
}
