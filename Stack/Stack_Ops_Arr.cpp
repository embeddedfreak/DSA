/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define CAPACITY 5
using namespace std;
/* Stack implementation using Array */

class Stack {
    int arr[CAPACITY];
    int top = -1;

public:
    void push(int val)
    {
        if(top == CAPACITY -1) {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    
    int top_ele() 
    {
        if(top == -1) {
            cout<<"No elements in Stack"<<endl;
            return -1;
        }
        return arr[top];
    }
    
    void pop()
    {
        if(top == -1) {
            cout<<"No elements in Stack"<<endl;
            return;
        }
        /* If needed can consider int pop() */
        /* Also return element */
        top--;
    }
    
    bool Empty() 
    {
            return top == -1;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    while(!s.Empty()) {
        cout<<s.top_ele()<<endl;
        s.pop();
    }
    return 0;
}
