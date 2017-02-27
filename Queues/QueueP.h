// ********************************************************
// Header file QueueP.h for the ADT queue.
// Pointer-based implementation.
// ********************************************************
struct itemtype
{
	int trans; // transaction time 
	int arrive; // arrival time 
};
typedef itemtype QueueItemType;


class Queue
{
public:
	// constructors and destructor:
	Queue(); // default constructor
			 //Queue(const Queue& Q); // copy constructor
	~Queue(); // destructor

			  // queue operations:
	bool isEmpty() const;
	// Determines whether a queue is empty.
	// Precondition: None.
	// Postcondition: Returns true if the queue is empty;
	// otherwise returns false.

	void enqueue(QueueItemType NewItem, bool& Success);
	// Inserts an item at the back of a queue.
	// Precondition: NewItem is the item to be inserted. 
	// Postcondition: If insertion was successful, NewItem
	// is at the back of the queue and Success is true; 
	// otherwise Success is false.

	void dequeue(bool& Success);
	// Deletes the front of a queue.
	// Precondition: None.
	// Postcondition: If the queue was not empty, the item 
	// that was added to the queue earliest is deleted and 
	// Success is true. However, if the queue was empty, 
	// deletion is impossible and Success is false.

	void dequeue(QueueItemType& QueueFront,
		bool& Success);
	// Retrieves and deletes the front of a queue.
	// Precondition: None.
	// Postcondition: If the queue was not empty, QueueFront 
	// contains the item that was added to the queue 
	// earliest, the item is deleted, and Success is true. 
	// However, if the queue was empty, deletion is 
	// impossible and Success is false.

	void getFront(QueueItemType& QueueFront,
		bool& Success) const;
	// Retrieves the item at the front of a queue.
	// Precondition: None.
	// Postcondition: If the queue was not empty, QueueFront 
	// contains the item that was added to the queue earliest 
	// and Success is true. However, if the queue was empty, 
	// the operation fails, QueueFront is unchanged, and 
	// Success is false. The queue is unchanged.

private:
	// The queue is implemented as a linked list
	// with one external pointer to the front of the queue
	// and a second external pointer to the back of the
	// queue.

	struct QueueNode
	{
		QueueItemType item;
		QueueNode *next;
	}; // end struct
	QueueNode *frontPtr;
	QueueNode *backPtr;
}; // end class
   // End of header file.