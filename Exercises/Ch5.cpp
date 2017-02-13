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
#include <string>
using namespace std;

string findExpression(string);
string findTerm(string);
string findFactor(string);

string findExpression(string exp)
{

}

string findTerm(string t)
{
}

string findFactor(string f)
{
	if(isalpha(f.at(0)))
		return f;
	else if(f.at(0) == '(')
	{
		int indOfClosing = f.find_last_of(')');
		if(indOfClosing == string::npos)
			return "";
		else
			return findExpression(f.substr(1, indOfClosing-1));
	}
	else
		return "";
}