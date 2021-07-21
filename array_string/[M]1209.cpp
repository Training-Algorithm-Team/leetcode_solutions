// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/submissions/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        string res;
        vector<int> count;
        for (int i = 0; i < n; ++i) {
            if (res.empty() || s[i] != res.back()) {
                res.push_back(s[i]);
                count.push_back(1);
            } else {
                res.push_back(s[i]);
                count.push_back(count.back() + 1);
            }
            
            if (count.back() >= k) {
                res.resize(res.size() - k);
                count.resize(count.size() - k);
            }
        }
        return res;
    }
};
