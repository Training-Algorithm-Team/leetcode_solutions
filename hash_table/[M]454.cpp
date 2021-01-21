// Problem: 454. 4Sum II - Medium
// Link: https://leetcode.com/problems/4sum-ii/

/* Nhận xét:
- Ta coi a + b + c + d là (a + b) + (c + d).
- Như vậy ta đếm tất cả số trường hợp có thể của (a + b) và của (c + d), sử dụng hash table để lưu lại.
- Với 2 số có khả năng cộng với nhau bằng không, ta cần nhân số lần xuất hiện của 2 bên với nhau và thêm vào kết quả.
- Time complexity: O(n^2)
- Space complexity: O(n^2), do tối đa một hash table có thể có n^2 phần tử.
*/

class Solution {
public:
    void computeHash(unordered_map<int, int> &hs, const vector<int> &a, const vector<int> &b) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                hs[a[i] + b[j]]++;
            }
        }
    }
    
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {        
        unordered_map<int, int> hs1, hs2;
        computeHash(hs1, a, b);
        computeHash(hs2, c, d);
        int res = 0;
        for (auto &[k, v] : hs1) {
            if (hs2[-k] != 0) {
                res += v * hs2[-k];
            }
        }
        return res;
    }
};
