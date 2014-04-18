#include "NDBtoDb.h"

using namespace std;

void NDBtoDbConverter(char* NDBfile, char* DBfile)
{
	ifstream input_NDBfile(NDBfile,ios::in );
	ofstream output_DBfile(DBfile, ios::out);
	string line; string new_item; int pos = 0; unsigned int line_count;
	input_NDBfile.unsetf(ios_base::skipws);
	line_count = count(istream_iterator<char>(input_NDBfile), istream_iterator<char>(), '\n');

	output_DBfile << "1.1:17 April 2014 11-22:" << line_count+1 << ':' << endl;
	input_NDBfile.clear();
	input_NDBfile.seekg(ios::beg);
	while (getline(input_NDBfile,line))
	{
		stringstream s(line);
		pos = 0;
		while (getline(s, new_item, ':'))
		{
			pos++;
			if (pos == 1 )
				output_DBfile << new_item << ':' ;
			if (pos == 4)
			{
				output_DBfile << new_item <<':' <<endl;
			}
			if (pos > 4)
			{
				break;
			}
		}
		
	} 
	input_NDBfile.close();
	output_DBfile.close();
}