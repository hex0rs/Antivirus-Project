/*
 * BMH.cpp
 *
 *  Created on: Apr 13, 2014
 *      Author: Ahmed
 */
#include "BMH.h"

using namespace std;
using namespace Techniques::Static;

int  Techniques::Static::BMH::search(char* pattern, int pattern_size, char* text, int text_size)
{
	//creating bad match table
	vector<unsigned char> BadMatchTable;
	int pattern_length = pattern_size;
	BadMatchTable.assign(256, pattern_length);
	for (int i = 0; i < pattern_length - 1; i++)
	{
		BadMatchTable[(unsigned char)pattern[i]] = pattern_length - 1 - i;
	}
	int text_length = text_size;
	int scan_pos = 0;
	int pat_pos = pattern_length - 1;
	while(text_length >= pattern_length)
	{
		pat_pos = pattern_length - 1;
		for(scan_pos = pat_pos; (unsigned char)text[scan_pos] == (unsigned char)pattern[pat_pos] ; scan_pos--,pat_pos--)
		{
			if(pat_pos == 0)
			{
				return (text_size - text_length);
			}
		}
		text_length -= BadMatchTable[(unsigned char)text[scan_pos]];
		text += BadMatchTable[(unsigned char)text[scan_pos]];
	}
	return -1;
}





