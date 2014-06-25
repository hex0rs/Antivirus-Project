#include "Core/Techniques/Techniques.h"
#include "Core/Shared/Shared.h"
#include "Core/Shared/File.h"
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

if(argc < 2)
{
	printHelp();
	return 0;
}

if( cmp(argv[1],"-h") || cmp(argv[1],"--help") )
{
	printHelp();
}

if( cmp(argv[1],"-v") || cmp(argv[1],"--version")){
	printVersion();
}
if((argv[1],"-cv") || cmp(argv[1],"--check"))
{
	printLatestVersion();
}

if (cmp(argv[1],"-s") || cmp(argv[1],"--scan"))
{
	if(cmp(argv[2],"-f") || cmp(argv[2],"--file"))
	{


	}
	else if(cmp(argv[2],"-d") || cmp(argv[2],"--directory"))
	{

	}
	else
	{
		cout << "[-]Error : file or directory must be specified with -f/--file or -d/--directory";
		return 0;
	}
	if(cmp(argv[2],"-m") || cmp(argv[2],"--file"))
	{

	}


}






else
{
	cout << "Error Parsing passed parameters .. "<<endl;
	cout << "Check again considering parameters proper order .."<<endl;
	printHelp();
	return 0;
}

}
