#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#define HEX_SIZE 16

#include <iostream>

struct Node{
    bool IsLeaf;
    char ch;
    unsigned int ID; //used to identify nodes in saving and loading DB
    unsigned int danger_level;
    std::string type;
    std::string name;
    Node *Fail_Node;
    Node *Children[HEX_SIZE];
};

Node* FindHex(Node*,Node*);
Node* Init(void);
void Add(std::string,std::string,std::string,unsigned int);
void Build_Fail_Edges(void);
Node* Go_To(Node*,char);


#endif // TRIE_H_INCLUDED
