// Problem: 974. Subarray Sums Divisible by K - Medium
// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

/* Nhận xét:
- Ta có thể dùng prefix sum, tạm gọi là biến accu. Một đoạn liên tiếp có tổng chia hết cho k <=> tổng của dãy % k == 0 <=> prefix[i] % k == prefix[j] % k
- Vậy ta chỉ cần lưu vào một hash table, số lần xuất hiện của một (prefix % k) trước đây, ở một điểm nhất định ta tính biến (accu % k), sau đó thêm vào kết quả
số lần xuất hiện của remainder trước đây.
- Ta cần phải + k rồi % k để xử lý cho trường hợp k < 0.
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        vector<int> hash(k, 0);
        hash[0] = 1;
        int accu = 0;
        int res = 0;
        for (int &v : a) {
            accu += v;
            int remain = ((accu % k) + k) % k;
            res += hash[remain];
            hash[remain]++;
        }
        return res;
    }
};
