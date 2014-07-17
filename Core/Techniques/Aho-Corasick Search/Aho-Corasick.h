/*
 * Aho-Corasick.h
 *
 *  Created on: Jun 25, 2014
 *      Author: Ahmed Fouda
 */

#ifndef AHO_CORASICK_H_
#define AHO_CORASICK_H_

#include <iostream>
#include "../Techniques.h"
#include "../../Shared/SigDb/Database.h"
#include "../../tools/NDBtoDB Converter/NDBtoDb.h"


class Techniques::Static::AhoCorasick
{
   private:
   int Search_Result;
   int CreateTrie(void);
   int SavingTrie(void); //To Speed up the process
   int LoadingTrie(void);
   
   public:
   AhoCorasick(void);
   AhoCorasick(char* text,unsigned int text_size);
   ~AhoCorasick(void);
   int LoadDB(void);
   int Search(char* text,unsigned int text_size);
};



#endif /* AHO_CORASICK_H_ */
