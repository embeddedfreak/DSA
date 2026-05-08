/******************************************************************************

Program to identify a celebrity using a stack-based elimination technique.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* Function to find the celebrity index */
int findCelebrity(vector<vector<int>> arr) 
{
    int n = arr.size();
    stack<int> st;
    
    /* Step 1: Push all people indices onto the stack */
    for(int i = 0; i < n; i++) {
        st.push(i);
    }
    
    /* Step 2: Eliminate non-celebrities */
    while(st.size() > 1) {
        int i = st.top(); st.pop();
        int j = st.top(); st.pop();
        
        /* Step 3: If person i knows person j,
           then i cannot be a celebrity */
        if(arr[i][j] == 1) {
            st.push(j);
        } 
        /* Step 4: Otherwise, j cannot be a celebrity */
        else {
            st.push(i);
        }
    }
    
    /* Step 5: Potential celebrity */
    int celeb = st.top();
    
    /* Step 6: Verify the potential celebrity */
    for(int i = 0; i < n; i++) {
        if((celeb != i) && 
           (arr[celeb][i] == 1 || arr[i][celeb] == 0)) {
            return -1;
        }
    }
    
    /* Step 7: Return verified celebrity index */
    return celeb;
}

int main()
{
    // Relationship matrix
  //make it {0, 1, 0}, {1, 0, 0}, {0, 1, 0} and get -1
  // for this example the potential celebrity logic is written
    vector<vector<int>> arr = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    
    // Print the celebrity index
    cout << findCelebrity(arr) << endl;

    return 0;
}
