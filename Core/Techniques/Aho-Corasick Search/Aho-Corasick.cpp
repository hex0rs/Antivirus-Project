#include "Aho-Corasick.h"
#include "trie.h"
#include <fstream>

Node* current;

Techniques::Static::AhoCorasick::AhoCorasick(void)
{
  Search_Result = -1;
}

Techniques::Static::AhoCorasick::AhoCorasick(char* DB_Path,char* text,unsigned int text_size)
{
    CreateTrie(DB_Path);
    Search_Result = Search(text,text_size);
}

void Techniques::Static::AhoCorasick::CreateTrie(char* DB_Path)
{
    std::ifstream DB(DB_Path,std::ifstream::in);
    current = Init();

    std::string signature,type,name;
    unsigned int danger_level;

  while(!DB.eof())
  {
    DB>>signature>>name>>type>>danger_level;
    //std::cout<<signature<<"  "<<name<<"  "<<type<<"  "<<danger_level<<std::endl;
    Add(signature,name,type,danger_level);
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
