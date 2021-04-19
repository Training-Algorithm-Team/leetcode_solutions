// https://leetcode.com/problems/maximum-ice-cream-bars/ - Medium
// 1833. Maximum Ice Cream Bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (int cost : costs) {
            if (cost <= coins) {
                res++;
                coins -= cost;
            } else {
                break;
            }
        }
        return res;
    }
};
