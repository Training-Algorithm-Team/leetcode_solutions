// Problem: 451. Sort Characters By Frequency - Medium
// Link: https://leetcode.com/problems/sort-characters-by-frequency/

/* Nhận xét:
- Ta cần đếm số lần xuất hiện của mỗi kí tự. Đây là thao tác quen thuộc sử dụng unordered_map
- Sau đó ta sort lại theo thứ tự giảm dần số lần xuất hiện và thêm vào xâu kết quả.
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        vector<pair<int, char>> vp;
        for (auto &[c, f] : freq) {
            vp.push_back({f, c});
        }
        sort(vp.begin(), vp.end(), greater<pair<int, char>>());
        
        string res;
        for (auto &[f, c] : vp) {
            res += string(f, c);
        }
        return res;
    }
};
