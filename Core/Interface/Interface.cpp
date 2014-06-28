/*
 * Interface.cpp
 *
 *  Created on: Jun 25, 2014
 *      Author: Ahmed Fouda
 */
#include "Interface.h"

using namespace std;

bool cmp(char* arg, char* opt1, char* opt2)
{
	char* op1 = new char(strlen(opt1)+2);
	strcpy(op1 , "-");
	char* op2 = new char(strlen(opt2)+3);
	strcpy(op2 , "--");
	strcat(op1,opt1);
	strcat(op2,opt2);
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
	cout << banners[choosed_banner] << endl;
}
void printFile(char* path)
{
	ifstream f(path);
	string line;
	while (getline(f, line))
		cout << line << endl;
}
void printHelp(char* opt)
{
	if (strcmp(opt, "all") == 0)
	{
		printFile("Help/h_info");
		printFile("Help/h_scan");
		printFile("Help/h_quarantine");
		printFile("Help/h_update");
	}
	else if (strcmp(opt, "scan") == 0)
	{
		printFile("Help/h_scan");

	}
	else if (strcmp(opt, "quarantine") == 0)
	{
		printFile("Help/h_quarantine");

	}
	else if (strcmp(opt, "update") == 0)
	{
		printFile("Help/h_update");

	}
	else if (strcmp(opt, "info") == 0)
	{
		printFile("Help/h_info");

	}
	else
	{
		printFile("Help/h_help");

	}
	
}
void printVersion()
{
cout << "current version";
}
void printLatestVersion()
{
cout << "Latest version";
}
void printResult(scan_result result)
{
	if(!result.isInfected)
		cout << "[+] File is Healthy !!"<<endl;
	else
	{
		cout << "[+] File is infected !!"<<endl;
		cout << "[+] Virus Name : " << result.virusName <<endl;
	}
}

//iface_scan
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
	scan_result* result = new scan_result();
	result->isInfected = true;
	result->virusName = "7amada firus";
	printResult(*result);
}
void iface_scan::scan_directory()
{
	scan_result* result = new scan_result();
	result->isInfected = true;
	result->virusName = "3abdo firus";
	printResult(*result);
}

//iface_quarantine
void iface_quarantine::list()
{

}
void iface_quarantine::add(char* path)
{

}
void iface_quarantine::restore(int qID)
{

}
void iface_quarantine::remove(int qID)
{

}

//iface_update
int iface_update::UpdateVersion()
{
	return 1;
}
int iface_update::UpdateDatabaseLocally(char* db)
{
	return 1;
}
int iface_update::UpdateDatabaseRemotely()
{
	return 1;
}

//iface_state
int iface_state::GetCurrentVersion()
{
	return 0;
}
int iface_state::GetLatestVersion()
{
	return 0;
}
int iface_state::GetDatabaseCurrentVersion()
{
	return 0;
}
int iface_state::GetDatabaseLatestVersion()
{
	return 0;
}




