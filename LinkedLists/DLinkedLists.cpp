#include "DLinkedLists.h"
#include <iostream>
#include <stddef.h>
using namespace std;

DList::DList() //Constructs a new DList object with a NULL head Node.
{
	size = 0;
	head = NULL;
}

DList::~DList() //Deconstructs the object.
{
	bool success = true; //needed to pass to remove
	while (!isEmpty()) //while the DList is not empty, remove item at index 1
	{
		remove(1, success);
	}
}

DList::DList(const DList &otherDList) //Copy Constructor; copies all elements in the previous DList
{
	size = otherDList.size; //gets size
	DListNode* currentNode;

	if (otherDList.head == NULL) //If the other DList has a null head Node, set this one's to NULL
	{
		head = NULL;
	}
	else
	{
		head = new DListNode; //...otherwise, set head to a new DListNode
		head->item = otherDList.head->item; //copy the otherDList's head item into ours
		currentNode = head;

		for (DListNode* nodeInOtherDList = otherDList.head->next; nodeInOtherDList != otherDList.head; nodeInOtherDList = nodeInOtherDList->next) //for every following node in otherDList that does not point to our head
		{
			currentNode->next = new DListNode; //point currentNode to a new Node
			currentNode->next->prev = currentNode; //retro-point the new Node to the current one
			currentNode->next->item = nodeInOtherDList->item; //copy the corresponding item
			currentNode = currentNode->next; //advance currentNode into the new Node
		}

		currentNode->next = head; //point our last node to our head
		head->prev = currentNode; //retro-point our head to our last node
	}
}

bool DList::isEmpty() const //returns whether or not the DList length is 0
{
	return (size == 0);
}

int DList::getLength() const //returns the DList's length
{
	return size;
}

void DList::insert(int index, ListItemType newItem, bool &success) //insert a valid node into the DList at the specified index
{
	int newSize = getLength() + 1; //get the size of the new DList
	DListNode* newNode;
	DListNode* targetNode;

	success = (index >= 1 && index <= newSize); //validate that our index will be between 1 and newLength, inclusive

	if(success)//if we can insert into our DList...
	{
		size = newSize; //set our size
		newNode = new DListNode; //create a new Node
		newNode->item = newItem; //give our new Node the item
		
		if(index == 1)
		{
			if(head == NULL) //create the head Node and point it to NULLs
			{
				head = newNode;
				head->next = NULL;
				head->prev = NULL;
			}
			else //place our new node as head
			{
				newNode->next = head;
				newNode->prev = NULL;
				head->prev = newNode;
				head = newNode;
			}
		}
		else
		{
			targetNode = find(index); //grab our target
			newNode->next = targetNode->next; //point our newNode to the node after our target

			if(targetNode->next != NULL)
				targetNode->next->prev = newNode; //retro-point the node after our target to the new node, if the former exists

			targetNode->next = newNode; //point our target to our new node
			newNode->prev = targetNode; //retro-point our new new node to the target
		}
	}
}

void DList::remove(int index, bool &success)
{
	success = index >= 1 && index <= getLength();
	DListNode* targetNode;
	DListNode* beforeTarget;
	DListNode* afterTarget;

	if (success)
	{
		--size;

		if(index == 1)
		{
			afterTarget = head->next;
			delete head;
			head = NULL;
			if(afterTarget != NULL)
				head = afterTarget;
		}
		else
		{
			targetNode = find(index); //get the target node
			beforeTarget = targetNode->prev; //get the node before our target

			//link the nodes before and after our target
			beforeTarget->next = targetNode->next;
			afterTarget = targetNode->next;
			if(afterTarget != NULL)
			{
				targetNode->next->prev = beforeTarget; 
			}

			// return target node to system
			targetNode->next = NULL;
			targetNode->prev = NULL;
			delete targetNode;
			targetNode = NULL;
		}
	}
}

void DList::retrieve(int index, ListItemType &dataItem, bool &success) const
{
	success = index >= 1 && index <= getLength();
	if(success)
	{
		DListNode* targetNode = find(index);
		dataItem = targetNode->item;

		if(targetNode->prev != NULL)
			cout << "Item before node: " << targetNode->prev->item << endl;
		if(targetNode->next != NULL)
			cout << "Item after node: " << targetNode->next->item << endl;
	}
}

DList::DListNode* DList::find(int index) const
{
	if ( index < 1 || index > getLength() )
        return NULL;

	int location = 1;
	DListNode* currentNode = head;
	while(location != index) //loop untill we reach our destination, and save a pointer to the desired node
	{
		currentNode = currentNode->next;
		location++;
	}
	return currentNode;
}