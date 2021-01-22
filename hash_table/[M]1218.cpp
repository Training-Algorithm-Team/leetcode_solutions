// Problem: 1218. Longest Arithmetic Subsequence of Given Difference - Medium
// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

/* Nhận xét:
- Tại một điểm, giả sử a[i], ta cần biết sub sequence dài nhất, PHÍA TRƯỚC ĐIỂM HIỆN TẠI, kết thúc tại giá trị là arr[i] - diff.
- Do đó, ta có thể lưu vào một hash table với key là giá trị tại điểm kết thúc, và value là độ dài của sub sequence kết thúc tại điểm đó.
- Do độ dài nhất tại một điểm chỉ quan tâm tới độ dài của các điểm trước đó, nên ta có thể build hash và sử dụng ngay trong một vòng for.
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> hs;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            int len = hs[val - difference];
            hs[val] = len + 1;
            res = max(res, len + 1);
        }
        return res;   
    }
};
