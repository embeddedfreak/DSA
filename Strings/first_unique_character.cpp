class Solution {
public:
    int firstUniqChar(string s) {

        // Step 1: Map to store frequency of each character
        unordered_map<char, int> m;

        // Step 2: Queue to store indices of characters
        queue<int> q;

        int n = s.size();

        // Step 3: Traverse the string
        for (int i = 0; i < s.size(); i++) {

            // Step 4: Update frequency of current character
            m[s[i]]++;

            // Step 5: Store index of current character
            q.push(i);

            // Step 6: Remove indices from queue whose characters
            // have frequency greater than 1 (not unique anymore)
            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }

        // Step 7: If queue is not empty, front gives index of first unique character
        // Otherwise return -1
        return q.size() > 0 ? q.front() : -1;
    }
};
