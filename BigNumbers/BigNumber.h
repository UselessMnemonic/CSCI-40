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

const int MAX_DIGITS = 100;

class BigNumber
{
public:
	void printBig(); //prints the value of this BigNumber
	void readBig(); //pasrses value from cin into this BigNumber
	BigNumber addBig(BigNumber otherNumber); //returns a BigNumber from the sum of this BigNumber and the argument 
private:
	int value[MAX_DIGITS]; //stores the value of BigNumber object
};
