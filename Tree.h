// Group Members include:
// Phillip Cole
// Dejah Taylor
// Kristofer Campbell
// Tahjae Campbell

//Please note that our check sentence function avoids a word if it is in the dictionary and moves to the next word which is not

//**Separates methods to be able to see them better

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "Treenode.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

class Tree
{
private:

    TreeNode *Root;
public:

    int successful_search;
    string Definition;
    string POS;
    string word;

    Tree()
    {
        successful_search =0;
        Root = NULL;
    }

    TreeNode *GetRoot()
    {
        return Root;
    }

    void PreOrderTraversal(TreeNode *R)
    {
        if(R != NULL)
        {
            cout << R->Getword() << " ";
            cout << R->GetPOS() << " ";
            cout << R->GetDefinition() << " ";
            PreOrderTraversal(R->GetLeftSubTree());
            PreOrderTraversal(R->GetRightSubTree());
        }
    }


//*********************************************************************************************************************************************



    void Inorder (TreeNode *R)
    {
        if(R != NULL)
        {
            Inorder(R->GetLeftSubTree());
            cout << R->Getword() << " ";
            cout << R->GetPOS() << " ";
            cout << R->GetDefinition() << " "<<endl << endl;
            Inorder(R->GetRightSubTree());
        }
    }


//*********************************************************************************************************************************************



     void Postorder (TreeNode *R)
    {
        if(R != NULL)
        {
            Postorder(R->GetLeftSubTree());
            Postorder(R->GetRightSubTree());
            cout << R->Getword() << " ";
            cout << R->GetPOS() << " ";
            cout << R->GetDefinition() << " ";
        }
    }

//*********************************************************************************************************************************************


    void InsertNode(string x, string y, string z)
    {
        TreeNode *N = new TreeNode(x,y,z);
        TreeNode *T;
            if(N != NULL)
            {
                if(Root == NULL)
                {
                    Root = N;
                }
                else
                {
                    T = Root;
                    while( true )
                    {
                        if( N->word[0] < T->word[0])
                        {
                            if( T->GetLeftSubTree() == NULL)
                                {
                                    T->SetLeftSubTree(N);
                                    break;
                                }
                            else
                                {
                                    T = T->GetLeftSubTree();
                                }
                                }
                        else
                                {
                                if( T->GetRightSubTree() == NULL)
                                    {
                                        T->SetRightSubTree(N);
                                        break;
                                    }
                                else
                                    {
                                        T = T->GetRightSubTree();
                                    }
                                    }
                                    }
                                    }
                                    }
                else
                {
                cout << "Error – out of memory, cannot add new node" << endl;
                }
    }

//*********************************************************************************************************************************************


        void LoadToTree()
        {
            ifstream wordbook1("wb1913_samp260.txt");
            clock_t tStart = clock();
             try
            {
                if (!wordbook1.is_open())
                {
                    throw 909;
                }
            }

            catch(int x)
            {
                cout << "Error code: " << x << "Could not open file!" << endl;
            }


                while(!wordbook1.eof())// stores the data to the variables until end of file is reached
                {

                wordbook1 >> word;
                wordbook1 >> POS;
                getline(wordbook1,Definition);

                cout << word << "\t" << POS << Definition << endl;

            InsertNode(word,POS,Definition);//this pushes the variables to the node

                }
                wordbook1.clear();
                cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
                wordbook1.close();
        }


//*********************************************************************************************************************************************


void LoadToTree2()
        {
            ifstream wordbook1("wb1913_samp520.txt");
            clock_t tStart = clock();
             try
            {
                if (!wordbook1.is_open())
                {
                    throw 909;
                }
            }

            catch(int x)
            {
                cout << "Error code: " << x << "Could not open file!" << endl;
            }


                while(!wordbook1.eof())// stores the data to the variables until end of file is reached
                {

                wordbook1 >> word;
                wordbook1 >> POS;
                getline(wordbook1,Definition);

                cout << word << "\t" << POS << Definition << endl;

            InsertNode(word,POS,Definition);//this pushes the variables to the node

                }
                wordbook1.clear();
                cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
                wordbook1.close();
        }


//*****************************************************************************************************************************************



void LoadToTree3()
        {
            ifstream wordbook1("wb1913_samp1040.txt");
            clock_t tStart = clock();
             try
            {
                if (!wordbook1.is_open())
                {
                    throw 909;
                }
            }

            catch(int x)
            {
                cout << "Error code: " << x << "Could not open file!" << endl;
            }


                while(!wordbook1.eof())// stores the data to the variables until end of file is reached
                {

                wordbook1 >> word;
                wordbook1 >> POS;
                getline(wordbook1,Definition);

                cout << word << "\t" << POS << Definition << endl;

            InsertNode(word,POS,Definition);//this pushes the variables to the node

                }
                wordbook1.clear();
                cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
                wordbook1.close();
        }

//******************************************************************************************************************************************************



    void SortWord()
    {
        clock_t tStart = clock();
        Inorder(GetRoot());
        cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s\n"<<endl;
    }

//*******************************************************************************************************************************************************

       void AddWord(string x, string y, string z)
    {
    try
    {

        cout<<"\n\n\tNew word : ";
        cin>>word;

        if(word[0] > 96 )
        {
        throw -1;
        }
    }

    catch(int)
    {
        word[0] = word[0]-32;//Sets the first letter of word to caps
    }

        cout<<"\n\n\tIt's part of speech : ";
        cin>>POS;
        cout<<"\n\n\tEnter it's definition : ";
        cin>>Definition;
        clock_t tStart = clock();
        InsertNode(word,POS,Definition);
        cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
    }


//*********************************************************************************************************************************************




    void SearchForWord(string word, TreeNode *R)
    {
       if(R != NULL)
        {
            if( word==R->Getword())
            {
            cout << R->Getword() << " ";
            cout << R->GetPOS() << " ";
            cout << R->GetDefinition() << " \n"<<endl;
            }
            SearchForWord(word,R->GetLeftSubTree());
            SearchForWord(word,R->GetRightSubTree());

        }
    }


//*********************************************************************************************************************************************



    void PrintWords()
    {
        clock_t tStart = clock();
        Inorder(GetRoot());
        cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
    }


//*********************************************************************************************************************************************



    int CheckSentence(string Words,TreeNode *R)
    {
            if (R != NULL)
            {
            if(Words == R->Getword())
            {
                successful_search = 1;
                return 1;
            }
            CheckSentence(Words,R->GetLeftSubTree());
            CheckSentence(Words,R->GetRightSubTree());
            }
    }


//*********************************************************************************************************************************************



    int Search(string Words, TreeNode *R)
    {
        CheckSentence(Words,R);
        if (successful_search == 1)
        {
            successful_search = 0;
            return 1;
        }
        return 0;
    }

};

#endif // TREE_H_INCLUDED
