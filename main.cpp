#include "Core/Techniques/Techniques.h"
#include "Core/Shared/Shared.h"
#include "Core/Shared/File.h"
#include "Core/Shared/Database/Database.h"
#include <string>

using namespace std;
using namespace Techniques::Static;
using namespace Shared::Common;
using namespace Shared::SigDb;
int main(int argc, char** argv)
{
	// trying BMH Scanning Algorithim
	cout << "-------------------" << endl<< "Searching 'This' in test.exe " <<endl << "-------------------" << endl;
	File x("test.exe");
	x.Process();
	BMH y("This",4,x.Buffer,x.BufferSize);
	int r = y.search();
	cout<<"Found in offset : "<<r<<endl;
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
	return 0;
}
