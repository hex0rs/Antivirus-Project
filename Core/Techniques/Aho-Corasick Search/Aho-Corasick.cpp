#include "Aho-Corasick.h"
#include "trie.h"
#include <fstream>
#include <queue>
#include <map>

Node* current;

Techniques::Static::AhoCorasick::AhoCorasick(void)
{
  Search_Result = -1;
}

Techniques::Static::AhoCorasick::AhoCorasick(char* text,unsigned int text_size)
{
    LoadDB();
    Search_Result = Search(text,text_size);
}

int Techniques::Static::AhoCorasick::CreateTrie(void)
{

NDBtoDbConverter("Databases\\NDB.ndb", "Databases\\test.db");

if(Shared::SigDb::Database d("Databases\\test.db"))
{
        std::cerr << "Failed to build database." << std::endl;
        return 1;  
}
d.init();



for(int i=0;i<d.SignaturesNumber;i++)
{
  Add( d.SignaturesList[i].HexSignature, d.SignaturesList[i].VirusName,"Not filled yet.",1);
}

Build_Fail_Edges();
return 0;
}

int Techniques::Static::AhoCorasick::Search(char* text,unsigned int text_size)
{

    for(unsigned int a=0;a<=text_size;a++)
    {
        current = Go_To(current,toupper(text[a]) );
        if(true == current->IsLeaf)
        {
            std::cout<<"Virus is found!!"<<std::endl;
            std::cout<<"Virus Name : "<<current->name<<std::endl;
            std::cout<<"Virus Type : "<<current->type<<std::endl;
            std::cout<<"Danger Level = "<<current->danger_level<<std::endl;
            return 1;
        }

    }

    std::cout<<"No virus was found."<<std::endl;
    return -1;

}

int Techniques::Static::AhoCorasick::SavingTrie(void)
{
    std::ofstream ADB("ADB.db"); //Creating trie DB 

    if(!ADB.is_open())
    {
        std::cerr << "Error while saving database." << std::endl;
        return 1;
    }

    std::queue<Node*> Opened;

    Node* node = current;
    Opened.push(node);



    while(!Opened.empty())
    {
        node = Opened.front();

        ADB << node->ID << " "
            << node->ch << " "
            << node->IsLeaf << " "
            << node->danger_level << " "
            << node->Fail_Node->ID << " ";

        if(node->name == "") //There is no value
        ADB << "@ ";
        else
        ADB << node->name << " ";

        if(node->type == "") //There is no value
        ADB << "@ ";
        else
        ADB << node->type << " ";


        for(unsigned int a=0;a<HEX_SIZE;a++)
        {
            if(NULL != node->Children[a])
            {
                    Opened.push(node->Children[a]);
                    ADB << node->Children[a]->ch << " " << node->Children[a]->ID<<" ";
            }
        }

        ADB << std::endl;
        Opened.pop();
    }

    return 0;

}


int Techniques::Static::AhoCorasick::LoadingTrie(void)
{
    char ch;
    bool Root = 1;
    unsigned int casted,ID;
    std::map<unsigned int,Node*> Nodes;
    std::ifstream ADB("ADB.db"); //open trie DB

    if(!ADB.is_open())
    {
        std::cerr << "Error while loading database." << std::endl;
        return 1;
    }


    while(!ADB.eof())
    {
        ADB >> ID;

        if(Nodes[ID] == NULL)
        Nodes[ID] = new Node();

        Nodes[ID]->ID = ID;
        Nodes[ID]->Fail_Node = new Node();

        ADB >> Nodes[ID]->ch >> Nodes[ID]->IsLeaf >> Nodes[ID]->danger_level >>Nodes[ID]->Fail_Node->ID>> Nodes[ID]->name >> Nodes[ID]->type;

        if(Nodes[ID]->name == "@")
        Nodes[ID]->name = "";
        if(Nodes[ID]->type == "@")
        Nodes[ID]->type = "";

        Nodes[ID]->Fail_Node = Nodes[Nodes[ID]->Fail_Node->ID];

        if(!Nodes[ID]->IsLeaf) //Leaf node has no children
        while(ADB.peek()!= '\n')
        {

          ADB >> ch;
          int casted = (int) ch;

          if(casted > 57) //The digit was a hex char not a number
           casted = casted - (int) 'A' + 10;
          else
           casted = casted - (int) '0';

          Nodes[ID]->Children[casted] = new Node();
          Nodes[ID]->Children[casted]->ch = ch;


          ADB >> Nodes[ID]->Children[casted]->ID;

          if(Nodes[Nodes[ID]->Children[casted]->ID] == NULL)
          Nodes[Nodes[ID]->Children[casted]->ID] = new Node();
          Nodes[Nodes[ID]->Children[casted]->ID] = Nodes[ID]->Children[casted];

          ADB.ignore(1,' '); //Removing the space before the endline character
        }
        if(Root)
        {
            current = Nodes[ID]; //Giving a reference to the trie Root
            Root=0;
        }
    }

    return 0;
}

int Techniques::Static::AhoCorasick::LoadDB(void)
{
    std::fstream Version; 
    float DB_ver,ADB_ver;

    Version.open("version.dat",std::fstream::in | std::fstream::out); //version.dat needs to be updated every time signature DB is updated

    if(!Version.is_open())
    {
        std::cerr << "Couldn't check for Database version." << std::endl;
        return 1;
    }

    Version>>DB_ver>>ADB_ver;

    Version.clear(); //c++ standards prevents outputing after inputing directly
    Version.seekp(0);


    if(DB_ver != ADB_ver) //Trie database isn't updated up to signatures database
    {
        CreateTrie();

        if(!SavingTrie()) //No error occured while saving database
        {
            Version<<DB_ver<<std::endl<<DB_ver<<"     "<<std::endl; //trie database became updated so both version are the same
            Version.close();
        }

        else
        {
            std::cerr << "Failed to save database." << std::endl;
            Version.close();
            return 1;
        }
    }

    else //Trie database is well updated
    {
        if(LoadingTrie()) //error occured while loading database
        {
            std::cerr << "Failed to load database." << std::endl;
            Version.close();
            return 1;
        }
        Version.close();
    }

    return 0;

}
