/* Authored by Christopher Madrigal
Test Program for BigNumber class
20 January 2017
*/

#include "BigNumber.h"
#include <iostream>
using namespace std;

int main()
{
	BigNumber aNumber; //store first user number
	BigNumber anotherNumber; //store second user number
	BigNumber thirdNumber; //store result of sum

	cout << "Please enter a number of up to " << MAX_DIGITS << " digits in legnth: "; //prompt for number
	cin >> aNumber; //read number from cin
	cout << "You entered: ";
	cout << aNumber; //validate user's input
	cout << endl << endl; //move two lines

	cout << "Please enter another number: ";
	cin >> anotherNumber;
	cout << "You entered: ";
	cout << anotherNumber;
	cout<< endl << endl;

	thirdNumber = aNumber + anotherNumber; //get sum of user input

	cout << "The sum of these numbers is: ";
	cout << thirdNumber; //print sum
	cout << endl << endl;

	return 0;
}