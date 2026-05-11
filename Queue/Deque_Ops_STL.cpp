#include <iostream>
#include <deque>

using namespace std;

int main()
{
    /* deque is double ended queue */
    /* Where push can be done from both front and back */
    /* pop also can be done from both front and back */
   deque<int> dq;
   
   dq.push_back(10);
   dq.push_back(20);
   dq.push_back(30);
   
   dq.push_front(40);
   
   cout<<"front: "<<dq.front()<<endl;
   cout<<"back: "<<dq.back()<<endl;
   
   /* dequeue() is a pop operation in queue */
   
    return 0;
}
