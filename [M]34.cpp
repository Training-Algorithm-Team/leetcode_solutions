// Problem: 34. Find First and Last Position of Element in Sorted Array - Medium
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int findLeft(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (nums[l] == target) return l;
        if (nums[r] == target) return r;
        return -1;
    }
    
    int findRight(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (nums[r] == target) return r;
        if (nums[l] == target) return l;
        return -1;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        int left, right;
        left = findLeft(nums, target);
        right = findRight(nums,target);
        return {left, right};
    }
};
