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
		//prompt user for input
		cout << "Enter an expression: ";

		//find an expression
		isExp = findExpression();

		//result is dependent on both finding a valid expression and having no extra characters
		if(isExp && cin.get() == '\n')
			cout << "Valid Expression" << endl << endl;
		else
		{
			cout << "Invalid Expression" << endl << endl;
			cin.ignore(1000, '\n');
		}

		cout << endl;
	}
}

bool findExpression()
{
	bool hasTerm;
	char nextChar;

	//look for a term
	hasTerm = findTerm();

	//if the next character is an operator, check for a following term
	nextChar = cin.peek();
	if(nextChar == '+' || nextChar == '-')
	{
		nextChar = cin.get();
		hasTerm = findTerm();
	}

	return hasTerm;
}

bool findTerm()
{
	bool hasFactor;
	char nextChar;

	//look for a factor
	hasFactor = findFactor();

	//if the next character is an operator, check for a following factor
	nextChar = cin.peek();
	if(nextChar == '*' || nextChar == '/')
	{
		nextChar = cin.get();
		hasFactor = findFactor();
	}

	return hasFactor;
}

bool findFactor()
{
	//check the first character
	char nextChar = cin.peek();

	//if the first character is a letter, we have a factor
	if(isalpha(nextChar))
	{
		//consume the character and return result
		nextChar = cin.get();
		return true;
	}

	//if the first character is a (, look for an expression
	else if(nextChar == '(')
	{
		//comsume character and check for expression
		nextChar = cin.get();
		findExpression();
		
		//check for a closing ) and return result
		nextChar = cin.peek();
		if(nextChar == ')')
		{
			nextChar = cin.get();
			return true;
		}
		else
			return false;
	}

	else
		return false;
}
