#include "LinkedLists.h"

template <typename T> List::List() //Constructs a new List object with a NULL head Node.
{
	size = 0;
	head = NULL;
}

template <typename T> List::~List() //Deconstructs the object.
{
	bool success; //needed to pass to remove
	while (!isEmpty()) //while the list is not empty, remove item at index 1
	{
		remove(1, &success);
	}
}

template <typename T> List::List(const List<T> &otherList) //Copy Constructor; copies all elements in the previous list
{
	size = otherList.size; //gets size

	if (otherList.head == NULL) //If the other list has a null head Node, set this one's to NULL
	{
		head = NULL;
	}
	else
	{
		head = new ListNode; //...otherwise, set head to a new ListNode
		head->item = otherList.head->item; //copy the otherList's head item into ours

		ListNode *currentNode = head; //create a node to iterate over the rest of the nodes in otherList

		for (ListNode *nodeInOtherList = otherList.head->next; nodeInOtherList != NULL; nodeInOtherList = nodeInOtherList->next) //for every following node in otherList...
		{
			currentNode->next = new ListNode; //point currentNode.next to a new Node
			currentNode->next->item = nodeInOtherList->item; //copy the corresponding item
			currentNode = currentNode->next; //advance currentNode into the new Node
		}

		currentNode->next = NULL; //set the currentNode.next pointer to NULL
	}
}

template <typename T> bool List::isEmpty() const //returns whether or not the list length is 0
{
	return (size == 0);
}

template <typename T> int List::getLength() const //returns the list's length
{
	return size;
}

template <typename T> void List::insert(int index, T newItem, bool &success) //insert a valid node into the list at the specified index
{
	int newLength = getLength() + 1; //get the size of the new list

	success = (index >= 1 || index <= size); //validate that our index will be between 1 and newLength, inclusive

	if(success)//if we can insert into our list...
	{
		size = newLength;
		ListNode newNode = new ListNode;
		newNode->item = newItem;

		if (index == 1)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			ListNode *beforeTarget = find(index - 1);
			newNode->next = beforeTarget->next;
			beforeTarget->next = newNode;
		}
	}
}

template <typename T> void List::remove(int index, bool &success)
{
	bool success = index >= 1 && index <= getLength();

	if (success)
	{
		--size;
		if (Position == 1)
		{ // delete the first node from the list
			Cur = head; // save pointer to node
			head = head->next;
		}

		else
		{
			Prev = find(Position - 1);
			// delete the node after the
			// node to which Prev points
			Cur = Prev->next; // save pointer to node
			Prev->next = Cur->next;
		} // end if

		  // return node to system
		Cur->next = NULL;
		delete Cur;
		Cur = NULL;
	} // end if
} // end remove

template <typename T> void List::retrieve(int index, T &dataItem, bool &success) const
{

}

template <typename T> ListNode List::T* find(int index) const
{

}