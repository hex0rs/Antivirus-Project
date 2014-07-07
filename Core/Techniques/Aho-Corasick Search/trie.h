#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#define HEX_SIZE 16

#include <iostream>

struct Node
{
    bool IsLeaf;
    char ch;
    unsigned int ID; //used to identify nodes in saving and loading DB
    unsigned int danger_level;
    std::string type;
    std::string name;
    Node *Fail_Node;
    Node *Children[HEX_SIZE];
    
    void operator= (Node a) //Providing = operator if needed to copy a Node to another
    {
        this->ch = a.ch;
        this->danger_level = a.danger_level;
        this->Fail_Node = a.Fail_Node;
        this->ID = a.ID;
        this->IsLeaf = a.IsLeaf;
        this->name = a.name;
        this->type = a.type;

        for(int i=0;i<HEX_SIZE;i++)
        {
            if(a.Children[i] != NULL)
            {
                this->Children[i] = a.Children[i];
            }
        }
    }
    
};

Node* FindHex(Node*,Node*);
Node* Init(void);
void Add(std::string,std::string,std::string,unsigned int);
void Build_Fail_Edges(void);
Node* Go_To(Node*,char);


#endif // TRIE_H_INCLUDED
