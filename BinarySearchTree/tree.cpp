//Test program for binary search tree.
//Note the includes at the beginning of each file.
//Christopher Madrigal

#include "BST.h"//Binary search tree header file.

//This is the "Visit" procedure.
void PrintKeyAndData(treeItemType&);

int main()
{
bstClass tree;
treeItemType MyItem;
int key;
string data;
char command;
bool Success,done=false;

while(!done)
    {
    cout<<"\n(I)nsert\n"
        <<"(D)elete\n"
        <<"(R)etrieve\n"
        <<"(T)raverse\n"
        <<"(Q)uit\n";
    cin>>command;
    cin.ignore(300,'\n');
    command=toupper(command);
    switch(command)
        {
        case 'I':
            cout<<"enter Search Key (integer):";
            cin>>key;
            cout<<"enter Data (string):";
            cin>>data;
            MyItem.SetSearch(key);
            MyItem.SetData(data);
            tree.SearchTreeInsert(MyItem,Success);
            if (Success)
                cout<<"item inserted\n";
            else
                cout<<"insert failed\n";
            break;
        case 'D':
            cout<<"enter Search Key (integer):";
            cin>>key;
            MyItem.SetSearch(key);
            tree.SearchTreeDelete(MyItem.Key(),Success);
            if (Success)
                cout<<"item deleted\n";
            else
                cout<<"delete failed\n";
            break;
        case 'R':
            cout<<"enter Search Key (integer):";
            cin>>key;
            MyItem.SetSearch(key);
            tree.SearchTreeRetrieve(key,MyItem,Success);
            if (Success)
                cout<<MyItem.GetData()<<" retrieved\n";
            else
                cout<<"retrieve failed\n";
            break;
        case 'T':
            tree.InorderTraverse(PrintKeyAndData);
            break;
        case 'Q':
            done=true;
            break;
        default:
            cout<<"invalid command\n";
        }
    }
return 0;
}

//I visit a node by printing its contents.
void PrintKeyAndData(treeItemType& MyItem)
{
cout<<MyItem.Key()<<"-"<<MyItem.GetData()<<" ";
}