// Problem: 714. Best Time to Buy and Sell Stock with Transaction Fee
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

/* Analysis:
- We want to buy at min price and sell at max price, so we maintain 2 variables to save them and update them correctly.
- If we meet a price that greater than max => update max to sell at higher price.
- Otherwise:
  + If price < min => we need to update minPrice.
  + If price < max - fee => we have profit on previous [min, max] pair => we start new traking.
  + Both cases above, we need to update profit based on previous [min, max] pair.
- Time complexity: O(n)
- Space complexity: O(1)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int minVal = 50001, maxVal = 0;
        int res = 0;
        for (int &p : prices) {
            if (p < maxVal - fee || p < minVal) {
                res += max(0, maxVal - minVal - fee);
                maxVal = minVal = p;
            } else if (p > maxVal) {
                maxVal = p;
            }
        }
        res += max(0, maxVal - minVal - fee);
        return res;
    }
};
