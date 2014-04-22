#include "Core/Techniques/Techniques.h"
#include "Core/Shared/Shared.h"
#include "Core/Shared/File.h"
<<<<<<< HEAD
#include "Core/Shared/Database/Database.h"
#include <string>

=======
#include "Core/Shared/SigDb/Database.h"
#include "Core\tools\NDBtoDB Converter\NDBtoDb.h"
#include <string>


>>>>>>> 1f930ae55d8650c119252bf39d58b7ad3417eea8
using namespace std;
using namespace Techniques::Static;
using namespace Shared::Common;
using namespace Shared::SigDb;
<<<<<<< HEAD
int main(int argc, char** argv)
{
	// trying BMH Scanning Algorithim
=======
int main()
{
/*
//testing BMH Scanning Algorithim
>>>>>>> 1f930ae55d8650c119252bf39d58b7ad3417eea8
	cout << "-------------------" << endl<< "Searching 'This' in test.exe " <<endl << "-------------------" << endl;
	File x("test.exe");
	x.Process();
	BMH y("This",4,x.Buffer,x.BufferSize);
	int r = y.search();
	cout<<"Found in offset : "<<r<<endl;
<<<<<<< HEAD
	Database d("Databases\\db.db");
	d.init();
	cout << endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << "Reading Signature Database from :" << d.Path << endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	for (int i = 0; i < d.SignaturesNumber;i++)
	{
		cout << endl <<"Virus Name : " << d.SignaturesList[i].VirusName << endl;
		cout << "Hex Signature : " << d.SignaturesList[i].HexSignature << endl;
		cout <<"ASCII Signature : " << d.SignaturesList[i].AsciiSignature << endl;
		cout << endl <<"- - - - - - - - - - - - - -" << endl;
	}
	cin.ignore();
=======
*/

	
 //testing NDB database converter
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Converting Main.ndb to db ..." << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	NDBtoDbConverter("Databases\\NDB.ndb", "Databases\\test.db");
	cout << "Converting is Done ... !!" << endl;

	
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
>>>>>>> 1f930ae55d8650c119252bf39d58b7ad3417eea8
	return 0;
}
