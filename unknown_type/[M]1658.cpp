// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

/* Chung ta dung two pointers voi doan phan bu cua x.
- Truong hop nay la ca so deu duong ta co the dung 2 pointers,
- Truong hop co so am thi ta phai dung hash table

*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        
        int res = -1;
        int j = 0;
        for (int i = 0, sum = 0; i < n; i++) {
            sum += nums[i];
            
            while (j <= i && sum > target) {
                sum -= nums[j];
                j++;
            }
            if (sum == target) {
                res = max(res, i - j + 1);
            }
        }
        return n - res;
    }
};
