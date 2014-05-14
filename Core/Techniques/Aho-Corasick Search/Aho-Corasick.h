#ifndef AHO-CORASICK_H_INCLUDED
#define AHO-CORASICK_H_INCLUDED

#include <iostream>
#include "../Techniques.h"

class Techniques::Static::AhoCorasick
{
   private:
   int Search_Result;

   public:
   AhoCorasick(void);
   AhoCorasick(char* DB_Path,char* text,unsigned int text_size);
   void CreateTrie(void);
   int Search(char* text,unsigned int text_size);
};


#endif // AHO-CORASICK_H_INCLUDED
