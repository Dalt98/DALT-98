// Group Members include:
// Phillip Cole
// Dejah Taylor
// Kristofer Campbell
// Tahjae Campbell

#include <iostream>
#include "Stack.h"
#include "Tree.h"
#include <fstream>
#include <stdlib.h>
#include <exception>
#include <windows.h>
#include <ctime>

using namespace std;

Stack S; // Invoke Stack Class
Tree  T; // Invoke Tree Class


int main()
{

    system("Color 4F");
    int menu; // variable for menu input
    int submenu; // variable for sub_menu input
    string x,y,z;
    string word;
    string Definition;
    int s = 0;
    int t = 0;

    // Dictionary operations
    A:
    system("CLS");
    cout << " \n\n                                T P D K    D I C T I O N A R Y \n\n" << endl;
    cout << "                               1: Load Words\n" << endl;
    cout << "                               2: Sort Words Alphabetically\n" << endl;
    cout << "                               3: Search for a Word\n" << endl;
    cout << "                               4: Add Word\n" << endl;
    cout << "                               5: Print All Words\n" << endl;
    cout << "                               6: Check for a Sentence\n" << endl;
    cout << "                               7: EXIT\n\n" << endl;
    cout << "\t\tEnter The Number That Corresponds With Your Choice:"<<" ";
    cin >>menu;
    system("CLS");
    switch(menu)
    {

    case 1: // LOAD DATA

            cout<<"\n"<<endl;
            cout<<"                 Choose the structure you wish to use to load the words\n\n"<<endl;
            cout<<"                             1: Stack Load\n" << endl;
            cout<<"                             2: Tree Load\n" << endl;
            cout<<"                             3: Go Back\n"<<endl;
            cout << "                  Your Choice :\t";
            cin >> submenu;
            //system("CLS");


            switch(submenu)
            {
                case 1:// Stack operation
                        s++;//increments before load is processed
                        S.LoadToStack();// Here we call the function to individually store the three parts of data (word,part of speech,definition)
                        //S.LoadToStack2(); //Uncomment of you wish to load more words in the stack
                        //S.LoadToStack3(); //Uncomment of you wish to load more words in the stack
                        //system("CLS");
                        cout<<"\n\n\n                                   LOAD SUCCESSFUL\n\n\t\t\t\t";
                        system("pause");
                        system("CLS");
                        goto A;
                        break;


                case 2:// Tree operation
                        t++;
                        T.LoadToTree();// Here we call the function to individually store the three parts of data (word,part of speech,definition)
                        //T.LoadToTree2(); //Uncomment of you wish to load more words in the tree
                        //T.LoadToTree3(); //Uncomment of you wish to load more words in the tree
                        cout<<"\n\n\n                                   LOAD SUCCESSFUL\n\n\t\t\t\t";
                        system("pause");
                        system("CLS");
                        goto A;
                        break;


                case 3: //Go back to main menu
                        goto A;
                        break;

            }

    case 2: // SORT DATA

            cout<<"\n"<<endl;
            cout<<"                 Choose the structure you wish to use to sort the words\n\n"<<endl;
            cout<<"                             1: Stack Sort\n" << endl;
            cout<<"                             2: Tree Sort\n" << endl;
            cout<<"                             3: Go Back\n" << endl;
            cout << "                  Your Choice :\t";
            cin >> submenu;
            system("CLS");

            switch(submenu)
            {

                case 1:

                       try
                       {
                            if(s == 0)//If loading operations aren't processed
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }

                        S.SortWords(x,y,z);
                        system("pause");
                        system("CLS");
                        goto A;
                        break;

                case 2:

                        try
                       {
                            if(t == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }

                        T.SortWord();
                        system("pause");
                        system("CLS");
                        goto A;
                        break;

            }
    case 3: // SEARCH FOR A WORD

            cout<<"\n"<<endl;
            cout<<"                 Choose the structure you wish to use to search for words\n\n"<<endl;
            cout<<"                             1: Stack Search\n" << endl;
            cout<<"                             2: Tree Search\n" << endl;
            cout<<"                             3: Go Back\n"<<endl;
            cout << "                  Your Choice :\t";
            cin >> submenu;
            system("CLS");

            switch(submenu)
            {
                case 1:

                         try
                       {
                            if(s == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }

                        S.SearchForWord(S);
                        system("pause");
                        system("CLS");
                        goto A;
                        break;
                case 2:
                        {

                        try
                       {
                            if(t == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }

                        try
                        {
                        cout<<"\n\n\t\tWhat's the word you are looking for : \t";
                        cin>>word;
                            if(word[0] > 96 )
                            {
                                throw -1;
                            }
                        }

                        catch(int)
                        {
                            word[0] = word[0]-32;
                        }

                        system("CLS");
                        clock_t tStart = clock();//start clock timing
                        T.SearchForWord(word,T.GetRoot());
                        cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
                        system("pause");
                        system("CLS");
                        goto A;
                        break;
            }
                case 3://Go back to main menu
                        goto A;
                        break;

            }
    case 4: // ADD WORD

            cout<<"\n"<<endl;
            cout<<"                 Choose the structure you wish to use to add words\n\n"<<endl;
            cout<<"                             1: Stack Add\n" << endl;
            cout<<"                             2: Tree Add\n" << endl;
            cout<<"                             3: Go Back\n"<<endl;
            cout << "                  Your Choice :\t";
            cin >> submenu;
            system("CLS");

            switch(submenu)
            {
                case 1:

                         try
                       {
                            if(s == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }

                        S.AddWord(x,y,z);
                        cout<<"\n\n\n                                    WORD ADDED SUCCESSFULLY\n\n\t\t\t\t";
                        system("pause");
                        system("CLS");
                        goto A;
                        break;

                case 2:

                         try
                       {
                            if(t == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }


                        T.AddWord(x,y,z);
                        cout<<"\n\n\n                                    WORD ADDED SUCCESSFULLY\n\n\t\t\t\t";
                        system("pause");
                        system("CLS");
                        goto A;
                        break;

                case 3://Go back to main menu
                        goto A;
                        break;
            }


    case 5: // PRINT DATA

            cout<<"\n"<<endl;
            cout<<"                 Choose the structure you wish to use to view all words\n\n"<<endl;
            cout<<"                             1: Stack View\n" << endl;
            cout<<"                             2: Tree View\n" << endl;
            cout<<"                             3: Go Back\n"<<endl;
            cout << "                  Your Choice :\t";
            cin >> submenu;
            system("CLS");

            switch(submenu)
            {
                case 1:

                     try
                       {
                            if(s == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }

                    S.PrintWords();
                    system("pause");
                    system("CLS");
                    goto A;
                    break;

            case 2:

                     try
                       {
                            if(t == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }


                    T.PrintWords();
                    cout<<"\n\n\n                                    SUCCESSFUL\n\n\t\t\t\t";
                    system("pause");
                    system("CLS");
                    goto A;
                    break;

            case 3://Go back to main menu
                    goto A;
                    break;
            }

    case 6: // VALIDATE A SENTENCE

        cout<<"\n"<<endl;
        cout<<"                 Choose the structure you wish to use to check for words\n\n"<<endl;
        cout<<"                             1: Stack Check\n" << endl;
        cout<<"                             2: Tree Check\n" << endl;
        cout<<"                             3: Go Back\n"<<endl;
        cout << "                  Your Choice :\t";
        cin >> submenu;
        system("CLS");

            switch(submenu)
            {
            case 1:
                    {
                     try
                       {
                            if(s == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }

                    S.CheckSentence();
                    system("pause");
                    system("CLS");
                    goto A;
                    break;
                    }
            case 2:
                        {

                    try
                       {
                            if(t == 0)
                            {
                                throw -1;

                            }
                       }

                       catch(int)
                       {

                           cout << endl << "Must load the datasets First" << endl << endl;
                           system("pause");
                           goto A;
                       }

                    string sentenceWords[10], sentence, Words, x,y,z;
                    char ans;
                    int countw = 0,i;
                    int found = 0;
                    cin.ignore(10000,'\n');
                    cout<<"\t\t\t\n\nEnter your sentence: \t"<<endl;
                    getline(cin,sentence);
                    clock_t tStart = clock();//Initiates beginning of time count
                    for(short i = 0; i<sentence.length(); i++) //Adds each individual word to its own place in the array
                        {
                            if (sentence[i] == ' ')//traverses word until space is reached
                            {
                                countw++;//increments as one word completes
                            }
                        else
                            {
                            sentenceWords[countw] += sentence[i];//Sets the letters before the space equal to a word
                            }
                        }
                    for(i=0; i<countw+1; i++) //loops to perform operation on each word found
                    {
                        Words = sentenceWords[i];//Lets words found be equal to variable word
                        found = T.Search(Words,T.GetRoot());//Calls the function to check a sentence if word is found
                        if (found != 1)//if word isn't found
                        {
                            cout<<"\t\t\tThe word "<<Words<<" was not found in the dictionary. Would you like to add it? [Y/N] \t"<<endl;
                            cin>>ans;
                        }
                        if (ans == 'Y' || ans == 'y' )
                            {
                                T.AddWord(x,y,z);//calls addword funtion to add word to stack
                            }
                    }
                    system("CLS");
                    cout<<"Sentence has been checked"<<endl;
                    cout<<"\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s\n"<<endl;//Stops the time period and displays total time
                    system("pause");
                    system("CLS");
                    goto A;
                    break;
            }

            case 3://Go back to main menu
                    goto A;
                    break;

            default:
                    cout << "Invalid input!!" << endl;
                    break;
            }

        case 7:
                cout <<"\n\n\t\t\t****************************************************************" <<endl;
                cout <<"\t\t\t\t\t     G-O-O-D-B-Y-E   F-A-M" <<endl;
                cout <<"\t\t\t****************************************************************" <<endl;
                break;
                exit;


            default:
                    cout << "\n\n\t\tI N V A L I D   I N P U T\n\n" << endl;
                    cout << "\t\tRun with specified inputs please"<<endl;

    }
    return 0;
}





