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

	cout<< "Please enter a number of up to " << MAX_DIGITS << " digits in legnth: "; //prompt for number
	aNumber.readBig(); //read number from cin
	cout << "You entered: ";
	aNumber.printBig(); //validate user's input
	cout<< endl << endl; //move two lines

	cout << "Please enter another number: ";
	anotherNumber.readBig();
	cout << "You entered: ";
	anotherNumber.printBig();
	cout<< endl << endl;

	thirdNumber = aNumber.addBig(anotherNumber); //get sum of user input

	cout << "The sum of these numbers is: ";
	thirdNumber.printBig(); //print sum
	cout << endl << endl;

	return 0;
}