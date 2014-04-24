//contains shared libraries / tools to be used directly between other code / source files
#include <iostream>

using namespace std;

#define RETURN_SUCCESS 0
#define RETURN_FAIL 1

#ifndef Shared_H
#define Shared_H
namespace Shared
{
	namespace Common
	{
		class File;
		class Quarantine;
	}
	namespace SigDb
	{
		class Database;
		class Signature;
	}
	namespace Connections
	{

	}

}
#endif
