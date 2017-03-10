/*
*   Authored by Christopher Madrigal
*   Non-recursive implementation and demonstration of solveTowers,
*   an algorithm to solve a game of Towers of Hanoi.
*/

#include <iostream>
#include "StackP.h"
using namespace std;

//prototype for iterative solveTowers
void solveTowers(int);

int main()
{
	int count; //holds user's input

	do
	{
	cout << "Count: ";
	cin >> count;

	//print steps
	solveTowers(count);
	cout << endl;

	}
	//while user's input remains > 0
	while(count > 0);

	return 0; //end program
}

//iterative definition of solveTowers
void solveTowers(int count)
{
	//holds states of each peg
	stackClass A, B, C;
	//holds the tops of whichever stacks being compared
	stackItemType first, second;
	//needed for calls to stack methods, ignored
	bool ok;

	//push integers onto A, each representing a disc on a peg
	for(stackItemType n = count; n >= 1; n--)
	{
		A.Push(n, ok);
	}

	/*
	If the count of discs is odd, then our strategy is to make moves between A and B,
	then between A and C, and finally between B and C, until both pegs A and C are empty.
	*/
	while(count%2 == 1)
	{
		//check the tops of A and B
		A.GetStackTop(first, ok);
		B.GetStackTop(second, ok);

		//if A was empty, move from B to A
		if(A.StackIsEmpty())
		{
			B.Pop(second,ok);
			A.Push(second,ok);
			cout << "Move from B to A" << endl;
		}
		//if B was empty, move from A to B
		else if(B.StackIsEmpty())
		{
			A.Pop(first,ok);
			B.Push(first,ok);
			cout << "Move from A to B" << endl;
		}
		//if the top of A is bigger than that of B, move from B to A
		else if(first > second)
		{
			B.Pop(second,ok);
			A.Push(second,ok);
			cout << "Move from B to A" << endl;
		}
		//if all else, move from A to B
		else
		{
			A.Pop(first,ok);
			B.Push(first,ok);
			cout << "Move from A to B" << endl;
		}

		//make moves between A and C
		//if both A and C are empty, we are done.
		if(A.StackIsEmpty() && C.StackIsEmpty())
			break;

		A.GetStackTop(first, ok);
		C.GetStackTop(second, ok);
		if(A.StackIsEmpty())
		{
			C.Pop(second,ok);
			A.Push(second,ok);
			cout << "Move from C to A" << endl;
		}
		else if(C.StackIsEmpty())
		{
			A.Pop(first,ok);
			C.Push(first,ok);
			cout << "Move from A to C" << endl;
		}
		else if(first > second)
		{
			C.Pop(second,ok);
			A.Push(second,ok);
			cout << "Move from C to A" << endl;
		}
		else
		{
			A.Pop(first,ok);
			C.Push(first,ok);
			cout << "Move from A to C" << endl;
		}

		//make moves between B and C
		B.GetStackTop(first, ok);
		C.GetStackTop(second, ok);

		if(B.StackIsEmpty())
		{
			C.Pop(second,ok);
			B.Push(second,ok);
			cout << "Move from C to B" << endl;
		}
		else if(C.StackIsEmpty())
		{
			B.Pop(first,ok);
			C.Push(first,ok);
			cout << "Move from B to C" << endl;
		}
		else if(first > second)
		{
			C.Pop(second,ok);
			B.Push(second,ok);
			cout << "Move from C to B" << endl;
		}
		else
		{
			B.Pop(first,ok);
			C.Push(first,ok);
			cout << "Move from B to C" << endl;
		}
	}
	
	/*
	If the count of discs is even, then the strategy makes moves between A and C first,
	checking each iteration if both are empty which means we have solved the game.
	*/
	while(count%2 == 0)
	{
		//make moves between A and C
		A.GetStackTop(first, ok);
		C.GetStackTop(second, ok);

		if(A.StackIsEmpty() && C.StackIsEmpty())
			break;

		if(A.StackIsEmpty())
		{
			C.Pop(second,ok);
			A.Push(second,ok);
			cout << "Move from C to A" << endl;
		}
		else if(C.StackIsEmpty())
		{
			A.Pop(first,ok);
			C.Push(first,ok);
			cout << "Move from A to C" << endl;
		}
		else if(first > second)
		{
			C.Pop(second,ok);
			A.Push(second,ok);
			cout << "Move from C to A" << endl;
		}
		else
		{
			A.Pop(first,ok);
			C.Push(first,ok);
			cout << "Move from A to C" << endl;
		}
			
		//make moves between A and B
		A.GetStackTop(first, ok);
		B.GetStackTop(second, ok);

		if(A.StackIsEmpty())
		{
			B.Pop(second,ok);
			A.Push(second,ok);
			cout << "Move from B to A" << endl;
		}
		else if(B.StackIsEmpty())
		{
			A.Pop(first,ok);
			B.Push(first,ok);
			cout << "Move from A to B" << endl;
		}
		else if(first > second)
		{
			B.Pop(second,ok);
			A.Push(second,ok);
			cout << "Move from B to A" << endl;
		}
		else
		{
			A.Pop(first,ok);
			B.Push(first,ok);
			cout << "Move from A to B" << endl;
		}

		//make moves between B and C
		B.GetStackTop(first, ok);
		C.GetStackTop(second, ok);
		
		if(B.StackIsEmpty())
		{
			C.Pop(second,ok);
			B.Push(second,ok);
			cout << "Move from C to B" << endl;
		}
		else if(C.StackIsEmpty())
		{
			B.Pop(first,ok);
			C.Push(first,ok);
			cout << "Move from B to C" << endl;
		}
		else if(first > second)
		{
			C.Pop(second,ok);
			B.Push(second,ok);
			cout << "Move from C to B" << endl;
		}
		else
		{
			B.Pop(first,ok);
			C.Push(first,ok);
			cout << "Move from B to C" << endl;
		}
	}
}
