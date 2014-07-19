#include <string>
#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include "../../Shared.h"
#include "../../File/File.h"
#include <dirent.h>
#include <vector>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

#ifndef WINDOWS_H
#define WINDOWS_H

class OS
{
public:
	static int closeProcess(char* executablePath);
	static vector<string> listDirectory(char* path, int* size);
	static void hideFile(char* path);
	static void unhideFile(char* path);
	static void deleteFile(const char* path);
	static int downloadFile(char* url, char* path2save);
};

#endif