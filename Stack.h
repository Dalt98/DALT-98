// Group Members include:
// Phillip Cole
// Dejah Taylor
// Kristofer Campbell
// Tahjae Campbell

//Please note that our check sentence function avoids a word if it is in the dictionary and moves to the next word which is not

//**Separates methods to be able to see them better

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "Stacknode.h"
#include <fstream>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <ctime>

class Stack
{
private:

    Node *Top;

public:

    int num;
     int num2 = 0;
    string Definition = "";
    string POS = "";
    string word = "";
    string* sarray = new string[1000];

    Stack()
    {
        Top = NULL;
        num = 0;
    }

    void Push(string x, string y, string z)
    {
        Node *Temp = new Node();

        if(Temp != NULL)
        {
            Temp -> Setword(x);
            Temp -> SetPOS(y);
            Temp -> SetDefinition(z);
            Temp -> SetNextNode(NULL);

            if(Top == NULL)
            {
                Top = Temp;
                num++;
            }
            else
            {
                num++;
                Temp->SetNextNode(Top);
                Top = Temp;
            }
        }
        else
        {
            cout << "Out of memory, unable to push data onto the stack" << endl;
        }
    }


  //*********************************************************************************************************************************************



     string Pop()
    {
        Node *Temp = new Node();
        string word;
        string POS;
        string Definition;
        string Diction;

        if(Top == NULL)
        {
            cout << "There is nothing in the stack to delete" << endl;
        }
        else
        {

            Temp = Top;
            Top = Top ->GetNextNode();
            word = Temp ->Getword();
            POS = Temp ->GetPOS();
            Definition = Temp ->GetDefinition();
            Diction = word + " " + POS + " " + Definition;
            cout << "----POP----" << endl;
            num2++;
        }
        return Diction;
    }


  //*********************************************************************************************************************************************



    void Display()
    {
        Node *Temp = new Node();
        if(Temp != NULL)
        {
            if(Top == NULL)
            {
            cout << "\n\n\t\t\t\t\tSTACK IS EMPTY BECAUSE IT WASN'T LOADED\n\n" << endl;
            }
            else
            {
            Temp = Top;
            while(Temp->GetNextNode()!= NULL)
            {
            cout << ":-" << " " << Temp ->Getword() << " " << Temp ->GetPOS() << " " << Temp ->GetDefinition()  << endl;
            Temp = Temp ->GetNextNode();
                }
                }
                }
    }



  //*********************************************************************************************************************************************





    void LoadToStack()//This is the stack-list function to store the three parts into three separate variable (word,POS,Def)
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
    wordbook1>>word;
    wordbook1 >> POS;
    getline(wordbook1,Definition);
    cout << word <<"\t" << POS << Definition << endl;
    Push(word,POS,Definition);//this pushes the variables to the node
    }
    wordbook1.clear();
    cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
    wordbook1.close();
    }


  //*********************************************************************************************************************************************




     void LoadToStack2()//This is the stack-list function to store the three parts into three separate variable (word,POS,Def)
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
    wordbook1>>word;
    wordbook1 >> POS;
    getline(wordbook1,Definition);
    cout << word <<"\t" << POS << Definition << endl;
    Push(word,POS,Definition);//this pushes the variables to the node
    }
    wordbook1.clear();
    cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
    wordbook1.close();
    }



  //*********************************************************************************************************************************************




    void LoadToStack3()//This is the stack-list function to store the three parts into three separate variable (word,POS,Def)
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
    wordbook1>>word;
    wordbook1 >> POS;
    getline(wordbook1,Definition);
    cout << word <<"\t" << POS << Definition << endl;
    Push(word,POS,Definition);//this pushes the variables to the node
    }
    wordbook1.clear();
    cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
    wordbook1.close();
    }


  //*********************************************************************************************************************************************




   void AddWord(string x, string y, string z)
    {
       try
       {
        cout<<"\n\n\t\t\t\t\tEnter word you wish to add to stack : \t";
        cin>>word;

        if(word[0] > 96 )
        {
        throw -1;
        }
       }

    catch(int)
    {
        word[0] = word[0]-32;//Sets first letter of word to capital
    }

        cout<<"\n\n\t\t\t\t\tIt's part of speech(followed by full stop) : \t";
        cin>>POS;
        cout<< "\n\n\t\t\t\t\tEnter it's definition : \t";
        cin>>Definition;
        clock_t tStart = clock();
        Node *Temp = new Node();

            Temp->Setword(x);
            Temp -> SetPOS(y);
            Temp -> SetDefinition(z);
            Push(word,POS,Definition);
        cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
    }


  //*********************************************************************************************************************************************




    void SortWords(string x, string y, string z)//this function pops words from stack to an array and then use the array to put back the words to the stack
    {
        clock_t tStart = clock();

        for (int i = 0 ; i < num; i++)
        {
            sarray[i] = Pop();//Pop stack words to array
            cout << sarray[i] << endl;//displays popped words
        }

       merge_sort(sarray,0, num-1);

        for (int i = 0 ; i < num ;i++)
        {
            cout << i << ":-" << sarray[i] <<endl;
        }

               for (int i = 0; i < num2 ;i++) // for loop is needed to loop through the entire array.
                {
                     int b = 0;
                    string Definition = "";
                    string POS = "";
                    string word = "";

                    do // this part of the code loops sarray to store each character of the first word one by one into word until the whitespace is reached.
                    {
                        word=word+sarray[i][b];
                        b++;

                    }while(sarray[i][b]!=' ');

                    do // this part of the code loops sarray to store each character of the POS one by one into word until the whitespace is reached.
                    {
                        POS=POS+sarray[i][b];
                        b++;

                    }while(sarray[i][b]!=' ');

                    do // this part of the code loops sarray to store each character of the Definition one by one into Definition until the Null terminator is reached.
                    {
                        Definition=Definition+sarray[i][b];
                        b++;

                    }while(sarray[i][b]!= '\0'); // do until Null terminator is reached

                    Push(word, POS, Definition); // push each variables into the stack for further operations
                }

                delete[] sarray; // delete array to release memory

    cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
    }


  //*********************************************************************************************************************************************




    void SearchForWord(Stack currentstack)
    {
        Node * Temp = Top;
        string NodeTemp;
        int a;
        int counter = 0;

    try
    {
        cout<<"\n\n\t\t\t\t\tEnter word to find : \t";
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
        clock_t tStart = clock();

        for (a=0;a<num;a++)
        {
        NodeTemp = Temp->Getword();
        counter++;

        if (word == NodeTemp )
        {
            cout<<"\n\n"<< counter <<" " << NodeTemp<<" ";
            cout<<Temp->GetPOS()<<"";
            cout<<Temp->GetDefinition()<<endl;
            cout<<"\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;

            return;
        }
        Temp = Temp->GetNextNode();

        }
        cout<<"\n\n\n\t\t\tWORD NOT FOUND . Hit ENTER to go to Main Menu to add word to stack database\n\n"<<endl;
        system("pause");
    }


  //*********************************************************************************************************************************************




    void PrintWords()
    {
        int count = 0;
     Node *Temp = new Node();
                clock_t tStart = clock();
        if(Temp != NULL)
        {
            if(Top == NULL)
            {
                cout << "\n\n\t\t\t\t\tSTACK IS EMPTY BECAUSE IT WASN'T LOADED\n\n" << endl;
            }
            else
            {
                Temp = Top;
                    //count++;
                while(Temp->GetNextNode()!= NULL)
                {
                    count++;
                    cout << count << ":-" << " " << Temp ->Getword() << " " << Temp ->GetPOS() << " " << Temp ->GetDefinition()  << endl;
                    Temp = Temp ->GetNextNode();


                }
                  cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
                }
                }
     }


//*********************************************************************************************************************************************





    void CheckSentence()
    {
        string NodeTemp;
        string sentence, x,y,z;
        string sentenceWords[10];
        int countw = 0,i;
        char ans;

        cin.ignore(10000,'\n');
        cout<<"\n\n\t\t\tEnter your sentence: \t"<<endl;
        getline(cin,sentence);
        clock_t tStart = clock();
        for (short i = 0; i<sentence.length(); i++) //Adds each indiviual word to its own place in the array
            {
            if (sentence[i] == ' ')//Traverses words until space is reached
                {
                countw++;//Increments as one word completes
                }
            else
                {
                sentenceWords[countw] += sentence[i];//sets the letters before the space equal to a word
                }
            }

        for ( i=0;i<countw+1;i++)//Loop to perform operation on each word found
        {
            Node *Temp = new Node();
            Temp = Top;
            while(Temp->GetNextNode()!= NULL) //checks all of the nodes to see if it exist in the dictionary
            {
                NodeTemp = Temp->Getword();//Moves through list checking words
                if (sentenceWords[i] == NodeTemp )//If word equals to letters put together before space
                {
                break;
                }
                Temp = Temp->GetNextNode();//Move on to next word in list because we know a word in there already
            }
            if (sentenceWords[i] == NodeTemp )//If word found, program will ignore it and move on
            {
                continue;
            }
            else //If the word doesn't exist in the dictionary, prompts the user to add it to the dictionary
            {
                cout<<"\t\t\tThe word "<<sentenceWords[i]<<" was not found in the dictionary. Would you like to add it? [Y/N] \t"<<endl;
                cin>>ans;
                if (ans == 'Y' || ans == 'y' )
                    {
                        AddWord(x,y,z);
                    }
                    else
                    {
                        continue;  }
            }
        }
        cout<<"\n\n\nTime Taken : "<<(double)(clock()-tStart)/CLOCKS_PER_SEC<<"s"<<endl;
        cout<<"\nThe sentence has been checked"<<endl;
    }



  //*********************************************************************************************************************************************




    void merge_sort(string a[], int p, int r)
    {
        int q;
        if(p < r)
    {
        q = floor( (p+r) / 2);
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merger(a, p, q, r);
    }
        }

        void merger(string a[], int p, int q, int r)
        {
            string b[num];     //same size of a[]
            int i, j, k;
            k = 0;
            i = p;
            j = q+1;

        while(i <= q && j <= r)
        {
            if(a[i] < a[j])
        {
            b[k++] = a[i++];       // same as b[k]=a[i]; k++; i++;
        }
            else
        {
            b[k++] = a[j++];
        }
        }

        while(i <= q)
        {
            b[k++] = a[i++];
        }

        while(j <= r)
        {
            b[k++] = a[j++];
        }

        for(i=r; i >= p; i--)
        {
            a[i] = b[--k];        // copying back the sorted list to a[]
        }

        }


};

#endif // STACK_H_INCLUDED
