#include "BigNumber.h"
#include <iostream>
using namespace std;

int main()
{
	BigNumber aNumber;
	BigNumber anotherNumber;
	BigNumber thirdNumber;

	aNumber.readBig();

	anotherNumber.readBig();

	thirdNumber = aNumber.addBig(anotherNumber);

	thirdNumber.printBig();

	cout << endl;
	return 0;
}