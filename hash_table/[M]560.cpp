// Problem: 560. Subarray Sum Equals K - Medium
// Link: https://leetcode.com/problems/subarray-sum-equals-k/

/* Nhận xét:
- Để tính tổng một dãy con bất kì, ta có thể sử dụng kĩ thuật prefix sum để tính toán với độ phức tạp O(1).
- Tại một điểm j, ta cần kiểm tra tổng của tất cả các dãy con kết thúc tại j, tổng này có dạng prefix[j] - prefix[i - 1] == k => Ta cần đếm số lượng i mà 
prefix[i-1] == prefix[j] - k.
- Nhận thấy ta có thể đếm số lượng này với độ phức tạp O(1) khi sử dụng một hash table, với key là prefix[i] và value là số lượng xuất hiện của nó.
- Cần lưu ý trường hợp i == 0, khi đó, ta cần thêm 1 giá trị 0 vào hash table để tính thêm cả tập con bắt đầu từ đầu mảng cho đến j.
*/

class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        if (0 == n) {
            return 0;   
        }
        vector<int> prefix(n, 0);
        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + a[i]; 
        }

        unordered_map<int, int> hash;
        hash.insert({0, 1});
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += hash[prefix[i] - k];
            hash[prefix[i]]++;
        }
        return res;
    }
};
