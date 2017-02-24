#include "StackP.h"
#include <iostream>
using namespace std;
//This program usesw stacks to simulate recursion.
//Every call is represented by a push to the stack.
//Every return is a pop. 

int fib(int);

int main()
{    
int count;
cout<<"Which term?\n";
cin>>count;
cout<<fib(count)<<endl;
return 0;
}

int fib(int n)
//This is a non-recursive function that uses stacks to simulate the recursion
//of a recursively written function that generates Fibonacci numbers.
{
int answer;
stackClass S;
stackItemType top,NewNode;
bool success;
top.n=n;
top.ret1=top.ret2=0;
S.Push(top,success);
while(! S.StackIsEmpty())
    {
    S.GetStackTop(top,success);
    answer=0;
    if(top.n<=2)            //degenerate case?
        {
        answer=1;
        S.Pop(success);
        }
    else if(top.ret1==0)    //need to make first recursive call?
        {
        NewNode.n=top.n-1;
        NewNode.ret1=NewNode.ret2=0;
        S.Push(NewNode,success); 
        }
    else if(top.ret2==0)    //need to make second recursive call?
        {
        NewNode.n=top.n-2;
        NewNode.ret1=NewNode.ret2=0;
        S.Push(NewNode,success); 
        }
    else                     //Time to return a value?
        {
        answer=top.ret1+top.ret2;
        S.Pop(success);
        }
    if (answer!=0)            //Was a value returned?
        {
        S.Pop(top,success);    //Pop the top of the stack to return the value in the proper field
        if(success)            //If there was nothing to pop, the while loop (above) will quit.
            {                // and the function will return.
            if(top.ret1==0)    // Otherwise, place the return value in the proper field & push.
                top.ret1=answer;
            else
                top.ret2=answer;
            S.Push(top,success);
            }
        }
    }
return answer;
}
