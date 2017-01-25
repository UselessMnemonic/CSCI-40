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

void fillNode(node* entry, int times, int data[])
{
	node* current;
	current = entry;

	for(int x = 1; x <= times && current != NULL; x++)
	{
		current->data = data[x-1];
		current = current->next;
	}
}

node* createList(int size)
{
	node* list;
	node* current;

	list = new node;
	list->next = NULL;

	current = list;

	for(int x = 1; x < size; x++)
	{
		current->next = new node;
		current = current->next;
		current->next = NULL;
	}

	return list;
}

void deleteList(node* entry)
{
	node* current = entry;

	int numberOfEntries = 0;

	while(current != NULL && current->next != NULL)
	{
		current = current->next;
		numberOfEntries++;
	}

	while(numberOfEntries > 0)
	{
		current = entry;

		for(int x = 1; x < numberOfEntries-1; x++)
		{
			current = current->next;
		}

		delete current;
		numberOfEntries--;
	}
}

void printNode(node* entry)
{
	node* current;
	current = entry;

	for(int x = 1; x <= times; x++)
	{
		cout<<"---------"<< endl;
		cout<<"|Node " << setw(2) << x << '|' << endl;
		cout<<'|' << setw(7) << current->data << '|' << endl;
		cout<<"---------"<< endl;
		cout << "|\nV" << endl;
		
		if(current->next == NULL)
		{
			break;
		}

		current = current->next;
	}
}

int main()
{
	node* first = createList(10);
	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	fillNode(first, 10, data);
	printNode(first, 10);
	deleteList(first);
	first = NULL;
	return 0;
}