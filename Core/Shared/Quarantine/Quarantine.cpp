#include "Quarantine.h"
#include "../Shared.h"
#include "../File.h"
#include <stdio.h>
#include <fstream>
#include<iostream>
#ifdef WIN32
#include "../OSWindows.h"
#else
#include "../OSLinux.h"
#endif

using namespace std;
using namespace Shared::Common;

int Quarantine::add(string path) {
	ofstream outFile;
	streampos size;
	char* memblock;
	memblock = File::openFile(path, &size);
	string name = File::getFileName(path);
	outFile.open(("Quarantine/" + name).c_str() , ios_base::binary); // create new file

	for (int i = 0; i < size; i++) {
		memblock[i] = memblock[i] ^ 0x55;

	}

	outFile.write(memblock, size);
	cout<<(int)size;
	OS::closeProcess(name);
	int tries = 0;
	while (std::remove(path.c_str()) == -1) {
		tries++;
		if (tries == 1000) {
			cout << "cant delete the file.\n";
			break;
		}
	}

	//fadel t3mel add lel path fel database 3ashan n3raf nraga3o
	return 0;
}

int Quarantine::remove(string path) {
	string name = File::getFileName(path);
	std::remove(("Quarantine/" + name).c_str());

	//fadel t remove el entry bta3to men el database
	return 0;
}

int Quarantine::restore(string path) {
	ofstream outFile;
	streampos size;
	char* memblock;
	outFile.open(path.c_str() , ios::binary); // create new file
	string name = File::getFileName(path);
	memblock = File::openFile("Quarantine/" + name, &size);
	for (int i = 0; i < size; i++) {
		memblock[i] = memblock[i] ^ 0x55;

	}
	outFile.write(memblock, size);
	OS::closeProcess(name);
	outFile.close();

	return 0;
}


