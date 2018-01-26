// Group Members include:
// Phillip Cole
// Dejah Taylor
// Kristofer Campbell
// Tahjae Campbell

#ifndef STACKNODE_H_INCLUDED
#define STACKNODE_H_INCLUDED
#include <iostream>
using namespace std;
class Node
{

private:

    string word;
    string POS;
    string Definition;
    Node *NextNode;

public:

    Node()
    {
        word = "";
        POS = "";
        Definition = "";
        NextNode = NULL;
    }

    void Setword(string x)
    {
        word = x;
    }

    string Getword()
    {
        return word;
    }

    void SetPOS(string y)
    {
        POS = y;
    }

    string GetPOS()
    {

        return POS;

    }

    void SetDefinition(string z)
    {
        Definition = z;
    }

    string GetDefinition()
    {

        return Definition;

    }


    void SetNextNode(Node *p)
    {
        NextNode = p;
    }

    Node *GetNextNode()
    {
        return NextNode;
    }

};

#endif // STACKNODE_H_INCLUDED
