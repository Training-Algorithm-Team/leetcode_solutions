// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                for (int j = n - 1; j > i; --j) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                break;
            }
            i--;
        }
        sort(nums.begin() + i + 1, nums.end());
    }
};
