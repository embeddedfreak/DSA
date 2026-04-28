#include <iostream>
#include <vector>

using namespace std;

class Stack {
    
    vector<int> vec;

public: 
    void push(int val)
    {
        vec.push_back(val);
    }
    
    void pop() 
    {
        vec.pop_back();        
    }
    
    int top()
    {
        return vec[vec.size()-1];   
    }
    
    bool Empty() {
        return vec.size() == 0;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    while(!s.Empty()) {
        cout<<s.top()<<" "<<endl;
        s.pop();
    }
    return 0;
}
