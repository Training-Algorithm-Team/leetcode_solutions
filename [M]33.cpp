// Problem: 33. Search in Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int find(const vector<int> &nums, int l, int r, int target) {
        if (l == r) {
            return nums[l] == target? l : -1;
        }
        else if (l > r) {
            return -1;
        }
        
        int mid = l + (r - l) / 2;
        int res;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            res = find(nums, mid + 1, r, target);
            if (nums[mid] < nums[l]) {
                res = max(res, find(nums, l, mid - 1, target));
            }
        }
        else {
            res = find(nums, l, mid - 1, target);
            if (nums[mid] > nums[r]) {
                res = max(res, find(nums, mid + 1, r, target));
            }
        }
        return res;
    }
    int search(vector<int>& nums, int target) {
        return find(nums, 0, nums.size() - 1, target);
    }
};
