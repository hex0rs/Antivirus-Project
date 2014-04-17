/*
 * BMH.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: Ahmed
 */
#include "Techniques.h"


using namespace std;
using namespace Techniques::Static;




// Constructor Definition

Techniques::Static::BMH::BMH()
{

}

Techniques::Static::BMH::BMH(char* pattern, int pattern_size, char* text, int text_size)
{
	this->pattern = pattern;
	this->pattern_size = pattern_size;
	this->text = text;
	this->text_size = text_size;

}

void Techniques::Static::BMH::create_BadMatchTable(char *pattern,int PatternSize)
{
	int pattern_length = PatternSize;
	for(int i=0;i<MAX_ALPHABET;i++)
	{
		this->BadMatchTable[i] =  pattern_length;
	}
	for(int i = 0; i < pattern_length - 1; i++)
	{
		this->BadMatchTable[pattern[i]] = pattern_length - 1 - i;
	}
}

int  Techniques::Static::BMH::search(char *text,int TextSize, char *pattern,int PatternSize)
{

	create_BadMatchTable(pattern,PatternSize);
	int pattern_length = PatternSize;
	int text_length = TextSize;
	int scan_pos = 0;
	int pat_pos = pattern_length - 1;
	while(text_length >= pattern_length)
	{
		pat_pos = pattern_length - 1;
		for(scan_pos = pat_pos; (unsigned char)text[scan_pos] == (unsigned char)pattern[pat_pos] ; scan_pos--,pat_pos--)
		{
			if(pat_pos == 0)
			{
				return (TextSize - text_length);
			}
		}
		text_length -= this->BadMatchTable[(unsigned char)text[scan_pos]];
		text += this->BadMatchTable[(unsigned char)text[scan_pos]];
	}

	return -1;
}

int Techniques::Static::BMH::search()
{
	return Techniques::Static::BMH::search(this->text, this->text_size, this->pattern, this->pattern_size);
}



