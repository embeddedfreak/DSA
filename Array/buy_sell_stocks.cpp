/*
Problem: Best Time to Buy and Sell Stock

Algorithm:
1. Assume the first day's price as the best buying price.
2. Traverse the array from the second element to the end.
3. Update the best buying price if a lower price is found.
4. For each day, calculate the profit if selling on that day using:
   profit = current price - bestBuy
5. Update the maximum profit if the current profit is greater.
6. After traversal, return the maximum profit obtained.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

/* consider first day price as best Buy
 * run loop from 1 - n-1
 * check and update comparing bestBuy and current day price for minimum
 * check for bestBuy and current day price for difference
 * Update maxdifference i.e max Profit
 * return maxProfit
 */
int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;
        int bestBuy = prices[0];
        for(int i = 1; i < n; i++) {
                bestBuy = bestBuy > prices[i] ? prices[i] : bestBuy;
                if(prices[i] > bestBuy) {
                        int diff = prices[i] - bestBuy;
                        maxProfit = (maxProfit > diff)? maxProfit : diff;
                }
        }
        return maxProfit;
}


int main()
{
        vector<int> prices = {3, 8, 1, 4, 7, 5};

        cout<<"Max Profit"<<maxProfit(prices)<<endl;
}
