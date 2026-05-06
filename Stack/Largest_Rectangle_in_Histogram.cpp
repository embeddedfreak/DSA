class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        /* Step 1: Find index of the nearest smaller bar to the RIGHT
           for each bar in the histogram */
        vector<int> rs(n);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove bars that are taller or equal to the current bar
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            // If no smaller bar exists to the right
            if (st.empty()) {
                rs[i] = n;
            }
            // Otherwise, top of stack is the right smaller index
            else {
                rs[i] = st.top();
            }

            // Push current bar index
            st.push(i);
        }

        /* Step 2: Find index of the nearest smaller bar to the LEFT */
        vector<int> ls(n);

        // Clear stack before reusing
        while (!st.empty())
            st.pop();

        // Traverse from left to right
        for (int i = 0; i <= n - 1; i++) {

            // Remove bars that are taller or equal to the current bar
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            // If no smaller bar exists to the left
            if (st.empty()) {
                ls[i] = -1;
            }
            // Otherwise, top of stack is the left smaller index
            else {
                ls[i] = st.top();
            }

            // Push current bar index
            st.push(i);
        }

        /* Step 3: Calculate the maximum rectangular area in the histogram */
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = rs[i] - ls[i] - 1;
            int curArea = heights[i] * width;

            if (ans < curArea) {
                ans = curArea;
            }
        }
        return ans;
    }
};
