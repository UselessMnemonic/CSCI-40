// *********************************************************
// Implementation file QueueP.cpp for the ADT queue.
// Pointer-based implementation.
// *********************************************************
#include "QueueP.h" // header file
#include <cstddef>
#include <cassert>

Queue::Queue() : backPtr(NULL), frontPtr(NULL)
{
} // end default constructor

  /*Queue::Queue(const Queue&Q)
  { // Implementation left as an exercise (Exercise 4).
  } // end copy constructor*/

Queue::~Queue()
{
	bool success;
	while (!isEmpty())
		dequeue(success);
	// Assertion: frontPtr and backPtr equal NULL
} // end destructor

bool Queue::isEmpty() const
{
	return bool(backPtr == NULL);
} // end isEmpty

void Queue::enqueue(QueueItemType newItem, bool & success)
{
	// create a new node
	QueueNode *newPtr = new QueueNode;

	if (newPtr == NULL) // check allocation
		success = false;
	else
	{
		success = true;
		// allocation successful; set data portion of new node
		newPtr->item = newItem;
		newPtr->next = NULL;
		// insert the new node
		if (isEmpty())
			// insertion into empty queue
			frontPtr = newPtr;
		else
			// insertion into nonempty queue
			backPtr->next = newPtr;
		backPtr = newPtr; // new node is at back
	} // end if
} // end enqueue

void Queue::dequeue(bool & success)
{
	if (isEmpty())
		success = false;
	else
	{
		success = true;
		// queue is not empty; remove front
		QueueNode *tempPtr = frontPtr;
		if (frontPtr == backPtr) // special case?
		{ // yes, one node in queue
			frontPtr = NULL;
			backPtr = NULL;
		}
		else
			frontPtr = frontPtr->next;

		tempPtr->next = NULL; // defensive strategy
		delete tempPtr;
	} // end if
} // end dequeue

void Queue::dequeue(QueueItemType& queueFront, bool& success)
{
	if (isEmpty())
		success = false;
	else
	{
		success = true;
		// queue is not empty; retrieve front
		queueFront = frontPtr->item;
		dequeue(success); // delete front
	} // end if
} // end dequeue

void Queue::getFront(QueueItemType& queueFront, bool& success) const
{
	if (isEmpty())
		success = false;
	else
	{
		success = true;
		// queue is not empty; retrieve front
		queueFront = frontPtr->item;
	}
} // end getFront
  // End of implementation file. 