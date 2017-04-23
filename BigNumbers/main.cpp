/* Authored by Christopher Madrigal
1 March 2017
*/

#include "BigNumber.h"
#include <iostream>
using namespace std;

int main()
{
	BigNumber aNumber; //store first user number
	BigNumber anotherNumber; //store second user number
	BigNumber thirdNumber; //store result of sum
	BigNumber fourthNumber; //test += and pre ++

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

	cout << "Please enter a fourth number: "; //get and print a fourth number
	cin >> fourthNumber;
	cout << "You entered: ";
	cout << fourthNumber;
	cout<< endl << endl;

	fourthNumber+=thirdNumber; //test +=
	cout << "The sum of this number and the previous result is: ";
	cout << fourthNumber++; //test ++, post increment should appear next print
	cout << endl << endl;

	cout << "Your fourth number plus one is: ";
	cout << fourthNumber;
	cout << endl << endl;

	cout << "Plus another one: "; //test ++ pre-increment
	cout << ++fourthNumber;
	cout << endl << endl;

	return 0;
}