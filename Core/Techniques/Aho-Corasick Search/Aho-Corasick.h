
#ifndef Aho-Corasick_H
#define Aho-Corasick_H
#include <iostream>
#include "../Techniques.h"
#include "../../Shared/SigDb/Database.h"
#include "../../tools/NDBtoDB Converter/NDBtoDb.h"


class Techniques::Static::AhoCorasick
{
   private:
   int Search_Result;

   public:
   AhoCorasick(void);
   AhoCorasick(char* text,unsigned int text_size);
   void CreateTrie(void);
   int Search(char* text,unsigned int text_size);
};


#endif
