// Problem: 1726. Tuple with Same Product - Medium
// Link: https://leetcode.com/problems/tuple-with-same-product/

/* Nhận xét:
- Với bài này ta cần so sánh 2 tích của 2 cặp số bất kì, hay nói cách khác, ta tính 1 tích, sau đó look up trong một danh sách các tích đã có.
- Khi tiếp cận theo cách này, ta build hash table, sử dụng unordered_map để có thể lưu thêm cả số lần xuất hiện của 1 tích.
- Sau khi có số lần xuất hiện, ta có thể tính được số cặp có thể ghép với nhau chính là số tập con 2 phần tử của số lần xuất hiện, tức là sử dụng công thức: 
Cn(k) = n!/(k!*(n-k)!). Với mỗi cặp, ta nhân kết quả với 8 vì có thể đảo vị trí 8 lần.
*/

class Solution {
public:
    vector<long> fact{1};
    
    long factorial(int n) {
        if (n >= fact.size()) {
            fact.resize(n+1, -1);
        } else if (fact[n] > -1) {
            return fact[n];
        }
        fact[n] = n * factorial(n-1);
        return fact[n];
    }
    
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hs;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; ++j) {
                hs[nums[i] * nums[j]] ++;
            }
        }
        int res = 0;
        for (auto it = hs.begin(); it != hs.end(); ++it) {
            int val = it->second;
            if (val >= 2) {
                res += 8 * ((factorial(val) / factorial(val - 2)) / factorial(2));
            }
        }
        return res;
    }
};
