class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Deque to store indices of useful elements in current window
        // It maintains decreasing order of values
        deque<int> dq;

        // Vector to store the maximum of each window
        vector<int> max;

        /* Step 1: Process the first window of size k */
        for (int i = 0; i < k; i++) {

            // Remove indices of elements smaller than current element
            // from the back, since they cannot be maximum
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Push current index into deque
            dq.push_back(i);
        }

        /* Step 2: Process the remaining elements */
        for (int i = k; i < nums.size(); i++) {

            // Step 3: The front of deque contains index of maximum element
            // for the previous window
            max.push_back(nums[dq.front()]);

            /* Step 4: Remove indices that are out of this window */
            while (dq.size() > 0 && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // (No-op call, does nothing but kept as in original code)
            dq.front();

            /* Step 5: Remove all elements smaller than current element
               from the back of deque */
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Step 6: Add current index to deque
            dq.push_back(i);
        }

        // Step 7: Add maximum of the last window
        max.push_back(nums[dq.front()]);

        // Step 8: Return the result containing maximums of all windows
        return max;
    }
};
