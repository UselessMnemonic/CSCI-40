// *********************************************************
// Header file BST.h for the ADT binary search tree.
// Assumption: A tree contains at most one item with a given
// search key at any time.
// *********************************************************
#include <iostream>
using namespace std;
typedef int keyType;//"int" matches the type in itemClass
#include "Data.h" // definition of itemClass

typedef itemClass treeItemType;

typedef void (*functionType)(treeItemType& AnItem);

struct treeNode; // defined in implementation file
typedef treeNode* ptrType; // pointer to node

class bstClass
{
public:
// constructors and destructor:
bstClass(); // default constructor
bstClass(const bstClass& Tree); // copy constructor
virtual ~bstClass(); // destructor

// binary search tree operations:
// Precondition for all methods: No two items in a binary
// search tree have the same search key.

virtual bool SearchTreeIsEmpty() const;
// Determines whether a binary search tree is empty.
// Postcondition: Returns true if the tree is empty;
// otherwise returns false.

virtual void SearchTreeInsert(const treeItemType& NewItem,
bool& Success);
// Inserts an item into a binary search tree.
// Precondition: The item to be inserted into the tree
// is NewItem.
// Postcondition: If the insertion was successful,
// NewItem is in its proper order in the tree and
// Success is true. Otherwise, the tree is unchanged and
// Success is false.

virtual void SearchTreeDelete(keyType SearchKey,
bool& Success);
// Deletes an item with a given search key from a binary
// search tree.
// Precondition: SearchKey is the search key of the item
// to be deleted.
// Postcondition: If the item whose search key equals
// SearchKey existed in the tree, the item is deleted and
// Success is true. Otherwise, the tree is unchanged and
// Success is false.

virtual void SearchTreeRetrieve(keyType SearchKey,
treeItemType& TreeItem,
bool& Success) const;
// Retrieves an item with a given search key from a
// binary search tree.
// Precondition: SearchKey is the search key of the item
// to be retrieved.
// Postcondition: If the retrieval was successful,
// TreeItem contains the retrieved item and Success is
// true. If no such item exists, TreeItem and the tree
// are unchanged and Success is false.

virtual void PreorderTraverse(functionType Visit);
// Traverses a binary search tree in preorder,
// calling function Visit once for each item.
// Precondition: The function represented by Visit
// exists outside of the class implementation.
// Postcondition: Visit's action occurred once for each
// item in the tree.
// Note: Visit can alter the tree.

virtual void InorderTraverse(functionType Visit);
// Traverses a binary search tree in sorted order,
// calling function Visit once for each item.

virtual void PostorderTraverse(functionType Visit);
// Traverses a binary search tree in postorder,
// calling function Visit once for each item.

// overloaded operator:
virtual bstClass& operator=(const bstClass& Rhs);

protected:
void InsertItem(ptrType& TreePtr,
const treeItemType& NewItem,
bool& Success);
// Recursively inserts an item into a binary search tree.
// Precondition: TreePtr points to a binary search tree,
// NewItem is the item to be inserted.
// Postcondition: Same as SearchTreeInsert.

void DeleteItem(ptrType& TreePtr, keyType SearchKey,
bool& Success);
// Recursively deletes an item from a binary search tree.
// Precondition: TreePtr points to a binary search tree,
// SearchKey is the search key of the item to be deleted.
// Postcondition: Same as SearchTreeDelete.

void DeleteNodeItem(ptrType& NodePtr);
// Deletes the item in the root of a given tree.
// Precondition: RootPtr points to the root of a
// binary search tree; RootPtr != NULL.
// Postcondition: The item in the root of the given
// tree is deleted.

void ProcessLeftmost(ptrType& NodePtr,
treeItemType& TreeItem);
// Retrieves and deletes the leftmost descendant of a
// given node.
// Precondition: NodePtr points to a node in a binary
// search tree; NodePtr != NULL.
// Postcondition: TreeItem contains the item in the
// leftmost descendant of the node to which NodePtr
// points. The leftmost descendant of NodePtr is
// deleted.

void RetrieveItem(ptrType TreePtr, keyType SearchKey,
treeItemType& TreeItem,
bool& Success) const;
// Recursively retrieves an item from a binary search
// tree.
// Precondition: TreePtr points to a binary search tree,
// SearchKey is the search key of the item to be
// retrieved.
// Postcondition: Same as SearchTreeRetrieve.

// The following 9 methods are the same as for the ADT
// binary tree, and so their specifications are abbreviated.
void CopyTree(ptrType TreePtr, ptrType& NewTreePtr) const;
void DestroyTree(ptrType& TreePtr);

void Preorder(ptrType TreePtr, functionType Visit);
void Inorder(ptrType TreePtr, functionType Visit);
void Postorder(ptrType TreePtr, functionType Visit);

ptrType RootPtr() const;
void SetRootPtr(ptrType NewRoot);

void GetChildPtrs(ptrType NodePtr, ptrType& LChildPtr,
ptrType& RChildPtr) const;
void SetChildPtrs(ptrType NodePtr, ptrType LChildPtr,
ptrType RChildPtr);

private:
ptrType Root; // pointer to root of tree
}; // end class
// End of header file.



