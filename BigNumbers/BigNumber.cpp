/* Authored by Christopher Madrigal

Big Number layout

int[0] -> first digit (ones)
int[1] -> second digit (tens)
int[2] -> third digit (hundreds)
.
.
.
int[MAX_DIGITS-1] -> last digit

*/

#include "BigNumber.h"
#include <iostream>
#include <string>
using namespace std;

BigNumber BigNumber::addBig(BigNumber otherNumber) //returns a BigNumber from the sum of this BigNumber and the argument 
{
	int i = 0;
	int j = 0;

	while(i <= MAX_DIGITS-1) //Get the sum of each corresponding digit
	{
		otherNumber.value[i] = value[i] + value[i]; //set sum
		i++;
	}

	while(j <= MAX_DIGITS-2 ) //conduct carry
	{
		
		if(otherNumber.value[j] > 9) //if we need to carry from digit in sum.value[j]...
		{
			otherNumber.value[j+1]++; //increase the following digit sum.value[j+1] by one
			otherNumber.value[j] -= 10; //subtract ten from sum.value[j]
		}
		j++;
	}

	return otherNumber; //returns the sum object
}

void BigNumber::printBig() //prints the value of this BigNumber
{
	int i = MAX_DIGITS-1; //start from the begining of the value array

	while(value[i] == 0 && i != 0) //proceed until leading 0's are skipped, except in the one's digit
	{
		i--;
	}

	while(i >= 0) //for the rest of the significant digits...
	{
		cout << value[i]; //...print in proper order
		i--;
	}

}

void BigNumber::readBig() //pasrses value from cin into this BigNumber
{
	int i = MAX_DIGITS-1; //start our counter at MAX_DIGITS-1 for index

	string numString; //string to store user input
	cin >> numString; //get the user input

	long numberStartPosition = numString.length() - 1; //index for the start of the number is the same as the length of the number minus 1

	while(i >= numberStartPosition+1) //this will set all leading digits to 0...
	{
		value[i] = 0;
		i--; //... moving down the array until we hit where the number begins; this will leave i equaling numberStartPosition
	}

	while(i >= 0) //then, we parse each digit in the string
	{
		value[i] = numString.at(numberStartPosition - i) - '0'; //get the number from the corresponding character in string
		i--;
	}
}