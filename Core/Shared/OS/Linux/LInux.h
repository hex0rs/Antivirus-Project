
#ifndef WIN32
#ifndef WINDOWS_H
#define WINDOWS_H

class OS
{
public:
	static int closeProcess(char* executablePath);
	static void hideFile(char* path);
	static void unhideFile(char* path);
	static void deleteFile(const char* path);
	static int downloadFile(char* url, char* path2save);
};

#endif
#endif