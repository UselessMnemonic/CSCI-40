//Christopher Madrigal
#include <vector>
#include <iostream>
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
	vector<bucketItemPtr> bucket;
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
		}
	}

	return 0;

}

void bucketSort(vector<bucketItemPtr>& bucket)
{
	int num;
	int i;
	bucketItemPtr newItem;

	cout << "Enter as many numbers as you want. Type -1 to stop." << endl;
	cin >> num;
	while(num >= 0)
	{
		i = 0;
		//traverse the bucket untill the proper entry is found
		while(i <= bucket.size()-1 && bucket.at(i) != NULL && bucket.at(i)->num != num)
			i++;

		//if the number is not in the bucket, make an entry
		if(i == bucket.size())
		{
			newItem = new bucketItem;
			newItem->num = num;
			newItem->amount = 1;
			bucket.push_back(newItem);
		}
		//if the number is counted, add onto tally
		else
		{
			bucket.at(i)->amount++;
		}

	}
	cout << endl;
}

void printBucket(vector<bucketItemPtr>& bucket)
{
	bucketItemPtr item;

	for(int i = 0; i <= bucket.size() - 1; i++)
	{
		item = bucket.at(i);
		cout << "Entry: " << item->num << " Tally: " << item->amount << endl;
	}
}