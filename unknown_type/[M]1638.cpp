// Problem: 1638. Count Substrings That Differ by One Character - Medium
// Link: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

/* Nhận xét:
- Mặc dù anh lọc với tag binary search + hash table, nhưng anh thấy bài này ko liên quan lắm. Chú đánh giá thử xem?
- Bài này anh thấy khá khó và chưa tìm được cách xử lý tối ưu, chú thử nghiên cứu giúp anh xem thế nào.
- Hướng giải quyết: build toàn bộ các substring có thể từ string s. Với mỗi substring đó, ta lại kiểm tra với toàn bộ các substring có thể tương ứng trong dãy t.
Nếu sai khác đúng một kí tự thì tăng thêm kết quả.
*/

class Solution {
public:
    bool check(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                count++;
            }
        }
        return (count == 1);
    }
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        vector<string> substrs;
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (string &ss : substrs) {
                ss += s[i];
            }
            substrs.push_back(string(1, s[i]));
            
            for (string &ss : substrs) {
                for (int j = 0; j <= n - ss.size(); j++) {
                    if (check(ss, t.substr(j, ss.size()))) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
