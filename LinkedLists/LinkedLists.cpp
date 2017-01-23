#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
	int data;
	node* next;
};

/*
PRINTOUT

---------
|Node ##|
|(Data )|
---------
|
V
*/

void fillNode(node* entry, int times, int data[], bool construct)
{
	node* current;
	current = entry;
	for(int x = 1; x <= times; x++)
	{
		current->data = data[x-1];
		cout << "current(" << x << ")->data = " << data[x-1];
		if(construct)
			current->next = new node;
		current = current->next;
	}
}

void printNode(node* entry, int times)
{
	node* current;
	current = entry;
	for(int x = 1; x <= times; x++)
	{
		cout<<"---------"<<endl;
		cout<<"|Node " << setw(2) << x << '|' << endl;
		cout<<'|' << setw(7) << current->data << '|' << endl;
		cout<<"---------"<<endl;

		if(current->next != nullptr)
			cout << "|\nV" << endl;
		else
			break;

		current = current->next;
	}
}

int main()
{
	node* first = new node;
	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	fillNode(first, 10, data, true);
	printNode(first, 10);
	return 0;
}