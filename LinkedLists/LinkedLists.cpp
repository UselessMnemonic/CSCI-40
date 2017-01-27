#include "LinkedLists.h"

/*
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

	int x = 1;

	while(current != NULL)
	{
		cout<<"---------"<< endl;
		cout<<"|Node " << setw(2) << x << '|' << endl;
		cout<<'|' << setw(7) << current->data << '|' << endl;
		cout<<"---------"<< endl;
		cout << "|\nV" << endl;
		current = current->next;
		x++;
	}

	cout << "0" << endl;
}

int main()
{
	node* first = createList(10);
	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	fillNode(first, 10, data);
	printNode(first);
	deleteList(first);
	first = NULL;
	return 0;
}
*/

template <typename T> List::List()
{
	size = 0;
	head = NULL;
}

template <typename T> List::~List()
{
	bool success; //needed to pass to remove
	while(!isEmpty()) //while the list is not empty, remove item at index 1
		remove(1, &success);
}

template <typename T> List::List(const List<T> &otherList)
{
	size = otherList.size;

	if(otherList.head == NULL)
		head = NULL;

	else
	{
		head = new ListNode;
		head->item = otherList->item;

		ListNode *currentNode = head;

		for(ListNode *nodeInOtherList = otherList.head->next; nodeInOtherList != NULL; nodeInOtherList = nodeInOtherList->next)
		{
			currentNode->next = new ListNode;
			currentNode->next->item = nodeInOtherList->item;
			currentNode = currentNode->next;
		}

		currentNode->next = NULL;
	}
}

template <typename T> bool List::isEmpty() const
{
	return (size == 0);
}

template <typename T> int List::getLength() const
{
	return size;
}

template <typename T> void List::insert(int index, T newItem,bool &success)
{
	size++;
	int newLength = size + 1;

	success = (index >= 1 || index <= size);

	if(success)
	{
		ListNode *beforeTargetNode = find(size-1); //get last node
		beforeTargetNode->next = new ListNode; //set the node pointed to by the last node to a new ListNode
		beforeTargetNode->next->item = newItem; //set the new node's item to newItem
		beforeTargetNode->next->next = NULL; //set the node pointed to by the new node to NULL
	}
	else
	{

	}
}

template <typename T> void List::remove(int index, bool &success)
{

}

template <typename T> void List::retrieve(int index, T &dataItem, bool &success) const
{

}

template <typename T> ListNode List::T* find(int index) const
{

}