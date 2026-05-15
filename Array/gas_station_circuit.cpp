
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // Step 1: Calculate total gas and total cost
        int totGas = 0, totCost = 0;

        for(int val: gas) {
            totGas += val;
        }

        for(int val: cost) {
            totCost += val;
        }

        // Step 2: If total gas is less than total cost,
        // it is impossible to complete the circuit
        if(totGas < totCost) {
            return -1;
        }        

        // Step 3: Initialize starting index and current gas
        int start = 0, curGas = 0;

        // Step 4: Traverse all stations
        for(int i = 0; i < gas.size(); i++) {

            // Add net gas at current station
            curGas += (gas[i] - cost[i]);

            // Step 5: If current gas becomes negative,
            // current starting point is invalid
            if(curGas < 0) {
                // Move start to next station
                start = i + 1;

                // Reset current gas
                curGas = 0;
            }
        }

        // Step 6: Return the valid starting index
        return start;
    }
};
