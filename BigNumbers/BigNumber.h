/* Authored by Christopher Madrigal
20 January 2017

Big Number layout

int[0] -> first digit (ones)
int[1] -> second digit (tens)
int[2] -> third digit (hundreds)
.
.
.
int[MAX_DIGITS-1] -> last digit

*/
#include <iostream>
using namespace std;

const int MAX_DIGITS = 100;

class BigNumber
{
	friend ostream& operator<<(ostream&, BigNumber); //inserts the string value of BigNumber into stream
	friend istream& operator>>(istream&, BigNumber&); //extracts a BigNumber from stream
public:
	BigNumber(int);
	BigNumber();
	BigNumber operator+(BigNumber); //returns the sum of two BigNumber
	BigNumber operator++(); //increments the BigNumber
	bool      operator<(BigNumber); //checks to see if this BigNumber is less than another
	bool      operator>(BigNumber); //checks to see if this BigNumber is greater than another
	bool      operator==(BigNumber); //checks to see if BigNumbers are equal
private:
	int digits[MAX_DIGITS]; //stores the value of BigNumber object
};
