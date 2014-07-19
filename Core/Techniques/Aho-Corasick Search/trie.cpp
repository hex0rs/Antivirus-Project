#include "trie.h"
#include <queue>

Node* Root;
unsigned int Add_calls=0; //used as an ID to Node

Node* Init()
{
    Root = new Node();
    Root->ch = 'R';
    Root->Fail_Node = Root;
    Root->IsLeaf = false;
    Root->ID=0;
    return Root;
}

void Add(std::string signature,std::string name,std::string type,unsigned int danger_level)
{
	Node* current = Init();
	Node* root = Init();
    for(unsigned int a=0;a<signature.length();a++)
    {
        int casted_digit = (int) signature[a];

        /*if(casted_digit > 57) //The digit was a hex char not a number
           casted_digit = casted_digit - (int) 'A' + 10;
        else
           casted_digit = casted_digit - (int) '0';*/
		std::map<int, Node*>::const_iterator it = current->Children.find(casted_digit);
		if (it == current->Children.end())
	{
           current->Children[casted_digit] = new Node();
           current->Children[casted_digit]->ch = signature[a];
           current->Children[casted_digit]->ID = Add_calls++;
        }

        current = current->Children[casted_digit];
    }
    current->IsLeaf = true;
    current->name = name;
    current->type = type;
    current->danger_level=danger_level;

}

void Build_Fail_Edges()
{
    //Breadth-first search is used to traverse through the trie and find the closest fail node

    std::queue<Node*> Opened_Nodes;
    Node* current = Root;

    for(unsigned int a=0;a<HEX_SIZE;a++)
    {
        if(NULL != current->Children[a])
        {
            current->Children[a]->Fail_Node = Root;
            Opened_Nodes.push(current->Children[a]);
        }
    }

    while(!Opened_Nodes.empty())
    {
        current = Opened_Nodes.front();

         for(unsigned int a=0;a<HEX_SIZE;a++)
         {
             if(NULL != current->Children[a])
             {
                 Node* temp = FindHex(current->Children[a],current->Fail_Node);

                 if(NULL == temp)
                 current->Children[a]->Fail_Node = current->Fail_Node;
                 else
                 current->Children[a]->Fail_Node = temp;

                 Opened_Nodes.push(current->Children[a]);
             }
         }

         Opened_Nodes.pop();
    }
}

Node* FindHex(Node* target,Node* Fail)
{
    for(unsigned int a=0;a<HEX_SIZE;a++)
    {
        if(NULL != Fail->Children[a])
        {
            if(Fail->Children[a]->ch == target->ch)
            return Fail->Children[a];
        }
    }
    return NULL;
}

Node* Go_To(Node* node,char ch)
{
    int casted_digit = (int) ch;

       /* if(casted_digit > 57) //The digit was a hex char not a number
           casted_digit = casted_digit - (int) 'A' + 10;
        else
           casted_digit = casted_digit - (int) '0';*/

      if(NULL == node->Children[casted_digit])
        {
            if(node->Fail_Node->ch != ch && NULL == node->Fail_Node->Children[casted_digit])
            return node->Fail_Node->Fail_Node;
            else
            Go_To(node->Fail_Node,ch);
        }
      else
      return node->Children[casted_digit];

}

