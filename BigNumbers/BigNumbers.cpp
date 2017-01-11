/* Christopher Madrigal
BigNumbers.cpp : Defines the entry point for the console application.

Big Number layout

int[0] -> first digit (ones)
int[1] -> second digit (tens)
int[2] -> third digit (hundreds)
.
.
.
int[MAX_DIGITS] -> last digit

*/

#include "stdafx.h" //<- need to get rid of this for GNU Make
#include <iostream>
#include <string>
using namespace std;

const int MAX_DIGITS = 100;

void addBig(int first[], int second[], int sum[]); //adds two numbers with max digits MAX_DIGITS and stores their sum into sum
void printBig(int num[]); //prints the big number onto the console
void readBig(int num[]); //parse a big number of up to MAX_DIGITS digits and store elements into num

int main()
{
	string dummy; //for use in a portable windows-like exit prompt

	int oneBigNumber[MAX_DIGITS];
	int anotherBigNumber[MAX_DIGITS];
	int sumOfBigNumbers[MAX_DIGITS];

	cout << "Please input a big number: ";
	readBig(oneBigNumber);
	cout << endl << endl;

	cout << "Please input another big number: ";
	readBig(anotherBigNumber);
	cout << endl << endl;

	cout << "Thier sum is: ";
	addBig(oneBigNumber, anotherBigNumber, sumOfBigNumbers);
	printBig(sumOfBigNumbers);
	cout << endl << endl;

	/*cout << "\nHit Enter to exit...\n"; //prompt user for exit confirmation
	cin.ignore();
	getline(cin, dummy);*/

	return 0; //end without error
}

void addBig(int first[], int second[], int sum[])
{
	int i = 0;
	int j = 0;

	while(i < MAX_DIGITS) //Get the sum of each corresponding digit
	{
		sum[i] = first[i] + second[i]; //set sum
		i++;
	}

	while(j < MAX_DIGITS-1 ) //thankfully, largest sum of any two digits and a carry is 19, so no complex multiple carries (but how crazy would that be huh?)
	{
		
		if(sum[j] > 9) //if we need to carry from digit in sum[j]...
		{
			sum[j+1]++; //increase the following digit by one
			sum[j] -= 10; //subtract ten from this digit
		}

		j++;
	}
}

void printBig(int num[])
{
	//int periodicComma = 0; //will trigger printing a comma
	int i = MAX_DIGITS-1; //start from the begining of the array

	while(num[i] == 0 && i != 0) //proceed until leading 0's are skipped, until last digit, which may be a zero, in which case it is necessary to print
	{
		i--;
	}

	//periodicComma = i % 3; //every 3 digits needs a comma, we can figure out when to print one going backwards by mod(i,3), which gives us the number of digits left to print before needing the first comma

	while(i >= 0) //for the rest of the significant digits...
	{
		cout << num[i]; //...print in proper order

		/*if (periodicComma == 0 && i != 0) //print comma only when needed (remove this block if necessary)
		{
			cout << ',';
			periodicComma = 3; //after the first comma, we can be sure that our counter starts at 3
		}
		periodicComma--;*/

		i--;
	}

}

void readBig(int num[])
{
	int i = MAX_DIGITS-1; //start our counter at MAX_DIGITS-1 for index

	string numString; //string to store user input
	cin >> numString; //get the user input
	long numberStartPosition = numString.length() - 1; //index for the start of the number is the same as the length of the number minus 1

	while(i > numberStartPosition) //this will set all leading digits to 0...
	{
		num[i] = 0;
		i--; //... moving down the array until we hit where the number begins; this will leave i equaling numberStartPosition
	}

	while(i >= 0) //then, we parse each digit in the string
	{
		num[i] = numString.at(numberStartPosition - i) - 48; //get the number from the corresponding ASCII character in the string, parsing backwards. ASCII ARITH LIKE THIS IS VERY PRONE TO ERRORS 
		i--;
	}
}