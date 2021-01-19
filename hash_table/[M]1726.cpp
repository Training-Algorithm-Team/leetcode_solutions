// Problem: 1726. Tuple with Same Product - Medium
// Link: https://leetcode.com/problems/tuple-with-same-product/

/* Nhận xét:
- Với bài này ta cần so sánh 2 tích của 2 cặp số bất kì, hay nói cách khác, ta tính 1 tích, sau đó look up trong một danh sách các tích đã có.
- Khi tiếp cận theo cách này, ta build hash table, sử dụng unordered_map để có thể lưu thêm cả số lần xuất hiện của 1 tích.
- Sau khi có số lần xuất hiện, ta có thể tính được số cặp có thể ghép với nhau chính là số tập con 2 phần tử của số lần xuất hiện, tức là sử dụng công thức: 
Cn(k) = n!/(k!*(n-k)!). Với mỗi cặp, ta nhân kết quả với 8 vì có thể đảo vị trí 8 lần.
- Trưởng hợp này, tập con có độ dài cố định là 2, vậy số tập con là n * (n - 1) / 2.
- Ngoài ra, ta có thể tính kết quả ngay khi thêm mới 1 tích. Ta nhận thấy, khi thêm 1 tích vào, nó có thể tạo tuple với toàn bộ các tích tương tự đã tồn tại trong hash table 
mà không gây ra trùng lặp. Như vậy, kết quả sẽ được tăng thêm 8 * (số tích với giá trị đó hiện có).
*/

// C1: đếm tất cả các tích, sau đó sử dụng công thức: n * (n - 1) / 2 để tính số lượng tập con
class Solution {
public:    
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
                res += 8 * val * (val - 1) / 2;
            }
        }
        return res;
    }
};

// C2: mỗi lần thêm một tích vào, ta cộng kết quả thêm 8 * (số tích hiện có)
class Solution {
public:    
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hs;
        int res = 0;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                res += hs[product];
                hs[product] ++;
            }
        }
        
        return res * 8;
    }
};
