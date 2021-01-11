// Problem: 852. Peak Index in a Mountain Array - Easy
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size();
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (arr[mid] < arr[mid-1]) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return l;
    }
};
