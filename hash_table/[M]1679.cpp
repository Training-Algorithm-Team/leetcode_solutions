// Problem: 1679. Max Number of K-Sum Pairs - Medium
// Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/

/* Nhận xét:
- Với một số x, để tổng bằng k thì ta cần tìm xem trong dãy có số (k - x) hay không. Điều này gợi ý ta sử dụng hash table.
- Do mỗi số chỉ sử dụng 1 lần, nên khi đến một số x bất kì, ta có thể kiểm tra ngay trong dãy phía trước đó, mà không cần quan tâm ở phía sau. Nếu tồn tại (k - x) thì ta xóa
(k - x) khỏi hash, nếu không thì ta thêm x vào hash để sử dụng cho đoạn phía sau.
- Do trong đoạn phía trước, có thể tồn tại nhiều lần (k - x), nên ta cần sử dụng unordered_map để đếm số lần xuất hiện, nếu matching thì ta giảm số lần xuất hiện của
(k - x) đi 1 đơn vị.
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int res = 0;
        for (int &v : nums) {
            if (hash[k-v] > 0) {
                res++;
                hash[k - v]--;
            } else {
                hash[v]++;
            }
        }
        return res;
    }
};
