/*
*   Authored by Christopher Madrigal
*   Chapter 5 - 6th ed - Programming Problem #8
*
*   Asks user for a string and determined if the string is a valid expression, as defined recursively below.
*
*   -Grammar-
*   <expression> = <term>|<term> + <term>|<term> - <term>
*   <term> = <factor>|<factor>*<factor>|<factor>/<factor>
*   <factor> = <letter>|(<expression>)
*   <letter> = a|b|...|z
*
*   -Example Infix Expression-
*    a + ( b * c )
*
*    'a' is letter, is term!
*    '(b * c)' is expresion
*    'b * c' is term
*    'b' is letter
*    'c' is letter
*/
#include <iostream>
using namespace std;

//returns true if an expression can be found in the input stream
bool findExpression();

 //returns true if a term can be found in the input stream
bool findTerm();

//returns true if a factor can be found in the input stream
bool findFactor();

int main() //entry point for program
{
	bool isExp;

	while(true)
	{
		isExp = findExpression();

		if(isExp && cin.get() == '\n')
			cout << "Valid Expression" << endl << endl;
		else
			cout << "Invalid Expression" << endl << endl;
	}
}

bool findExpression()
{
	bool hasTerm;
	char nextChar;

	hasTerm = findTerm();

	cin >> nextChar;
	cout << "Next char: " << nextChar << endl;

	if(nextChar == '+' || nextChar == '-')
		hasTerm = findTerm();

	return hasTerm;
}

bool findTerm()
{
	bool hasFactor;
	char nextChar;

	hasFactor = findFactor();

	cin >> nextChar;
	cout << "Next char: " << nextChar << endl;

	if(nextChar == '*' || nextChar == '/')
		hasFactor = findFactor();

	return hasFactor;
}

bool findFactor()
{
	char nextChar;

	cin >> nextChar;
	cout << "Next char: " << nextChar << endl;

	if(isalpha(nextChar))
		return true;

	else if(nextChar == '(')
	{
		findExpression();
		
		cin >> nextChar;
		cout << "Next char: " << nextChar << endl;

		if(nextChar == ')')
			return true;
		else
			return false;
	}

	else
		return false;
}
