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
if( cmp(argv[1],"h","help") )
{
	printHelp(argv[2]);
}

else if( cmp(argv[1],"v","version"))
{
	if (iface_state::GetCurrentVersion() == -1)
	{
		cout << "[-] Error finding current version file" << endl;
	}
}
else if(cmp(argv[1],"cv","check"))
{
	cout << "[+] Downloading the latest Version File . . . " << endl;
	if (iface_state::GetLatestVersion() == -1)
	{
		cout << "[-] Error finding latest version file" << endl;
	}
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
else if (cmp(argv[1], "q", "quarantine") && argc > 2 && argc < 10)
{
	if (cmp(argv[2], "l", "list"))
	{
		iface_quarantine::list();
	}
	else if (cmp(argv[2], "a", "add"))
	{
		int key = 0; char* foundVirus = "UNKNOWN";
		if (cmp(argv[4], "e", "encryption"))
		{
			if (cmp(argv[5], "k", "key"))

			{
				key = atoi(argv[6]);
			}
			else
			{
				cout << "[-] Invalid encryption option !!" << endl;
				printHelp("quarantine");
			}
			if (cmp(argv[7], "fv", "found-virus"))
			{
				foundVirus = argv[8];
			}
		}
		else if (cmp(argv[4], "fv", "found-virus"))
		{
			foundVirus = argv[5];
			if (cmp(argv[6], "e", "encryption"))
			{
				if (cmp(argv[7], "k", "key"))

				{
					key = atoi(argv[6]);
				}
				else
				{
					cout << "[-] Invalid encryption option !!" << endl;
					printHelp("quarantine");
				}
			}
		}
		
			iface_quarantine::add(argv[3],foundVirus,key);
	}
	else if (cmp(argv[2], "d", "delete"))
	{
		iface_quarantine::remove(atoi(argv[3]));
	}
	else if (cmp(argv[2],"r","restore"))
	{
		iface_quarantine::restore(atoi(argv[3]));
	}
	else if (cmp(argv[2], "c", "clear"))
	{
		iface_quarantine::clear();
	}
	else
	{
		cout << "[-] Undefined Quarantine switches !! " << endl;
		printHelp("quarantine");
	}
}
else if (cmp(argv[1],"u","update") && (argc==3 || argc==4 || argc ==5))
{
	if (cmp(argv[2], "c", "core"))
	{
		if (iface_update::UpdateCore()==-1)
		{
			cout << "[-] Error Updating core from arma server, check connection status !" << endl;
		}
		else
			cout << "[+] Core Updated successfully !!" << endl;
	}
	else if (cmp(argv[2], "g", "gui"))
	{
		if (iface_update::UpdateGUI() == -1)
		{
			cout << "[-] Error Updating GUI from arma server, check connection status !" << endl;
		}
		else
			cout << "[+] GUI Updated successfully !!" << endl;
	}
	else if (cmp(argv[2], "d", "database"))
	{
		if (cmp(argv[3], "r", "remotely"))
		{
			iface_update::UpdateDbRemotely();
		}
		else if (cmp(argv[3], "l", "locally"))
		{
			if (cmp(argv[4],"b","bmdb"))
			{
				iface_update::UpdateBMHDBLocally(argv[5]);
			}
			if (cmp(argv[4], "a", "acdb"))
			{
				iface_update::UpdateACDBLocally(argv[5]);
			}

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
	cout << "[-] Error Parsing the given switches .. "<<endl;
	cout << "[-] Check again considering switches in proper order .."<<endl;
	printHelp("xx");
}


cin.ignore();
}
