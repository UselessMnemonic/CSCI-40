/*
*	Authored by Christopher Madrigal
*	Chapter 5 - 6th ed - Programming Problem #8, Infix Expressions
*
*	-Grammar-
*	<expression> = <term>|<term> + <term>|<term> - <term>
*	<term> = <factor>|<factor>*<factor>|<factor>/<factor>
*	<factor> = <letter>|(<expression>)
*	<letter> = a|b|...|z
*/
#include <iostream>
#include <string>
using namespace std;

string findExpression(string); //returns an expression string, null if the argument is not an expression
string findTerm(string); //returns the first occurance of a term in the argument, null if no term can be found
string findFactor(string); //returns the first occurance of a factor in the argument, null if no factor can be found
bool isExpression(string); //returns true if the argument is an expression, false otherwise

int main() //entry point for program
{
	string exp; //stores user input
	while (true)
	{
		cout << "Enter an expression: "; //prompt for string
		cin >> exp;
		cout << isExpression(exp) << endl; //print result of isExpression
	}
	return 1;
}

string findExpression(string exp)
{
}

string findTerm(string t)
{
	
}

string findFactor(string f)
{
	
}

bool isExpression(string expr)
{
	return !findExpression(expr).empty();
}