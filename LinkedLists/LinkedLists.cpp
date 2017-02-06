#include "LinkedLists.h"
#include <stddef.h>

List::List() //Constructs a new List object with a NULL head Node.
{
	size = 0;
	head = NULL;
}

List::~List() //Deconstructs the object.
{
	bool success = true; //needed to pass to remove
	while (!isEmpty()) //while the list is not empty, remove item at index 1
	{
		remove(1, success);
	}
}

List::List(const List& otherList) //Copy Constructor; copies all elements in the previous list
{
	size = otherList.size; //gets size
	ListNode* currentNode;

	if (otherList.head == NULL) //If the other list has a null head Node, set this one's to NULL
	{
		head = NULL;
	}
	else
	{
		head = new ListNode; //...otherwise, set head to a new ListNode
		head->item = otherList.head->item; //copy the otherList's head item into ours

		currentNode = head; //create a node to iterate over the rest of the nodes in otherList

		for (ListNode *nodeInOtherList = otherList.head->next; nodeInOtherList != NULL; nodeInOtherList = nodeInOtherList->next) //for every following node in otherList...
		{
			currentNode->next = new ListNode; //point currentNode.next to a new Node
			currentNode->next->item = nodeInOtherList->item; //copy the corresponding item
			currentNode = currentNode->next; //advance currentNode into the new Node
		}

		currentNode->next = NULL; //set the currentNode.next pointer to NULL
	}
}

bool List::isEmpty() const //returns whether or not the list length is 0
{
	return (size == 0);
}

int List::getLength() const //returns the list's length
{
	return size;
}

void List::insert(int index, ListType& newItem, bool &success) //insert a valid node into the list at the specified index
{
	int newSize = getLength() + 1; //get the size of the new list
	ListNode* newNode;
	ListNode *beforeTarget;

	success = (index >= 1 || index <= newSize); //validate that our index will be between 1 and newLength, inclusive

	if(success)//if we can insert into our list...
	{
		size = newSize; //set our size
		newNode = new ListNode; //create a new Node
		newNode->item = newItem; //give our new Node the item

		if (index == 1) //If our desired location is at the head of the list
		{
			newNode->next = head; //point our new node to the current head
			head = newNode; //set our head to our new node
		}
		else
		{
			beforeTarget = find(index - 1);
			newNode->next = beforeTarget->next; //point our new node to the node pointed to by that node above our target node
			beforeTarget->next = newNode; //point the node above us to the new node
		}
	}
}

void List::remove(int index, bool &success)
{
	success = index >= 1 && index <= getLength();
	ListNode* targetNode;
	ListNode *beforeTarget;

	if (success)
	{
		--size;
		if (index == 1)
		{ // delete the first node from the list
			targetNode = head; // save pointer to node
			head = head->next;
		}

		else
		{
			beforeTarget = find(index - 1);
			//save our target node, and point the node above it to the node below it
			targetNode = beforeTarget->next; // save pointer to node
			beforeTarget->next = targetNode->next;
		} // end if

		  // return node to system
		targetNode->next = NULL;
		delete targetNode;
		targetNode = NULL;
	} // end if
} // end remove

void List::retrieve(int index, ListType& dataItem, bool &success) const
{
	success = index >= 1 && index <= getLength();
	if(success)
	{
		ListNode* targetNode = find(index);
		dataItem = targetNode->item;
	}
}

List::ListNode* List::find(int index) const
{
	if ( index < 1 || index > getLength() )
        return NULL;

	int location = 1;
	ListNode* currentNode = head;
	while(location != index) //loop untill we reach our destination, and save a pointer to the desired node
	{
		currentNode = currentNode->next;
		location++;
	}
	return currentNode;
}