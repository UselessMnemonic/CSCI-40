// solveTowers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //<- need to get rid of this for GNU Make
#include <iostream>
#include <string>
using namespace std;

void solveTowers(int n, char so, char de, char sp);

int main()
{
	string dummy;

	solveTowers(1, 'b', 'c', 'a');
	
	cout << "\nHit Enter to exit...\n"; //prompt user for exit confirmation
	cin.ignore();
	getline(cin, dummy);
	
	return 0; //end without error
}

void solveTowers(int n, char so, char de, char sp)
{
	cout << "n = " << n << ", so = " <<  so << ", de = " << de << ", sp = " << sp << endl;

	if(n == 1)
		cout << "move from " << so << " to " << de << endl;
	else
	{
		solveTowers(n-1, so, sp, de);
		solveTowers(1, so, de, sp);
		solveTowers(n-1, sp, de, so);
	}
}