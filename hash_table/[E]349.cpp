// Problem: 349. Intersection of Two Arrays - Easy
// Link: https://leetcode.com/problems/intersection-of-two-arrays/

/* Nhận xét:
- Ta có thể chuyển sang set, và dùng hàm std set_intersection thì độ phức tạp là O(mlog(m) + nlog(n)) cho thao tác tạo set
- Ta sử dụng cách thứ hai:
    + Build 1 hash table (dùng unordered_set) để lưu các phần tử trong mảng thứ 1.
    + Duyệt toàn bộ các phần tử của mảng thứ 2 và look up trong hash table vừa tạo, nếu xuất hiện thì ta thêm vào vector kết quả.
    + Time complexity: O(m + n) tương đương với O(max(m, n)). Thao tác tạo hash table có n phần tử, insert mỗi phần tử có độ phức tạp trung bình O(1) => Độ phức tạp O(n).
    Thao tác look up m phần tử của mảng 2, mỗi lần find trong hash table có độ phức tạp O(1) => Độ phức tạp O(m). 
    + Space complexity: O(2n) = O(n) cho hash table và kết quả;
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash(nums1.begin(), nums1.end());
        vector<int> res;
        
        for (int v : nums2) {
            if (hash.find(v) != hash.end()) {
                res.push_back(v);
                hash.erase(v);
            }
        }
               
        return res;
    }
};
