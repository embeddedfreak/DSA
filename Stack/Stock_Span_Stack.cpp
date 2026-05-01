
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // Vector containing stock prices for consecutive days
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    
    // Vector to store the stock span result for each day
    vector<int> ans(price.size(), 0);

    // Stack to store indices of days
    // It helps in tracking previous higher prices
    stack<int> st;
    
    // Loop through each day's stock price
    for(int i = 0; i < price.size(); i++) {

        // Pop indices from the stack while the current price
        // is greater than or equal to the price at stack's top index
        while(st.size() > 0 && price[st.top()] <= price[i] ) {
            st.pop();
        }

        // If stack is empty, it means no greater price exists on the left
        // Hence span is all days from 0 to i
        if(st.empty()) {
            ans[i] = i + 1;
        } 
        // If stack is not empty, span is the difference between
        // current index and index of last greater price
        else {
            ans[i] = i - st.top();
        } 
            
        // Push current index onto the stack
        st.push(i);
    }

    // Print the stock span for each day
    for(int val: ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;  // Indicate successful program termination
}
