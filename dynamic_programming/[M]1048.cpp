// https://leetcode.com/problems/longest-string-chain/

/* Voi bai nay, ta can dung dp de build up longest string chain tu cac string nho hon.
- Vi vay ta can sort theo do dai truoc
- Sau do den moi phan tu, ta lai quay nguoc ve truoc de tim kiem predecessor.
- Bai nay co the dung hash table de giam do phuc tap, voi moi string thi ta thu toan bo cac predecessor co the roi tim kiem trong hash table. 
Anh doc giai xong moi biet va se ap dung vao lan khac.

*/

class Solution {
public:
    bool isPredecessor(const string &small, const string &big) {
        int m = small.size(), n = big.size();
        if (n - m != 1) {
            return false;
        }
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (small[i] != big[j]) {
                i--;
            }
            i++, j++;
        }

        return i == m && j >= n - 1;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
