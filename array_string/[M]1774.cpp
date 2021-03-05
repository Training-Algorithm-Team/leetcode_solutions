// 1774. Closest Dessert Cost - Medium
// https://leetcode.com/problems/closest-dessert-cost/ 

/* Analysis:
- We can use backtracking to list all possible cases and calculate its price.
- For 1 type of topping, we have 3 choices with it: do not choose, choose 1, choose 2. We do it recursively with all types of toppings.
- Time complexity: O(m * 3^n). m: numbers of bases, n: number of toppings
- Space complexity: O(1).
*/

class Solution {
private:
    int price;
    
    void bt(int i, int curPrice, const vector<int> &toppingCosts, int target) {
        int diff = abs(curPrice - target);
        int bestDiff = abs(price - target);
        
        if (diff < bestDiff) {
            price = curPrice;
        } else if (diff == bestDiff && curPrice < target) {
            price = curPrice;
        }
        
        if (i == toppingCosts.size()) {
            return;
        }
        
        for (int t = 0; t <= 2; ++t) {
            bt(i + 1, curPrice + t * toppingCosts[i], toppingCosts, target);
        }
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        price = baseCosts[0];
        for (int &base : baseCosts) {
            bt(0, base, toppingCosts, target);
        }
        return price;
    }
};
