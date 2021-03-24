// 740. Delete and Earn - Medium
// https://leetcode.com/problems/delete-and-earn/

/* Analysis:
- We define f[i] is the maximum score if the array contains only value <= i. So we can calculate f[i] based on smaller ones.
- If we delete (i-1) => we cannot delete i. But if we delete any j <= i-2, we can delete i and earn => f[i] = max(f[i-1], f[i-2] + earning from i).
- (Earning from deleting i) = (frequency of i) * i.
- Time complexity: O(max(n, 10000)). n = size of nums.
- Space complexity: O(20000) for frequency and f.
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int maxN = 10001;
        array<int, maxN> frequency;
        frequency.fill(0);
        for (int &v : nums) {
            frequency[v]++;
        }
        
        array<int, maxN> f;
        f.fill(0);
        f[1] = frequency[1];
        f[2] = max(f[1], frequency[2] * 2);
        for (int i = 3; i < maxN; ++i) {
            f[i] = max(f[i-2] + i * frequency[i], f[i-1]);
        }
        return f[maxN-1];
    }
};
