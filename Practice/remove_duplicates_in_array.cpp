#include <iostream>

#include <set>

using namespace std;


void remove_Duplicate(int arr[], int n)
{
    set<int> s;
    
    for(int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }
    
    int j = 0;
    
    for(int val : s) {
        arr[j] = val;
        j++;
    }
    
    for(int i = 0; i < j ; i++) {
        cout<<arr[i];
    }
}

int main()
{
    int arr[5] = {1, 2, 1, 3, 4};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    remove_Duplicate(arr, n);

    return 0;
}

