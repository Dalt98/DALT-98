// Group Members include:
// Phillip Cole
// Dejah Taylor
// Kristofer Campbell
// Tahjae Campbell

#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

class TreeNode
{

private:

    TreeNode *LeftSubTree;
    TreeNode *RightSubTree;

public:

    string POS;
    string Definition;
    string word;

    TreeNode()
    {
        word = "";
        POS = "";
        Definition = "";
        LeftSubTree = NULL;
        RightSubTree = NULL;
    }
    TreeNode(string x,string y, string z)
    {
        word = x;
        POS = y;
        Definition = z;
        LeftSubTree = NULL;
        RightSubTree = NULL;
    }

    TreeNode2(string x)
    {
        word = x;
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

    void SetRightSubTree(TreeNode *p)
    {
        RightSubTree = p;
    }
    TreeNode *GetRightSubTree()
    {
        return RightSubTree;
    }
    void SetLeftSubTree(TreeNode *p)
    {
        LeftSubTree = p;
    }
    TreeNode *GetLeftSubTree()
    {
        return LeftSubTree;
    }
};

#endif // TREENODE_H_INCLUDED
