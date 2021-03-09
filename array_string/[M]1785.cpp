// 1785. Minimum Elements to Add to Form a Given Sum - Medium
// https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

/* Analysis:
- We calculate the difference we need to make. After that, we divide by limit to get minimum number of elements needed.
- If difference % limit != 0, it means we need one more item to make it work.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        for (int &v : nums) {
            sum += v;
        }
        long diff = abs(goal - sum);
        return diff % limit == 0? (diff / limit) : (diff / limit) + 1;
    }
};
