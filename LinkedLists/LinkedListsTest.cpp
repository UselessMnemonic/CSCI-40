/* Christopher Madrigal
*  LinkedListsTest.cpp
*  DLinkedList test program
*/
#include <iostream>
using namespace std;
#include "DLinkedLists.h"
int main()
    {
    ListItemType item;
    bool Success,done;
    char choice;
    int where;
    DList L;
    done=false;
    while (!done)
        {
        //print menu
        cout<<"\n\n(I)nsert an item\n"
        <<"(D)elete an item\n"
        <<"(R)etrieve an item\n"
        <<"(L)ength of list\n"
        <<"(Q)uit\n";
        //get choice
        cout<<"?";
        cin>>choice;
        //execute command
        switch (choice)
            {
            case 'd':
            case 'D':
                cout<<"What position?\n";
                cin>>where;
                L.remove( where, Success);
                if(Success)
                    cout<<"Successful!\n";
                else
                    cout<<"Not successful\n";
                break;
            case 'i':
            case 'I':
                cout<<"What position?\n";
                cin>>where;
                cout<<"What item?\n";
                cin>>item;
                L.insert( where, item, Success);
                if(Success)
                    cout<<"Successful!\n";
                else
                    cout<<"Not successful\n";
                break;
            case 'r':
            case 'R':
                cout<<"What position?\n";
                cin>>where;
                L.retrieve( where, item, Success);
                if(Success)
                    {
                    cout<<"Successful!\n";
                    cout<<"Item retrieved: "<<item<<endl;
                    }
                else
                    cout<<"Not successful\n";
                break;
            case 'l':
            case 'L':

                cout<<"Length: "<<L.getLength( )<<endl;
                break;
            case 'Q':
            case 'q':
                done=true;
                break;
            }
        }

    }