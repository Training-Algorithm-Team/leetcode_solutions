// https://leetcode.com/problems/continuous-subarray-sum/

/* Ta dung hash table de luu prefixSum da chia du voi k, va vi tri cua no.
- Neu tim duoc prefix nao dong du thi tuc la co day chia het cho k.

*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k;
            auto it = prefixSum.find(sum);
            if (it != prefixSum.end()) {
                if (i - it->second > 1) {
                    return true;       
                }
            } else {
                prefixSum[sum] = i;   
            }
        }
        return false;
    }
};
