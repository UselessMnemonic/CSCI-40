/*
*   Authored by Christopher Madrigal
*   Non-recursive implementation and demonstration of solveTowers,
*   an algorithm to solve a game of Towers of Hanoi
*/

#include <iostream>
#include "StackP.h"
using namespace std;

stackClass pegA, pegB, pegC;

void solveTowers(int, char, char, char), solveTowers(int);

int main()
{
	int count;

	do{
	cout << "Count: ";
	cin >> count;

	cout << "--START RECURSIVE--" << endl;
	solveTowers(count, 'A', 'B', 'C');
	cout << "--END RECURSIVE--" << endl << endl;

	cout << "--START ITERATIVE--" << endl;
	solveTowers(count);
	cout << "--END ITERATIVE--" << endl;
	}while(count > 0);
	return 0;
}

//recursive definition of solveTowers
void solveTowers(int count, char source, char destination, char spare)
{
	if (count == 1)
	{
		cout << "Move from " << source << " to " << destination << endl;
	}
	else
	{
		solveTowers(count - 1, source, spare, destination);
		solveTowers(1, source, destination, spare);
		solveTowers(count - 1, spare, destination, source);
	}
}

//iterative definition of solveTowers
void solveTowers(int count)
{
	stackClass A, B, C;
	stackItemType first, second;
	bool ok;

	for(stackItemType n = count; n >= 1; n--)
	{
		A.Push(n, ok);
	}

	if(count%2 == 1)
	{
		while(true)
		{
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


			//make moves between A and C
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
	}
	else
	{
		while(true)
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
}