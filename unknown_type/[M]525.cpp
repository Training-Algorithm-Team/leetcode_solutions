// Problem: 525. Contiguous Array - Medium
// Link: https://leetcode.com/problems/contiguous-array/

/* Nhận xét:
- Bài này anh cũng chịu. Anh tính giải bằng binary search mà bị wrong answer.
- Chú có phân tích lý do cho anh được ko?
*/

class Solution {
public:
    bool isValid(const vector<int> &nums, int k) {
        int count[2] = {0, 0};
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
            if (i >= k - 1) {
                if (i >= k) {
                    count[nums[i-k]]--;
                }
                if (count[0] == count[1]) {
                    return true;
                }
            }
        }
        if (count[0] == count[1]) {
            return true;
        }
        return false;
    }
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int l = 0, r = n / 2 + 1;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (isValid(nums, mid * 2)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l * 2;
    }
};

/* C2: 
- Anh nghĩ ra rồi :D Cơ mà anh buồn ngủ quá, thôi để nhận xét sau nhé :D
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        int diff = 0;
        hash.insert({diff, -1});
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                diff++;
            } else {
                diff--;
            }
            if (hash.find(diff) == hash.end()) {
                hash[diff] = i;
            } else {
                res = max(res, i - hash[diff]);
            }
        }
        return res;
    }
};
