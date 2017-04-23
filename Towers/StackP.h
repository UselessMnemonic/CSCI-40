// *********************************************************
// Header file StackP.h for the ADT stack.
// Pointer-based implementation.
// *********************************************************

struct stackNode;

struct towerState
{
	int count;
	char source, destination, spare;
};

typedef towerState stackItemType;
    
typedef stackNode* ptrType;

class stackClass
{
public:
// constructors and destructor:
stackClass();                     // default constructor
    stackClass(const stackClass& S);// copy constructor
    ~stackClass();                    // destructor
// stack operations:
bool StackIsEmpty() const;
// Determines whether a stack is empty.
// Precondition: None.
// Postcondition: Returns true if the stack is empty;
// otherwise returns false.

void Push(stackItemType NewItem, bool& Success);
// Adds an item to the top of a stack.
// Precondition: NewItem is the item to be added.
// Postcondition: If insertion was successful, NewItem
// is on the top of the stack and Success is true; 
// otherwise Success is false.

void Pop(bool& Success);
// Removes the top of a stack.
// Precondition: None.
// Postcondition: If the stack was not empty, the item 
// that was added most recently is removed and Success 
// is true. However, if the stack was empty, deletion is 
// impossible and Success is false.

void Pop(stackItemType& StackTop, bool& Success);
// Retrieves and removes the top of a stack.
// Precondition: None.
// Postcondition: If the stack was not empty, StackTop
// contains the item that was added most recently, the 
// item is removed, and Success is true. However, if the
// stack was empty, deletion is impossible, StackTop is 
// unchanged, and Success is false.

void GetStackTop(stackItemType& StackTop, 
bool& Success) const;
// Retrieves the top of a stack.
// Precondition: None.
// Postcondition: If the stack was not empty, StackTop
// contains the item that was added most recently and 
// Success is true. However, if the stack was empty, the 
// operation fails, StackTop is unchanged, and Success 
// is false. The stack is unchanged.

private:
ptrType TopPtr;

}; // end class
// End of header file.