#include "NDBtoDb.h"
#include <algorithm>
#include <stdio.h>
#include <time.h>
using namespace std;
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

	return buf;
}
void NDBtoDbConverter(char* NDBfile, char* DBfile)
{
	ifstream input_NDBfile(NDBfile,ios::in );
	ofstream output_DBfile(DBfile, ios::out);
	string line; string new_item; int pos = 0; 
	
	__int64 line_count;
	double prog = 0;
	line_count = count(istreambuf_iterator<char>(input_NDBfile), istreambuf_iterator<char>(), '\n');
	string version; cout << "[+] Specify a bmdb database version : "; cin >> version;
	output_DBfile << version << ':' << currentDateTime() << ':' << line_count + 1 << ':' << endl;
	input_NDBfile.clear();
	input_NDBfile.seekg(ios::beg);
	if (input_NDBfile.good())
	{
		while (getline(input_NDBfile, line))
		{
			prog++;
			double perc = (prog / line_count) * 100;
			printf("[+] Progress : %3d %%\r", int(perc));
			stringstream s(line);
			pos = 0;
			while (getline(s, new_item, ':'))
			{
				pos++;
				if (pos == 1)
					output_DBfile << new_item << ':';
				if (pos==2)
				{
					output_DBfile << new_item << ':';
				}
				if (pos == 4)
				{
					for each (char c in new_item)
					{
						if (c == ':' || c == '*' || c == '(' || c == ')' || c == '-' || c == '{' || c == '}' || c == '?')
						{
							output_DBfile << "NULL:" << -1 << endl;
							goto breaking;
						}
					}
					output_DBfile << new_item << ':';
					output_DBfile << new_item.length() / 2 << endl;
				}
			
				if (pos > 4)
				{
					breaking:
					break;
				}
			}
			
		}
		input_NDBfile.close();
		output_DBfile.close();
		cout << endl <<"[+] done !!" << endl;
	}
}
