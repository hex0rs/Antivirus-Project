#include "Core/Techniques/Techniques.h"
#include "Core/Shared/Shared.h"
#include "Core/Shared/File/File.h"
#include "Core/Shared/SigDb/Database.h"
#include "Core\tools\NDBtoDB Converter\NDBtoDb.h"
#include "Core/Interface/Interface.h"


using namespace std;
using namespace Techniques::Static;
using namespace Shared::Common;
using namespace Shared::SigDb;



int main(int argc, char* argv[])
{
/*
// testing BMH Scanning Algorithim
	cout << "-------------------" << endl<< "Searching 'This' in test.exe " <<endl << "-------------------" << endl;
	File x("test.exe");
	x.Process();
	BMH y("This",4,x.Buffer,x.BufferSize);
	int r = y.search();
	cout<<"Found in offset : "<<r<<endl;

*/
	
/*
// testing NDB database converter
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Converting Main.ndb to db ..." << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	NDBtoDbConverter("Databases\\NDB.ndb", "Databases\\test.db");
	cout << "Converting is Done ... !!" << endl;*/

/*
	
// testing database loading and initializing
	Database d("Databases\\test.db");
	d.init();

	cout << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Reading Signature Database from : " << d.Path << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	for (int i = 0; i < d.SignaturesNumber; i++)
	{
		cout << "Virus Name : " << d.SignaturesList[i].VirusName << endl;
		cout << "Hex Signature : " << d.SignaturesList[i].HexSignature << endl;
		cout << "ASCII Signature : " << d.SignaturesList[i].AsciiSignature << endl;
		cout << "---------------------------------------------------------------------------" << endl;
	}
	cout << "Database Loading Done ... !!" ; cin.ignore();
*/

/*
// testing aho-corasick algorithim
	cout << endl;
	AhoCorasick test();*/

	printBanner();
// parsing the classic way
if(argc < 2)
{
	printHelp("all");
	return 0;
}
//parsing the new way
//for(int i=0;i<argc;i++)
	//cout << argv[i] <<endl;

if( cmp(argv[1],"h","help") )
{
	printHelp(argv[2]);
}

else if( cmp(argv[1],"v","version"))
{
	iface_state::GetCurrentVersion();
}
else if(cmp(argv[1],"cv","check"))
{
	iface_state::GetLatestVersion();
}
else if (cmp(argv[1],"s","scan") && argc == 6)
{
	iface_scan* scan = new iface_scan();
	if(cmp(argv[2],"f","file"))
	{
		scan->path = argv[3];
		if(cmp(argv[4],"m","method"))
		{
			scan->scanMethod = argv[5];
			scan->setScanMethod();
			if (scan->ScanMethodNum < 0)
				scan->scan_file();
			else
				cout << "[-] Invalid method !! use [bmh / ac / both] !!"<<endl;
		}
		else
		{
			cout << "[-] Use -m / --method switch to specify scanning method "<<endl;
			cout << "Supported methods : [bmh / ac / both]"<<endl;
		}
	}
	else if(cmp(argv[2],"d","directory"))
	{
		scan->path = argv[3];
		if(cmp(argv[4],"m","method"))
		{
			scan->scanMethod = argv[5];
			scan->setScanMethod();
			if (scan->ScanMethodNum < 0)
				scan->scan_directory();
			else
				cout << "[-] Invalid method !! use [bmh / ac / both] !!"<<endl;
		}
		else
		{
			cout << "[-] Use -m / --method switch to specify scanning method "<<endl;
			cout << "Supported methods : [bmh / ac / both]"<<endl;
		}
	}
	else if(cmp(argv[2],"m","method"))
	{
		scan->scanMethod = argv[3];
		scan->setScanMethod();
		if (scan->ScanMethodNum < 0)
			{
				cout << "[-] Invalid method !! use [bmh / ac / both] !!"<<endl;
			}
		else if(cmp(argv[4],"f","file"))
		{
			scan->path = argv[5];
			scan->scan_file();
		}
		else if(cmp(argv[4],"d","directory"))
		{
			scan->path = argv[5];
			scan->scan_directory();
		}
	}
	else
	{
		cout << "[-] Undefined Scanning switches !!"<<endl;
		printHelp("scan");
	}
	delete scan;
}
else if (cmp(argv[1], "q", "quarantine") && (argc == 3 || argc == 4 ))
{
	iface_quarantine q;
	if (cmp(argv[2], "l", "list"))
	{
		q.list();
	}
	else if (cmp(argv[2], "a", "add"))
	{
		q.add(argv[3]);
	}
	else if (cmp(argv[2], "d", "delete"))
	{
		q.remove(atoi(argv[3]));
	}
	else if (cmp(argv[2],"r","restore"))
	{
		q.restore(atoi(argv[3]));
	}
	else
	{
		cout << "[-] Undefined Quarantine switches !! " << endl;
		printHelp("quarantine");
	}
}
else if (cmp(argv[1],"u","update") && (argc==3 || argc==4 || argc ==5))
{
	iface_update u;
	if (cmp(argv[2], "v", "version"))
	{
		u.UpdateVersion();
	}
	else if (cmp(argv[2], "d", "database"))
	{
		if (cmp(argv[3], "r", "remotely"))
		{
			u.UpdateDatabaseRemotely();
		}
		else if (cmp(argv[3], "l", "locally"))
		{
			u.UpdateDatabaseLocally(argv[4]);
		}
		else
		{
			cout << "[-] Undefined Database Updating switches !!" << endl;
			cout << "[-] Either use -r to update from arma server " << endl;
			cout << "[-] OR -l [db path] to update from local db file" << endl;
		}
	}
	else
	{
		cout << "[-] Undefined Update switches !!" << endl;
		printHelp("update");
	}
}

else
{
	cout << "[-]Error Parsing the given switches .. "<<endl;
	cout << "[-]Check again considering switches in proper order .."<<endl;
	printHelp("xx");
}


cin.ignore();
}
