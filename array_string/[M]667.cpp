// 667. Beautiful Arrangement II - Medium
// https://leetcode.com/problems/beautiful-arrangement-ii/

/* Solution 1: Backtracking
- Bài này anh vò đầu bứt tai ko biết làm backtracking kiểu gì, mà còn phải đảm bảo time limit
- Code anh submit còn ko chạy, chú thử suggest anh phương pháp này phát.
*/

class Solution {
private:
    vector<bool> used;
    vector<bool> hash;
public:
    vector<int> bt(vector<int> perm, int cur, int n, int k) {
        if (perm.size() == n) {
            if (cur == k) {
                return perm;    
            } else {
                return {};
            }
        }
        
        for (int j = 1; j <= n; ++j) {
            if (!used[j]) {
                used[j] = true;
                
                vector<int> res;
                if (perm.empty() || hash[perm.back() - j + n]) {
                    perm.push_back(j);
                    res = bt(perm, cur, n, k);
                } else {
                    int prev = perm.back();
                    hash[prev - j + n] = true;
                    perm.push_back(j);
                    res = bt(perm, cur + 1, n, k);
                    hash[prev - j + n] = false;
                } 
                
                if (res.size() > 0) {
                    return res;
                }
                
                used[j] = false;
                perm.pop_back();
            }
        }
        return {};
    }
    
    vector<int> constructArray(int n, int k) {
        used.resize(n + 1, false);
        hash.resize(2 * n + 1, false);
        
        vector<int> perm;
        auto res = bt(perm, 0, n, k);
        return res;
          
    }
};

/* Solution 2:
- Cách này khá hay, nhưng anh nghĩ lâu quá, có vẻ không phù hợp trong một buổi phỏng vấn.
- Với số các hiệu là k, ban đầu ta có thể build được 1 đoạn từ 1-> k+1 như sau. Ví dụ: 
  + n = 5, k = 4 => [1, 5, 2, 4, 3]
  + n = 3, k = 2 => [1, 3, 2]
- Ta dùng 1 vòng while đến k đầu tiên để build dãy có đủ k hiệu khác nhau.
- Với vòng while còn lại cho đến n, ta đặt luôn số nằm ở vị trí i chính là index i => điều này đảm bảo không tạo ra một hiệu mới lớn hơn k.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
private:
    
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        res[0] = 1;
        bool add = true;
        
        int i = 1;
        while (i <= k) {
            if (add) {
                res[i] = res[i-1] + (k - i + 1);
            } else {
                res[i] = res[i-1] - (k - i + 1);
            }
            ++i;
            add = !add;
        }
        while (i < n) {
            res[i] = i + 1;
            ++i;
        }
        return res;
    }
};
