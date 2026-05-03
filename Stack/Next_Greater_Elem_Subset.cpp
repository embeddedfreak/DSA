
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /* store the next greater element for each value in nums2 */
        unordered_map<int, int> m;

        // Stack to help find the next greater element
        stack<int> st;

        // Step 1: Traverse nums2 from right to left
        // This helps in finding the next greater element on the right
        for(int i = nums2.size() - 1; i >= 0; i--) {

            // Step 2: Remove all elements from the stack
            // that are smaller than or equal to the current element
            while(st.size() > 0 && st.top() <= nums2[i]) {
                st.pop();
            }

            // Step 3: If stack is empty, no greater element exists
            if(st.empty()) {
                m[nums2[i]] = -1;
            }
            // Step 4: If stack is not empty, the top element
            // is the next greater element
            else {
                m[nums2[i]] = st.top();
            }

            // Step 5: Push the current element onto the stack
            st.push(nums2[i]);
        }

        // Step 6: Build the answer for nums1 using the precomputed map
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }

        // Step 7: Return the final result
        return ans;   
    }
};
