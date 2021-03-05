// 1775. Equal Sum Arrays With Minimum Number of Operations - Medium
// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

/* Analysis:
- First, we must calculate the difference between the sum of 2 array first.
- After that, in order to equalize 2 arrays with minimum operations, we must change the values of the number that make biggest difference first. For the smaller array,
we change all of them to 6, from 1 first. For the greater array, we change all of them to 1, from 6 first.
- We change them in 5 rounds, for round 1, we change 1->6 and 6->1, round 2: 2->6 and 5->2, ... Until, the possible changes is greater than the difference 
between 2 arrays.
- So, we need to count and save the number of values from 1->6 to a hash table. We can use vector for this purpose.
- Time complexity: O(m + n)
- Space complexity: O(7) for hash table. Litterally, it's O(1).
*/

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        
        if (sum1 < sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        
        int diff = sum1 - sum2;
        vector<int> hashBig(7, 0), hashSmall(7, 0);
        for (int &v : nums1) {
            hashBig[v]++;
        }
        for (int &v : nums2) {
            hashSmall[v]++;
        }
        
        int res = 0;
        for (int i = 0; i < 5; ++i) {
            int times = hashBig[6 - i] + hashSmall[1 + i];        
            int change = 5 - i;
            
            if (diff <= times * change) {
                res += (diff + change - 1) / change;
                return res;
            } else {
                res += times;
                diff -= times * change;
            }
        }
        return -1;
    }
};
