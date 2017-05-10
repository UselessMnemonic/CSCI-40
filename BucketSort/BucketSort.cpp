//Christopher Madrigal
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

struct bucketItem{
	int num;
	int amount;
};

typedef bucketItem* bucketItemPtr;

//sorts integets from cin into a bucket
//then prints the results
void bucketSort(vector<bucketItemPtr>&);
void printBucket(vector<bucketItemPtr>&);

/*Bucket:
0: [#, amount]
1: [#, amount]
2: [#. amount]
 .
 .
 .
*/

int main()
{
	vector<bucketItemPtr> bucket(0);
	int i = 0;

	while(true)
	{
		cout << "Choose among the options for this demo:" << endl;
		cout << "1: Sort" << endl;
		cout << "2: Print" << endl;
		cin >> i;

		switch(i)
		{
		case 1:
			bucketSort(bucket);
			break;
		case 2:
			printBucket(bucket);
			break;
		default:
			cout << "Try again." << endl;
		}
	}

	return 0;

}

void bucketSort(vector<bucketItemPtr>& bucket)
{
	int num;
	int i;
	bucketItemPtr newItem;

	cout << "Enter as many positive numbers as you want. Type -1 to stop." << endl;
	cin >> num;
	while(num >= 0)
	{
		i = 0;
		//traverse the bucket untill the proper entry is found
		while((i  < bucket.size()) && (bucket.at(i)->num != num))
			i++;

		//if the number is not in the bucket, make an entry
		if(i == bucket.size())
		{
			newItem = new bucketItem;
			newItem->num = num;
			newItem->amount = 1;

			//find the right index in which to insert
			i = 0;
			while (i < bucket.size() && bucket.at(i)->num < num)
				i++;

			bucket.insert(bucket.begin() + i, newItem);
		}
		//if the number is counted, add onto tally
		else
		{
			bucket.at(i)->amount++;
		}

		cin >> num;

	}
	cout << endl;
}

/*
Table format for print

------------------------
Number             Total
------------------------
          0            0
          1            1
.
.
.
99999999999        99999
*/
void printBucket(vector<bucketItemPtr>& bucket)
{
	bucketItemPtr item;
	cout << "------------------------" << endl;
	cout << "Number             Total" << endl;
	cout << "------------------------" << endl;

	for(int i = 0; i <= bucket.size() - 1; i++)
	{
		item = bucket.at(i);
		cout << setw(11) << item->num << "        " << setw(5) << item->amount << endl;
	}
	cout << endl;
}