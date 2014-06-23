#ifndef BMH_H
#define BMH_H
#include "../Techniques.h"
#include <iostream>

#ifndef MAX_ALPHABET
#define MAX_ALPHABET 256
#endif

using namespace Techniques;
class Techniques::Static::BMH {
protected:
	unsigned char BadMatchTable[ MAX_ALPHABET ];
	void create_BadMatchTable(char* pattern, int pattern_size);
public:
	char* pattern;
	char* text;
	int pattern_size;
	int text_size;
	BMH();
	BMH(char* pattern, int pattern_size, char* text, int text_size);
	int search();
	int search(char* pattern, int pattern_size, char* text, int text_size);

};

#endif
