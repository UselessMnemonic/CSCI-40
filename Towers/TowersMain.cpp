/*
*   Authored by Christopher Madrigal
*   Non-recursive implementation and demonstration of solveTowers,
*   an algorithm to solve a game of Towers of Hanoi.
*/

#include <iostream>
#include "StackP.h"
using namespace std;

//prototype for iterative solveTowers
void solveTowersItr(int count, char source, char destination, char spare);
//prototype for recursive solveTowers
void solveTowersRec(int count, char source, char destination, char spare);
//returns a state struct
towerState makeState(int count, char source, char destination, char spare);

int main()
{
	int count; //holds user's input

	do
	{
	cout << "Count: ";
	cin >> count;

	//print steps
	cout << "Recursive:" << endl;
	solveTowersRec(count, 'A', 'B', 'C');
	cout << "Iterative:" << endl;
	solveTowersItr(count, 'a', 'b', 'c');
	cout << endl;

	}
	//while user's input remains > 0
	while(count > 0);

	return 0; //end program
}

void solveTowersRec(int count, char source, char destination, char spare)
{
	if (count == 1)
		cout << "Move from " << source << " to " << destination << endl;
	else
	{
		solveTowersRec(count - 1, source, spare, destination);
		solveTowersRec(1, source, destination, spare);
		solveTowersRec(count - 1, spare, destination, source);
	}
}

towerState makeState(int count, char source, char destination, char spare)
{
	towerState state = { count, source, destination, spare };
	return state;
}

void solveTowersItr(int count, char source, char destination, char spare)
{
	stackClass stack;
	bool ok = true;

	towerState state = makeState(count, source, destination, spare), nextState;

	stack.Push(state, ok);

	while (!stack.StackIsEmpty())
	{
		stack.Pop(state, ok);

		if(state.count == 1)
			cout << "Move from " << state.source << " to " << state.destination << endl;
		else
		{
			nextState = makeState(state.count - 1, state.spare, state.destination, state.source);
			stack.Push(nextState, ok);

			nextState = makeState(1, state.source, state.destination, state.spare);
			stack.Push(nextState, ok);

			nextState = makeState(state.count - 1, state.source, state.spare, state.destination);
			stack.Push(nextState, ok);
		}
	}
}