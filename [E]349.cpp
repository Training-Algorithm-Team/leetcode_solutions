// Problem: 349. Intersection of Two Arrays - Easy
// Link: https://leetcode.com/problems/intersection-of-two-arrays/

/* Nhận xét:
- Chuyển sang set thì độ phức tạp là O(mlog(m) + nlog(n))
- Dùng hashtable thì độ phức tạp là O(m + n). Space complexity là O(m);
- Anh lưu kết quả vào nums1 cho tiết kiệm space.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(), nums1.end());
        
        vector<int>::iterator it = nums1.begin();
        for (int v : nums2) {
            if (hash.find(v) != hash.end()) {
                *it = v;
                it++;
                hash.erase(v);
            }
        }
        nums1.erase(it, nums1.end());
        return nums1;
    }
};
