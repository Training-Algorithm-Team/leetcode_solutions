// 930. Binary Subarrays With Sum - Medium
// Link: https://leetcode.com/problems/binary-subarrays-with-sum/

/* Nhận xét:
- Ta lưu điểm bắt đầu 1 prefix sum - p - mới là hash[p]. Số dãy có tổng s tạo được từ điểm hiện tại, chính là số dãy có tổng bằng cur - s, hay chính là hash[p + 1] - hash[p],
điểm bắt đầu của prefix sum mới - điểm bắt đầu prefix sum cũ.
- Trường hợp s = 0 thì ta lấy vị trí hiện tại trừ đi vị trí bắt đầu của prefix sum p.
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int s) {
        int n = a.size();
        vector<int> hash(1, -1);
        
        int accu = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                hash.push_back(i);
            } 
            accu += a[i];
            if (accu >= s) {
                res += s == 0? i - hash[accu] :  hash[accu - s + 1] - hash[accu - s];
            }
        }
        return res;
    }
};
