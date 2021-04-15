// 1818. Minimum Absolute Sum Difference - Medium
// https://leetcode.com/problems/minimum-absolute-sum-difference/

/* Analysis:
- First, we keep a set of all numbers in nums1.
- For every number i in nums2 , we must find the nearest number to i from the set (greater and smaller). After that, we calculate the posible gaining
and save the maximum value.
- Time complexity: O(nlog(n))
- Space complexity: O(n)
*/

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        set<int> m;
        long absSumDiff = 0;
        long mod = 1e9 + 7;
        
        for (int i = 0; i < n; ++i) {
            m.insert(nums1[i]);
            absSumDiff += abs(nums1[i] - nums2[i]);
        }
        
        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            auto it = m.lower_bound(nums2[i]);
            int diff = abs(nums1[i] - nums2[i]) - abs(*it - nums2[i]);
            maxDiff = max(maxDiff, diff);
            
            if (it != m.begin()) {
                it--;
                diff = abs(nums1[i] - nums2[i]) - abs(*it - nums2[i]);
                maxDiff = max(maxDiff, diff);
            }
        }
        return (absSumDiff - maxDiff) % mod;
    }
};
