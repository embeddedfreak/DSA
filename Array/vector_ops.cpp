/*
Program: Basic Vector Operations in C++

Algorithm:
1. Create vectors using different initialization methods.
2. Display the elements of a vector using a range-based for loop.
3. Insert a new element at the end using push_back().
4. Display the updated size and capacity of the vector.
5. Access the first and last elements using front() and back().
6. Remove the last element using pop_back().
7. Access an element at a specific index using at().
8. Copy one vector to another using the copy constructor.
9. Display the elements of the copied vector.

Time Complexity:
- Traversing vector: O(n)
- push_back(): O(1) (amortized)
- pop_back(): O(1)
- front(), back(), at(): O(1)
- Copy constructor: O(n)

Space Complexity: O(n)
*/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
        vector<int> vec;
        vector<int> vec1 = {1, 2, 3, 4};
        vector<int> vec2(3, 0);

        for(int val: vec1) {
                cout<<val<<" ";
        }

        cout<<endl;

        cout<<"push_back(10) operation:"<<endl;
        vec1.push_back(10);

        cout<<"Size of vec1 is: "<< vec1.size()<<endl;
        cout<<"Capacity of vec1 is: "<< vec1.capacity()<<endl;


        for(int val: vec1) {
                cout<<val<<" ";
        }
        cout<<endl;

        cout<<"First element is "<<vec1.front()<<endl;
        cout<<"Last element is "<<vec1.back()<<endl;

        cout<<"After pop_back()"<<endl;
        vec1.pop_back();

        for(int val: vec1) {
                cout<<val<<" ";
        }
        cout<<endl;

        cout<<"Element at() 1 is "<<vec1.at(1)<<endl;

        cout<<"Copy vec1 to vec3"<<endl;

        vector<int> vec3(vec1);
        cout<<"Elements of vec3 are: "<<endl;
        for(int val: vec3) {
                cout<<val<<" ";
        }
        cout<<endl;
        return 0;
}
