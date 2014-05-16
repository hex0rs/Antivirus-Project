#include "Aho-Corasick.h"
#include "trie.h"
#include "Core/Shared/SigDb/Database.h"
#include "Core\tools\NDBtoDB Converter\NDBtoDb.h"
#include <fstream>

Node* current;

Techniques::Static::AhoCorasick::AhoCorasick(void)
{
  Search_Result = -1;
}

Techniques::Static::AhoCorasick::AhoCorasick(char* text,unsigned int text_size)
{
    CreateTrie();
    Search_Result = Search(text,text_size);
}

void Techniques::Static::AhoCorasick::CreateTrie(void)
{

NDBtoDbConverter("Databases\\NDB.ndb", "Databases\\test.db");

Shared::SigDb::Database d("Databases\\test.db");
d.init();



for(int i=0;i<d.SignaturesNumber;i++)
{
 add( d.SignaturesList[i].HexSignature, d.SignaturesList[i].VirusName,"Not filled yet.",1);
}

Build_Fail_Edges();

}

int Techniques::Static::AhoCorasick::Search(char* text,unsigned int text_size)
{

    for(unsigned int a=0;a<text_size;a++)
    {
        current = Go_To(current,text[a]);
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
