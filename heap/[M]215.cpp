// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for (int &v : nums) {
            heap.push(v);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        return heap.top();
    }
};
