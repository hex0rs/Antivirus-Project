// contains classes of different techniques used in scanning
#ifndef TECHNIQUES_H
#define TECHNIQUES_H

#include <iostream>
#ifndef MAX_ALPHABET
#define MAX_ALPHABET 256
#endif


namespace Techniques {

namespace Static {
	class BMH;
	class AhoCorasick;
}

namespace Dynamic {}

}

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
