/*
 * Interface.cpp
 *
 *  Created on: Jun 25, 2014
 *      Author: Ahmed Fouda
 */
#include "Interface.h"


using namespace std;
using namespace Shared::Common;
using namespace Techniques::Static;
using namespace Shared::SigDb;
void initSet()
{
	fstream settings("Settings", ios::in | ios::beg);
	string tep;
	if (!settings.good())
	{
		cout << "[-] Error intializing the settings file !!" << endl;
	}
	int i = 0; 
	while (!settings.eof())
	{
		if (i == 0)
		{
			getline(settings, QuarantinePath);
		}
		else if (i == 1)
		{
			getline(settings, VersionPath);
		}
		else if (i == 2)
		{
			getline(settings, VersionURL);
		}
		else if (i == 3)
		{
			getline(settings, bmdbPath);
		}
		else if (i == 4)
		{
			getline(settings, bmdbURL);
		}
		else if (i == 5)
		{
			getline(settings, acdbPath);
		}
		else if (i == 6)
		{
			getline(settings, acdbURL);
		}
		else
			break;
		i++;
	}
}
bool cmp(char* arg, char* opt1, char* opt2)
{
	if (arg == NULL)
		return false;
	char* op1 = new char(strlen(opt1)+2);
	strcpy_s(op1 ,2, "-");
	char* op2 = new char(strlen(opt2)+3);
	strcpy_s(op2 ,3, "--");
	strcat_s(op1, strlen(op1) + strlen(opt1) + 1, opt1);
	strcat_s(op2, strlen(op2) + strlen(opt2) + 1, opt2);
	if(strcmp(arg,op1)== 0 || strcmp(arg,op2) == 0)
		return true;
	else
		return false;
}
//printing functions
void printBanner()
{
	string* banners = new string[10];
	banners[0] = R"(                                               
   __ _ _ __ _ __ ___   __ _ ______ __ ___   __
  / _` | '__| '_ ` _ \ / _` |______/ _` \ \ / /
 | (_| | |  | | | | | | (_| |     | (_| |\ V / 
  \__,_|_|  |_| |_| |_|\__,_|      \__,_| \_/  
)";
	banners[1] = R"(                                                                        
                                                                        
  /$$$$$$   /$$$$$$  /$$$$$$/$$$$   /$$$$$$          /$$$$$$  /$$    /$$
 |____  $$ /$$__  $$| $$_  $$_  $$ |____  $$ /$$$$$$|____  $$|  $$  /$$/
  /$$$$$$$| $$  \__/| $$ \ $$ \ $$  /$$$$$$$|______/ /$$$$$$$ \  $$/$$/ 
 /$$__  $$| $$      | $$ | $$ | $$ /$$__  $$        /$$__  $$  \  $$$/  
|  $$$$$$$| $$      | $$ | $$ | $$|  $$$$$$$       |  $$$$$$$   \  $/   
 \_______/|__/      |__/ |__/ |__/ \_______/        \_______/    \_/    
)";
	
	banners[2] = R"(
  ____ __________ ___  ____ _      ____ __   __
 / __ `/ ___/ __ `__ \/ __ `/_____/ __ `/ | / /
/ /_/ / /  / / / / / / /_/ /_____/ /_/ /| |/ / 
\__,_/_/  /_/ /_/ /_/\__,_/      \__,_/ |___/  
)";
	banners[3] = R"(
     ___      .______      .___  ___.      ___              ___   ____    ____ 
    /   \     |   _  \     |   \/   |     /   \            /   \  \   \  /   / 
   /  ^  \    |  |_)  |    |  \  /  |    /  ^  \   ______ /  ^  \  \   \/   /  
  /  /_\  \   |      /     |  |\/|  |   /  /_\  \ |______/  /_\  \  \      /   
 /  _____  \  |  |\  \----.|  |  |  |  /  _____  \      /  _____  \  \    /    
/__/     \__\ | _| `._____||__|  |__| /__/     \__\    /__/     \__\  \__/     
                                                                               
)";
	banners[4] = R"(                                                                   
                                                                 
 8888b.  888d888 88888b.d88b.   8888b.          8888b.  888  888 
    "88b 888P"   888 "888 "88b     "88b            "88b 888  888 
.d888888 888     888  888  888 .d888888 888888 .d888888 Y88  88P 
888  888 888     888  888  888 888  888        888  888  Y8bd8P  
"Y888888 888     888  888  888 "Y888888        "Y888888   Y88P   

)"; 
	banners[5] = R"(
   _   _   _   _   _   _   _  
  / \ / \ / \ / \ / \ / \ / \ 
 ( a | r | m | a | - | a | v )
  \_/ \_/ \_/ \_/ \_/ \_/ \_/ 

)"; 
	banners[6] = R"(                                                                   
                                                                   
 ,6"Yb.  `7Mb,od8 `7MMpMMMb.pMMMb.   ,6"Yb.       ,6"Yb.`7M'   `MF'
8)   MM    MM' "'   MM    MM    MM  8)   MM      8)   MM  VA   ,V  
 ,pm9MM    MM       MM    MM    MM   ,pm9MM mmmmm ,pm9MM   VA ,V   
8M   MM    MM       MM    MM    MM  8M   MM      8M   MM    VVV    
`Moo9^Yo..JMML.   .JMML  JMML  JMML.`Moo9^Yo.    `Moo9^Yo.   W     

)";
	banners[7] = R"(                                    
                                  
,---.,---.,-.-.,---.   ,---..    ,
,---||    | | |,---|---,---| \  / 
`---^`    ` ' '`---^   `---^  `'  
 
)";
	banners[8] = R"(                                                                   
                                                                   
   .::    .: .:::.::: .:: .::    .::             .::    .::     .::
 .::  .::  .::    .::  .:  .:: .::  .:: .::::: .::  .::  .::   .:: 
.::   .::  .::    .::  .:  .::.::   .::       .::   .::   .:: .::  
.::   .::  .::    .::  .:  .::.::   .::       .::   .::    .:.::   
  .:: .:::.:::   .:::  .:  .::  .:: .:::        .:: .:::    .::    
                   
)";
	banners[9] = R"(                                            
   __     _ __    ___ ___      __                __     __  __  
 /'__`\  /\`'__\/' __` __`\  /'__`\   _______  /'__`\  /\ \/\ \ 
/\ \L\.\_\ \ \/ /\ \/\ \/\ \/\ \L\.\_/\______\/\ \L\.\_\ \ \_/ |
\ \__/.\_\\ \_\ \ \_\ \_\ \_\ \__/.\_\/______/\ \__/.\_\\ \___/ 
 \/__/\/_/ \/_/  \/_/\/_/\/_/\/__/\/_/         \/__/\/_/ \/__/  

)";
	srand(time(NULL));
	int choosed_banner = rand()%10;
	int choosed_color_1 = rand() % 15 + 1;
	int choosed_color_2 = rand() % 15 + 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), choosed_color_1);
	cout << banners[choosed_banner] << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), choosed_color_2);
}
void printHelp(char* opt)
{
	if (strcmp(opt, "all") == 0)
	{
		File::printFile("Help/h_info");
		File::printFile("Help/h_scan");
		File::printFile("Help/h_quarantine");
		File::printFile("Help/h_update");
	}
	else if (strcmp(opt, "scan") == 0)
	{
		File::printFile("Help/h_scan");

	}
	else if (strcmp(opt, "quarantine") == 0)
	{
		File::printFile("Help/h_quarantine");

	}
	else if (strcmp(opt, "update") == 0)
	{
		File::printFile("Help/h_update");

	}
	else if (strcmp(opt, "info") == 0)
	{
		File::printFile("Help/h_info");

	}
	else
	{
		File::printFile("Help/h_help");

	}
	
}
void scan_result::printResult()
{
	if(!this->isInfected)
		cout << "[+] Healthy !!"<<endl;
	else
	{
		cout << "[+] Infected !!"<<endl;
		cout << "[+] Virus Name : " << this->virusName <<endl;
	}
}

//iface_scan
int iface_scan::parseFile()
{
	string ext = File::getExt(this->path);
	if (ext == "exe" || ext == "dll")
		return 1;
	if (ext == "vb")
		return 2;
	if (ext == "html" || ext == "htm")
		return 3;
	if (ext == "eml")
		return 4;
	if (ext == "jpeg" || ext == "jpg" || ext == "png" || ext == "gif" || ext == "psd" || ext == "flv" || ext == "mp4" || ext == "wmv"
		|| ext == "rmvb" || ext == "mp3" || ext == "avi" || ext == "mkv" || ext == "wma")
		return 5;
	if (ext == "txt" || ext == "doc" || ext == "docx")
		return 7;
	return 0;
}
void iface_scan::setScanMethod()
{
	if(strcmp(this->scanMethod,"bmh") == 0)
		this->ScanMethodNum = 1;
	else if(strcmp(this->scanMethod,"ac")== 0)
		this->ScanMethodNum = 2;
	else if(strcmp(this->scanMethod,"both")== 0)
		this->ScanMethodNum = 3;
	else
		this->ScanMethodNum = -1;
}
void iface_scan::scan_file()
{
	scan_result result;
	if (this->ScanMethodNum == 1)
	{
		Database db((char*)bmdbPath.c_str());
		if (db.init() == -1)
		{
			cout << "[-] Intialization Failed .. check bmdb path in settings file !!";
			return;
		}
		File f(this->path);
		int type = this->parseFile();
		cout << "[+] Starting scanning . . ." << endl;
		for (int i = 0; i < db.SignaturesNumber; i++)
		{
			printf("[+] Progress : %2d %%\r", i * 100 / (db.SignaturesNumber) + 1);
			if (type == stoi(db.SignaturesList[i].SignatureType) && db.SignaturesList[i].SignatureSize != -1)
			{
				if (BMH::search(db.SignaturesList[i].AsciiSignature, db.SignaturesList[i].SignatureSize,f.Buffer,f.BufferSize) != -1)
				{
					result.isInfected = true;
					result.virusName = (char*)db.SignaturesList[i].VirusName.c_str();
					break;
				}
			}
		}
		result.printResult();

	}
	else if (this->ScanMethodNum == 2)
	{
		AhoCorasick ac; File f(this->path);
		ac.LoadDB();
		ac.Search(f.Buffer, f.BufferSize);

	}
	else if (this->ScanMethodNum == 3)
	{

	}
	result.printResult();
}
void iface_scan::scan_directory()
{
	scan_result result;
	result.isInfected = true;
	result.virusName = "mo7a firus";
	result.printResult();
}

//iface_quarantine
void iface_quarantine::list()
{
	Qdb quarantine(QuarantinePath);
	quarantine.list();

}
void iface_quarantine::add(char* path,char* foundVirus,int key)
{
	Qdb quarantine(QuarantinePath);
	if (quarantine.add(path, foundVirus, key) == -1)
		cout << "[-] Error Adding this file to quarantine !!" << endl;
	else
		cout << "[+] File Added Successfully !!" << endl;

}
void iface_quarantine::restore(int qID)
{
	Qdb quarantine(QuarantinePath);
	if (quarantine.restore(qID) == -1)
		cout << "[-] Error restoring this file from quarantine !!" << endl;
	else
		cout << "[+] File Restored Successfully !!" << endl;

}
void iface_quarantine::remove(int qID)
{
	Qdb quarantine(QuarantinePath);
	if (quarantine.remove(qID) == -1)
		cout << "[-] Error deleting this file from quarantine !!" << endl;
	else
		cout << "[+] File Deleted Successfully !!" << endl;
}
void iface_quarantine::clear()
{
	Qdb quarantine(QuarantinePath);
	if (quarantine.clear() == -1)
		cout << "[-] Error Clearing Quarantine !!" << endl;
	else
		cout << "[+] Quarantine Cleared Successfully !!" << endl;

}

//iface_update
int iface_update::UpdateCore()
{
	return 1;
}
int iface_update::UpdateGUI()
{
	return 1;
}
int iface_update::UpdateDbRemotely()
{
	return 1;
}
int iface_update::UpdateBMHDBLocally(char* bmdb)
{
	return 1;
}
int iface_update::UpdateACDBLocally(char* acdb)
{
	return 1;
}

//iface_state
int iface_state::GetCurrentVersion()
{
	string core_vr, gui_vr, bmdb_vr, acdb_vr;
	fstream ver_file(VersionPath, ios::in);
	if (ver_file.good())
	{
		ver_file >> core_vr >> gui_vr >> bmdb_vr >> acdb_vr;
		cout << "Arma Version Status ->" << endl;
		cout << "[+] Core	: " << core_vr << endl;
		cout << "[+] GUI		: " << gui_vr << endl;
		cout << "[+] BMH db	: " << bmdb_vr << endl;
		cout << "[+] Aho db	: " << acdb_vr << endl;
		return 0;
	}
	else
		return -1;
}
int iface_state::GetLatestVersion()
{
	char* new_ver = File::addExt((char*)VersionPath.c_str(), ".newVer");
	if (OS::downloadFile((char*)VersionURL.c_str(), new_ver) == -1)
		return -1;
	else
	{
		fstream ver_file(new_ver, ios::in);
		string core_vr, gui_vr, bmdb_vr, acdb_vr;
		ver_file >> core_vr >> gui_vr >> bmdb_vr >> acdb_vr;
		cout << "Arma Version Status ->" << endl;
		cout << "[+] Core	: " << core_vr << endl;
		cout << "[+] GUI		: " << gui_vr << endl;
		cout << "[+] BMH db	: " << bmdb_vr << endl;
		cout << "[+] Aho db	: " << acdb_vr << endl;
		ver_file.close();
	}
	
	OS::deleteFile(new_ver);
	return 0;
}
void iface_state::GetQuarantineState()
{
	ifstream quarantine(QuarantinePath);
	__int64 line_count;
	line_count = count(istreambuf_iterator<char>(quarantine), istreambuf_iterator<char>(), '\n');
	cout << "[+] Quarantine Files Number : " << line_count - 1 << endl;
}





