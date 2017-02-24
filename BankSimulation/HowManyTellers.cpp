// **************************************************************
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
struct enode
    {
    eventNodePtr next; // next event 
    int time;
    events etype; // time of event 
    int trans; // transaction time
    }; 

struct statistics
    {
    int sumCustomers; // total no. of customers 
    int sumWaitingTime; // cumulative waiting time 
    };
Queue Q; // the waiting line 
void Einsert (eventNodePtr& ,eventNodePtr);
void getA (eventNodePtr& E,ifstream&);
void ProcessA (eventNode, eventNodePtr&,ifstream&, statistics&);
void ProcessD (eventNode, eventNodePtr&, statistics&);


int main()
{
string s;
enodeptr E; // the event list 
statistics Stats; // global statistics 
ifstream Inputfile("infile"); // arrival and transaction times 
enodeptr NewEvent; // the current event node 

// initialize 
E = NULL;
Stats.totnum = 0;
Stats.totwait = 0;
NewEvent = new enode;
cout<<"Simulation Begins\n";

// get the first arrival event 
getA(E,Inputfile);

// process events until the event list is empty 
while (E != NULL) 
    {
    NewEvent = E; // next event at beginning of event list 
    E = E->next; // delete event from event list 
    if(NewEvent->etype == A)
        ProcessA(*NewEvent, E,Inputfile,Stats); // process arrival event 
    else
        ProcessD(*NewEvent, E,Stats); // process departure event 
    } // while 

cout<<"Simulation Ends\n";

// write out the final statistics 
cout<<"\nFinal Statistics:\n";
cout<<" Total number of people processed: "<< Stats.totnum<<endl;
cout<<" Average amount of time spent on line: ";
if(Stats.totnum == 0)
    cout<<" 0.0\n";
else
    cout<<double(Stats.totwait) / double(Stats.totnum)<<endl;
return 0;
} //main


void Einsert (enodeptr& E,enodeptr newnode )
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
    newnode->next = NULL;
    E->next = newnode;
    }
} // Einsert 


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
}; // getA 

void ProcessA (enode doevent, enodeptr& E,ifstream& Inputfile,statistics& Stats)
// --------------------------------------------------------------
// Executes an arrival event.
// Precondition: Event node doevent contains the arrival event, E is 
// the event list, the queue Q has been created, an input file of 
// arrival events is available, global Stats.totnum is the total number 
// of arrivals.
// Postcondition: If waiting line (queue) is empty, departure event is 
// inserted into event list. A new arrival event read from the input 
// file is inserted into event list, doevent is added to waiting line 
// (queue). Stats.totnum (total no. of arrivals) is updated.
// Calls: Einsert, getA, IsEmpty, Add.
// -------------------------------------------------------------- 
{ //ProcessA
int current; // arrival time of current person 
itemtype PersonInLine; // data about person in queue 
enodeptr event; // event in event list 
bool success;
// update the global statistics 
Stats.totnum = Stats.totnum + 1;

// get current time 
current = doevent.time;
cout<<"Processing an arrival event at time: "<< current<<endl;

// update the event list 

// if the line is empty, then the person starts transaction 
if(Q.isEmpty())
    {
    // create a departure event 
    event = new enode; // get pointer to new node 
    event->etype = D; // tag field == departure event 
    event->next = NULL;
    event->time = current + doevent.trans;

    // insert the node into the event list 
    Einsert(E, event);
    //delete event;
    }

// get the next arrival event from input file 
getA(E,Inputfile);

// person arrives: update the waiting line (queue) 
PersonInLine.trans = doevent.trans;
PersonInLine.arrive = current;
Q.enqueue( PersonInLine,success);
} // ProcessA 

void ProcessD (enode doevent, enodeptr& E,statistics& Stats)
// --------------------------------------------------------------
// Executes a departure event.
// Precondition: Event node doevent contains the departure event, E is 
// the event list, the queue Q has been created, global Stats.totwait is 
// the total waiting time.
// Postcondition: A person is removed from the queue; the event list 
// is updated by adding a departure event for the next customer, if any; 
// Stats.totwait (total waiting time) is updated.
// Calls: Einsert, IsEmpty, Remove, QueueFront.
// -------------------------------------------------------------- 
{ 
int current; // arrival time of current person 
itemtype PersonInLine; // data about person in queue 
enodeptr event; // event in event list 
bool success; // flag for queue operations - ignored 
//ProcessD
current = doevent.time;
cout<<"Processing a departure event at time: "<<current<<endl;

// person departs - update the line (queue) 
Q.dequeue (success); // remove person from queue 

// update the event list 

// if the line is not empty, then the
// next person starts a transaction 
if(!Q.isEmpty())
    {
    // create a departure node 
    Q.getFront( PersonInLine, success);
    event = new enode; // get pointer to new node 
    event->etype = D; // tag field == departure event 
    event->next = NULL;
    event->time = current + PersonInLine.trans;

    // insert the node into the event list 
    Einsert(E, event);
    //delete event;
    // update the global statistics 
    Stats.totwait = Stats.totwait + (current - PersonInLine.arrive);
    }
} // ProcessD 