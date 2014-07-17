#ifndef BMH_H
#define BMH_H
#include "../Techniques.h"
#include <iostream>
#include <vector>

#ifndef MAX_ALPHABET
#define MAX_ALPHABET 256
#endif

using namespace Techniques;
class Techniques::Static::BMH {
public:
	static int search(char* pattern, int pattern_size, char* text, int text_size);
};

#endif
