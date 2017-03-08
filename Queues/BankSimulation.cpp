// **************************************************************
// Modified for variable teller system
// Christopher Madrigal
//
// SAMPLE EVENT-DRIVEN SIMULATION
// 
// Simulation of a single waiting line of people.
// 
// There are two kinds of events:
// 
//      arrival - enter the line
//      departure - complete transaction and leave the line
// 
// Input: The textfile Inputfile. Each line contains the arrival 
//     time and required transaction time for a person.
// 
// Assumption: The arrival times are ordered by increasing time.
// 
// Output:A trace of the events executed.
//     Summary statistics (total number of arrivals, average 
//     time spent waiting in line).
// 
// Data Structures:
//     Line of people--a queue
//     Event list--a linked list of 2 kinds of event nodes:
//         arrival event - an arrival time and a transaction time
//         departure event - a departure time
// 
// Subprograms:
//     Einsert - inserts event node into event list
//     getA- reads arrival event from input file, inserts it 
//          into event list
//     ProcessA- executes an arrival event
//     ProcessD- executes a departure event
//     ADT Queue operations
// 
// Major Global Variables:
//     Q - queue (line of people)
//     E - event list
// ************************************************************** 

#include <fstream>
#include <iostream>
using namespace std;
#include "QueueP.h"

// event list 
enum events {A, D}; // arrival and departure 
struct eventNode;
typedef eventNode* eventNodePtr;
const int NUM_LINES = 3; //number of tellers

struct eventNode
{
    eventNodePtr next; // next event 
    int time;
    events etype; // time of event 
    int trans; // transaction time
	int indOfLine;
}; 

struct statistics
{
    int sumCustomers; // total no. of customers 
    int sumWaitingTime; // cumulative waiting time
	int lineSize[NUM_LINES];
};

//waiting lines
Queue* lines[NUM_LINES];

void Einsert (eventNodePtr& ,eventNodePtr);
void getNextArrival (eventNodePtr& E,ifstream&);
void ProcessA (eventNode, eventNodePtr&, ifstream&, statistics&);
void ProcessD (eventNode, eventNodePtr&, statistics&);

int main()
{
	string s;
	eventNodePtr E; // the event list 
	statistics Stats; // global statistics 
	ifstream Inputfile("infile"); // arrival and transaction times 
	eventNodePtr NewEvent; // the current event node 

	// initialize 
	E = NULL;

	Stats.sumCustomers = 0;
	Stats.sumWaitingTime = 0;

	for (int i = 0; i <= NUM_LINES - 1; i++)
	{
		Stats.lineSize[i] = 0;
		lines[i] = new Queue;
	}

	NewEvent = new eventNode;
	cout << "Simulation Begins\n";

	// get the first arrival event 
	getNextArrival(E,Inputfile);

	// process events until the event list is empty 
	while (E != NULL) 
    {
		NewEvent = E; // next event at beginning of event list 
		E = E->next; // delete event from event list 

		if(NewEvent->etype == A)
			ProcessA(*NewEvent, E,Inputfile,Stats); // process arrival event 
		else
			ProcessD(*NewEvent, E,Stats); // process departure event 
		delete NewEvent;
    }

	cout<<"Simulation Ends\n";

	// write out the final statistics 
	cout<<"\nFinal Statistics:\n";
	cout<<" Total number of people processed: "<< Stats.sumCustomers<<endl;
	cout<<" Average amount of time spent on line: ";

	if(Stats.sumCustomers == 0)
		cout<<" 0.0\n";
	else
		cout<<double(Stats.sumWaitingTime) / double(Stats.sumCustomers)<<endl;

	return 0;
}

void Einsert (eventNodePtr& E, eventNodePtr newnode)
// --------------------------------------------------------------
// Inserts an event node into the event list ordered by time.
// Precondition: Event list E is empty or has 1 node.
// Postcondition: newnode is added to E such that times are ordered. 
// (In case of nodes with the same times, arrival events come before 
// departure events.)
// -------------------------------------------------------------- 
{

// if the event list is empty 
	if(E == NULL)
		E = newnode;

	// if the event list is not empty, then insert new node at front or 
	// end of list according to time 

	// new node has earliest time, or has same time but is arrival event 
	// - insert at front of list 
	else if((newnode->time < E->time) || ((newnode->time == E->time) && (newnode->etype == A)))
	{
		newnode->next = E;
		E = newnode;
	}

	// new node has later time, or has same time but is departure event - 
	// insert at end of the list 
	else
	{
		eventNodePtr curr = E;
		while(curr->next != NULL && curr->next->time < newnode->time)
			curr = curr -> next;

		newnode->next = curr->next;
		curr->next = newnode;
	}
}

void getNextArrival (eventNodePtr& E, ifstream& fileToRead)
{
	eventNodePtr p; //points to the next eventNode

	if(!fileToRead.eof()) //if we aren't at EOF
    {
		// create a new event node 
		p = new eventNode; //point p to new eventNode
		p -> etype = A; // tag field == arrival event 
		p -> next = NULL;
		fileToRead >> p->time >> p->trans;
	
		// insert the node into the event list 
		Einsert(E, p);
    }
}

void ProcessD (eventNode doevent, eventNodePtr& E,statistics& Stats)
// --------------------------------------------------------------
// Executes a departure event.
// Precondition: Event node doevent contains the departure event, E is 
// the event list, the queue Q has been created, global Stats.sumWaitingTime is 
// the total waiting time.
// Postcondition: A person is removed from the queue; the event list 
// is updated by adding a departure event for the next customer, if any; 
// Stats.sumWaitingTime (total waiting time) is updated.
// Calls: Einsert, IsEmpty, Remove, QueueFront.
// -------------------------------------------------------------- 
{ 
	int current; // arrival time of current person 
	itemtype PersonInLine; // data about person in queue 
	eventNodePtr event; // event in event list 
	bool success; // flag for queue operations

	//ProcessD
	current = doevent.time;
	cout<<"Processing a departure event at time: "<<current<<endl;
	Queue* targetQueue = lines[doevent.indOfLine];
	// person departs - update the line (queue) 
	targetQueue->dequeue(success); // remove person from queue 
	if(success)
		Stats.lineSize[doevent.indOfLine] -= 1;

	// update the event list 
	// if the line is not empty, then the
	// next person starts a transaction 
	if(!targetQueue->isEmpty())
	{
		// create a departure node 
		targetQueue->getFront(PersonInLine, success);
		event = new eventNode; // get pointer to new node 
		event->etype = D; // tag field == departure event 
		event->next = NULL;
		event->time = current + PersonInLine.trans;
		event->indOfLine = doevent.indOfLine;
		// insert the node into the event list 
		Einsert(E, event);
		//delete event;
		// update the global statistics 
		Stats.sumWaitingTime = Stats.sumWaitingTime + (current - PersonInLine.arrive);
		cout << "sum waiting time: " << Stats.sumWaitingTime << endl;
	}
}

void ProcessA (eventNode doevent, eventNodePtr& E, ifstream& Inputfile, statistics& Stats)
// --------------------------------------------------------------
// Executes an arrival event.
// Precondition: Event node doevent contains the arrival event, E is 
// the event list, the queue Q has been created, an input file of 
// arrival events is available, global Stats.sumCustomers is the total number 
// of arrivals.
// Postcondition: If waiting line (queue) is empty, departure event is 
// inserted into event list. A new arrival event read from the input 
// file is inserted into event list, doevent is added to waiting line 
// (queue). Stats.sumCustomers (total no. of arrivals) is updated.
// Calls: Einsert, getA, IsEmpty, Add.
// -------------------------------------------------------------- 
{
	
	Queue* targetLine;
	int indTargetLine = 0;

	for(int i = 1; i <= NUM_LINES-1; i++)
	{
		if(Stats.lineSize[i] < Stats.lineSize[indTargetLine])
			indTargetLine = i;
	}

	targetLine = lines[indTargetLine];

	int current; // arrival time of current person 
	itemtype PersonInLine; // data about person in queue 
	eventNodePtr event; // event in event list 
	bool success;
	// update the global statistics 
	Stats.sumCustomers = Stats.sumCustomers + 1;
	
	// get current time 
	current = doevent.time;
	cout<<"Processing an arrival event at time: "<< current<<endl;

	// update the event list 

	// if the line is empty, then the person starts transaction 
	if(targetLine->isEmpty())
	{
		// create a departure event 
		event = new eventNode; // get pointer to new node 
		event->etype = D; // tag field == departure event 
		event->next = NULL;
		event->time = current + doevent.trans;
		event->indOfLine = indTargetLine;
		// insert the node into the event list 
		Einsert(E, event);
		//delete event;
	}

	// get the next arrival event from input file 
	getNextArrival(E,Inputfile);

	// person arrives: update the waiting line (queue) 
	PersonInLine.trans = doevent.trans;
	PersonInLine.arrive = current;
	targetLine->enqueue(PersonInLine,success);
	Stats.lineSize[indTargetLine] += 1;
}