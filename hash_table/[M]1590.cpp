// Problem: 1590. Make Sum Divisible by P - Medium
// Link: https://leetcode.com/problems/make-sum-divisible-by-p/

/* Nhận xét:
- Ta gọi tổng của toàn dãy % p là target. Khi đó, để có thể xóa một đoạn đi được một dãy chia hết cho p, ta cần tìm một đoạn cố tổng % p = target 
<=> prefix[j] % p == (prefix[i] + target) % p
=> Ta dùng một hash table lưu toàn bộ các [prefix % p]. Tại điểm i, ta look up trong hash xem có tồn tại giá trị [(prefix[i] - target) % k] hay không, nếu có thì 
update kết quả.
- Time complexity: O(n)
- Space complexity: O(n)
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int accu = 0;
    
        for (int &v : nums) {
            accu = (accu + v) % p;
        }
        if (accu == 0) {
            return 0;
        }
        
        int target = accu;
        unordered_map<int, int> hash;
        hash[0] = -1;
        accu = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            accu = (accu + nums[i]) % p;
            int j = (accu - target + p) % p;
            if (hash.find(j) != hash.end()) {
                res = min(res, i - hash[j]);   
            }
            hash[accu] = i;
        }
        return res >= n? -1 : res;
    }
};
