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

void debug(string msg)
{
	cout << msg << endl;
}
void debug(string msg, string val)
{
	debug(msg + ": \"" + val + "\"");
}

int main() //entry point for program
{
	string exp; //stores user input
	while (true)
	{
		cout << "Enter an expression: "; //prompt for string
		cin >> exp;
		//print result of isExpression
		if (!isExpression(exp))
			cout << "in";
		cout << "valid expression" << endl;
	}
	return 1;
}

string findExpression(string stringContainingExpression)
{
	debug("***FIND EXPRESSION**");
	if (stringContainingExpression.length() == 2)
		return "";
	//holds the possible operator between terms
	string operatorCharacter;

	//holds the result of findTerm on the argument
	string termString = findTerm(stringContainingExpression);
	debug("termString", termString);
	//substring following the found term in the argument
	string restOfString = stringContainingExpression.substr(termString.length());
	debug("restOfString", restOfString);
	//holds the result of a second term search
	string nextTerm;
	//holds a reconstructed result
	string result;

	//if there is possibly at least one more term to find
	if (restOfString.length() >= 2)
	{
		//find the operator
		operatorCharacter = restOfString.substr(0, 1);
		debug("operatorCharacter", operatorCharacter);
		//if the operator is either a + or -...
		if (operatorCharacter.at(0) == '+' || operatorCharacter.at(0) == '-')
		{
			//find the next term
			nextTerm = findFactor(restOfString.substr(1));
			debug("nextTerm", nextTerm);
			//if the search fails, the argument contains no valid expression
			if (nextTerm.empty())
				return "";
			else //else, return a reconstructed term,
			{
				result = termString + operatorCharacter + nextTerm;;
				debug("result", result);

				if (stringContainingExpression.compare(result) == 0)
					return result;
				else
					return "";
			}
		}
		else //else, the argument contains no valid expression
			return "";
	}
	else
		return termString;
}

string findTerm(string stringContainingTerm)
{
	debug("***FIND TERM**");
	//holds the possible operator between factors
	string operatorCharacter;

	//holds the result of findFactor on the argument
	string factorString = findFactor(stringContainingTerm);
	debug("factorString", factorString);
	//substring following the found factor in the argument
	string restOfString = stringContainingTerm.substr(factorString.length());
	debug("restOfString", restOfString);
	//holds the result of a second factor search
	string nextFactor;

	//if there is possibly at least one more factor to find
	if (restOfString.length() >= 2)
	{
		//find the operator
		operatorCharacter = restOfString.substr(0, 1);
		debug("operatorCharacter", operatorCharacter);
		//if the operator is either a * or /...
		if (operatorCharacter.at(0) == '*' || operatorCharacter.at(0) == '/')
		{
			//find the next factor
			nextFactor = findFactor(restOfString.substr(1));
			debug("nextFactor", nextFactor);
			//if the search fails, the argument contains no valid term
			if (nextFactor.empty())
				return "";
			else //else, return a reconstructed term
			{
				return factorString + operatorCharacter + nextFactor;
			}
		}
	}
	//else, return the found factor, as it is our term
	return factorString;
}

string findFactor(string stringContainingFactor)
{
	debug("***FIND FACTOR**");
	string firstCharacter = stringContainingFactor.substr(0, 1);
	debug("firstCharacter", firstCharacter);
	string stringContainingExpression;
	int indOfClosingPara;

	if (firstCharacter.at(0) == '(')
	{
		//get the string following the (
		stringContainingExpression = stringContainingFactor.substr(1);
		debug("stringContainingExpression", stringContainingExpression);

		//if we have "<expression>)"
		if (stringContainingExpression.length() >= 4)
		{
			//if there is a closing brace after three characters
			if (stringContainingExpression.at(3) == ')')
				indOfClosingPara = 3; //then we found the end of our factor
			else //otherwise, the embedded expression has a far right closing )
				indOfClosingPara = stringContainingExpression.find_last_of(')');

			cout << "indOfClosingPara: " << indOfClosingPara << endl;

			//if there is no closing ), the argument is not a valid factor
			if (indOfClosingPara == string::npos)
				return "";
			else
			{
				//otherwisem isolate the embedded expression and check for validity
				stringContainingExpression = stringContainingExpression.substr(0, indOfClosingPara);
				debug("stringContainingExpression", stringContainingExpression);
				stringContainingExpression = findExpression(stringContainingExpression);
				debug("stringContainingExpression", stringContainingExpression);
				//if the search failed, the argument is not a valid factor
				if (stringContainingExpression.empty())
					return "";
				else
					return "(" + stringContainingExpression + ")";
			}
		}
		else if (stringContainingExpression.length() == 2 && isalpha(stringContainingExpression.at(0))) //however, if it is the case we have "<letter>)"
		{
			//then it's implied the argument is "(<letter>)"
				return stringContainingFactor;
		}
		else
			return "";
	}
	else if (isalpha(firstCharacter.at(0)))
	{
		return firstCharacter;
	}
	else
		return "";
}

bool isExpression(string stringContainingExpression)
{
	return !findExpression(stringContainingExpression).empty();
}