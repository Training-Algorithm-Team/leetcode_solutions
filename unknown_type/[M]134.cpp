// https://leetcode.com/problems/gas-station/

/* Bai nay trung tu, ngay xua anh lam mot lan roi

*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int allCost = 0;
        int remaining = 0;
        int startIdx = 0;
        
        for (int i = 0; i < n; ++i) {
            total += gas[i];
            allCost += cost[i];
            remaining += gas[i];
            
            if (remaining < cost[i]) {
                startIdx = i + 1;
            }
            remaining = max(0, remaining - cost[i]);
        }
        return total >= allCost? startIdx : -1;
    }
};
