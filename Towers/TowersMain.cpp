/*
*   Authored by Christopher Madrigal
*   Non-recursive implementation and demonstration of solveTowers,
*   an algorithm to solve a game of Hanoi
*/

//recursive definition of solveTowers
void solveTowers(int count, char source, char destination, char spare)
{
	if (count == 1)
	{
		source--;
		destination++;
	}
	else
	{
		solveTowers(count - 1, source, spare, destination);
		solveTowers(1, source, destination, spare);
		solveTowers(count - 1, spare, destination, source);
	}
}

void solveTowers(int count)
{
	
}