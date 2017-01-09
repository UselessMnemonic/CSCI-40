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

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const int MAX_DIGITS = 100;

void addBig(int first[], int second[], int sum[]); //adds two numbers with max digits MAX_DIGITS and stores their sum into sum
void printBig(int num[]); //prints the big number onto the console
void readBig(int num[]); //parse a big number of up to MAX_DIGITS digits and store elements into num

int main()
{
	int oneBigNumber[MAX_DIGITS];
	int anotherBigNumber[MAX_DIGITS];
	int sumOfBigNumbers[MAX_DIGITS];

	cout << "Please input a big number: ";
	readBig(oneBigNumber);
	printBig(oneBigNumber);
	cout << endl << endl;

	cout << "Please input another big number: ";
	readBig(anotherBigNumber);
	printBig(anotherBigNumber);
	cout << endl << endl;

	cout << "Thier sum is: ";
	addBig(oneBigNumber, anotherBigNumber, sumOfBigNumbers);
	printBig(sumOfBigNumbers);



	return 0;
}

void addBig(int first[], int second[], int sum[])
{
	int i = 0;
	int j = 1;

	while(i < MAX_DIGITS) //Get the sum of each corresponding digit
	{
		sum[i] = first[i] + second[i]; //set sum
		i++;
	}

	while(j < MAX_DIGITS ) //thankfully, largest sum of any two digits and a carry is 19, so we don't need to worry about cases where sum[j] % 10 > 1
	{
		if(sum[j-1] > 9) //if we need to carry from this digit...
		{
			sum[j]++; //increase the following digit by one
			sum[j-1] -= 10; //subtract ten from this digit
		}

		j++;
	}
}

void printBig(int num[])
{
	int i = MAX_DIGITS-1;

	while(num[i] == 0) //proceed until leading 0's are skipped
	{
		i--;
	}

	while(i >= 0)
	{
		cout << num[i];
		i--;
	}

}

void readBig(int num[])
{
	int i = MAX_DIGITS-1; //start our counter at MAX_DIGITS-1 for index

	string numString; //string to store user input
	cin >> numString; //get the user input
	int len = numString.length();
	
	if(len > 100) //check if the input is too big
		len = 100;

	while(i > len-1) //this will set all leading digits to 0...
	{
		num[i] = 0;
		i--; //... and move down the array until we hit where the number begins
	}

	while(i >= 0)
	{
		num[i] = numString.at(len - 1 - i) - 48; //get the number from the corresponding ASCII character in the string
		i--;
	}
}