/* Authored by Christopher Madrigal
1 March 2017

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

BigNumber::BigNumber(int n)
{
	int i = 0;
	while(n > 0)
	{
		digits[i] = n%10;
		n /= 10;
		i++;
	}
	while(i<=MAX_DIGITS-1)
	{
		digits[i] = 0;
		i++;
	}
}

BigNumber::BigNumber(BigNumber& otherNumber)
{
	setDigits(otherNumber.digits);
}

BigNumber::BigNumber()
{
	for(int i = 0; i <= MAX_DIGITS-1; i++)
		digits[i] = 0;
}

BigNumber BigNumber::operator+(BigNumber otherNumber) //returns a BigNumber from the sum of this BigNumber and the argument 
{
	int i = 0;
	int j = 0;
	BigNumber sum;

	while(i <= MAX_DIGITS-1) //Get the sum of each corresponding digit
	{
		sum.digits[i] = digits[i] + otherNumber.digits[i]; //set sum
		i++;
	}

	while(j <= MAX_DIGITS-2 ) //conduct carry
	{
		
		if(sum.digits[j] > 9) //if we need to carry from digit in sum.value[j]...
		{
			sum.digits[j+1]++; //increase the following digit sum.value[j+1] by one
			sum.digits[j] -= 10; //subtract ten from sum.value[j]
		}
		j++;
	}

	return sum; //returns the sum object
}

BigNumber BigNumber::operator++()
{
	//set this object's digits to those of the sum of this number and 1
	this->setDigits((*this + 1).digits);
	return *this; //then return
}

BigNumber BigNumber::operator++(int num)
{
	BigNumber copy(*this); //must return a copt of the current value

	operator++(); //call preincrement 

    return copy; //return original value
}

BigNumber BigNumber::operator+=(BigNumber otherNumber)
{
	//set this object's digits to those of other number
	setDigits((otherNumber + *this).digits);
	return *this;
}

bool BigNumber::operator<(BigNumber other)
{
	int i = MAX_DIGITS-1; //start at most significant
	do
	{
		//move down if digits are same
		if(digits[i] == other.digits[i]) 
			i--;

		else //result of this check is result for entire operation
			return digits[i] < other.digits[i];
	}
	while(i >= 0);

	return false; //reaching the end means the numbers are equal
}

bool BigNumber::operator>(BigNumber other)
{
	int i = MAX_DIGITS-1; //start at most significant
	do
	{
		//move down if digits are same
		if(digits[i] == other.digits[i]) 
			i--;

		else //result of this check is result for entire operation
			return digits[i] > other.digits[i];
	}
	while(i >= 0);

	return false; //reaching the end means the numbers are equal
}

bool BigNumber::operator==(BigNumber other)
{
	if (this == &other)
		return true;

	bool equal = true;
	int i = 0;

	do
	{
		equal = digits[i] == other.digits[i]; //check if digits are same
	}
	 //stop when any digits are not equal or all have been checked
	while (i <= MAX_DIGITS-1 && equal);

	return equal;
}

void BigNumber::setDigits(int newDigits[MAX_DIGITS])
{
	for (int i = 0; i <= MAX_DIGITS - 1; i++)
		digits[i] = newDigits[i];
}

ostream& operator<<(ostream& out, BigNumber toPrint) //prints the value of this BigNumber
{
	int i = MAX_DIGITS-1; //start from the begining of the value array

	while(toPrint.digits[i] == 0 && i != 0) //proceed until leading 0's are skipped, except in the one's digit
	{
		i--;
	}

	while(i >= 0) //for the rest of the significant digits...
	{
		out << toPrint.digits[i]; //...print in proper order
		i--;
	}
	return out; //return the output stream for chain insertions
}

istream& operator>>(istream& in, BigNumber& toSave) //pasrses value from cin into this BigNumber
{
	int i = MAX_DIGITS-1; //start our counter at MAX_DIGITS-1 for index

	string numString; //string to store user input
	in >> numString; //get the user input

	long numberStartPosition = numString.length() - 1; //index for the start of the number is the same as the length of the number minus 1

	while(i >= numberStartPosition+1) //this will set all leading digits to 0...
	{
		toSave.digits[i] = 0;
		i--; //... moving down the array until we hit where the number begins; this will leave i equaling numberStartPosition
	}

	while(i >= 0) //then, we parse each digit in the string
	{
		toSave.digits[i] = numString.at(numberStartPosition - i) - '0'; //get the number from the corresponding character in string
		i--;
	}
	return in; //return the input stream for chain extractions
}

