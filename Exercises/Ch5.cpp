/*
*   Authored by Christopher Madrigal
*   Chapter 5 - 6th ed - Programming Problem #8, Infix Expressions
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
#include <string>
using namespace std;

string findExpression(string); //returns an expression string, empty if the argument is not an expression
string findTerm(string); //returns the first occurance of a term in the argument, empty if no term can be found
string findFactor(string); //returns the first occurance of a factor in the argument, empty if no factor can be found
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

string findExpression(string stringContainingExpression)
{
	string termString = findTerm(stringContainingExpression); //find the first expression
	string followingString = termString.substr(termString.length()); //get the string following the first term
	char operatorCharacter;
	string nextTerm;
	string constructedExpression;

	if(!termString.empty()) //if findTerm was successful
	{
		if(followingString.empty()) //if the following substring is empty, then we are done
			return termString;
		else //otherwise
		{
			operatorCharacter = followingString.at(0); //check the next character after our term

			if(operatorCharacter == '+' || operatorCharacter == '-') //if the character is a + or -
			{
				nextTerm = findTerm(followingString.substr(1)); //check if there is another term

				if(!nextTerm.empty()) //if findTerm was successful
				{
					constructedExpression = termString.append(&operatorCharacter) + nextTerm; //construct our expression

					if(constructedExpression.length() == stringContainingExpression.length()) //if our expression matches our grammar, we are done
						return constructedExpression;
					else //otherwise, the string is not an expression
						return "";
				}
				else //otherwise, the string is not an expression
					return "";
			}
			else //otherwise, the string is not an expression
			{
				return "";
			}
		}
	}
	else //otherwise, string is not expression
		return "";
}

string findTerm(string stringContainingTerm)
{
}

string findFactor(string stringContainingFactor)
{
	char beginningCharacter = stringContainingFactor.at(0); //char at beginning of string
	int indexOfLastPara = stringContainingFactor.find_last_of(')'); //last index of )

	if(beginningCharacter == '(') //if the first character in stringContainingFactor is ( ...
	{
		if(indexOfLastPara == string::npos) //if there is no coresponding ), the string is not a factor
			return "";
		else
			return "("+findExpression(stringContainingFactor.substr(1,indexOfLastPara))+")"; //if there is a corresponding ), get the expression between () and return (<expression>);
	}
	else if (isalpha(beginningCharacter) && stringContainingFactor.length() == 1) //if the first character in stringContainingFactor is a letter and string is len 1...
		return stringContainingFactor; //string is already a factor, return it
	else
		return ""; //if all else, string is not a factor
}

bool isExpression(string stringContainingExpression)
{
	return !findExpression(stringContainingExpression).empty();
}