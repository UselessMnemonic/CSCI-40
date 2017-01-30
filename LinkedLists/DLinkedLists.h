typedef int ListType;

class DList
    {
    public:
        DList();                     // default constructor
        DList(const DList& DL);    //copy Constructor
        ~DList();                //Destructor

        bool isEmpty() const;
        // Determines whether a list is empty.
        // Precondition: None.
        // Postcondition: Returns true if the list is empty;
        // otherwise returns false.

        int getLength() const;
        // Determines the length of a list.
        // Precondition: None.
        // Postcondition: Returns the number of items
        // that are currently in the list.

        void insert(int index, ListType newItem, bool &success);
        // Inserts an item into the list at position index.
        // Precondition: index indicates the position at which
        // the item should be inserted in the list.
        // Postcondition: If insertion is successful, newItem is
        // at position index in the list, and other items are
        // renumbered accordingly, and success is true;
        // otherwise success is false.
        // Note: Insertion will not be successful if
        // index < 1 or index > getLength()+1.

        void remove(int index, bool &success);
        // Deletes an item from the list at a given position.
        // Precondition: index indicates where the deletion
        // should occur.
        // Postcondition: If 1 <= index <= getLength(),
        // the item at position index in the list is
        // deleted, other items are renumbered accordingly,
        // and success is true; otherwise success is false.

        void retrieve(int index, ListType &dataItem, bool& success) const;
        // Retrieves a list item by position.
        // Precondition: index is the number of the item to
        // be retrieved.
        // Postcondition: If 1 <= index <= getLength(),
        // dataItem is the value of the desired item and
        // success is true; otherwise success is false.

    private:
        struct DListNode // a node in the list
		{
			ListType item; // a data item on the list
			DListNode* next; // pointer to next node
			DListNode* prev;
		}; // end struct

        int size; // number of items in list
        DListNode* head; // pointer to linked list of items

        DListNode* find(int index) const;
        // Returns a pointer to the index-th node
        // in the linked list.
    };