// 229. Majority Element II - Medium
// https://leetcode.com/problems/majority-element-ii/

/* Analysis:
- Bài này thì dựa theo cách làm của bài một ta có thể dùng hàm sort của C++ để có thể có space complexity O(1). Ngoài ra, thì ta vẫn có thể dùng hash table, hoặc
Moore's voting nhưng cách đấy hơi khó, vào phòng thi đúng là anh ko nghĩ ra nổi.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    const int INVALID = INT_MAX;
    int checkMajor(vector<int> &nums, int pos) {
        nth_element(nums.begin(), nums.begin() + pos, nums.end());
        int val = nums[pos];
        if (count(nums.begin(), nums.end(), val) > (nums.size() / 3)) {
            return val;
        }
        return INVALID;
    }
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int idx = n / 3;
        int first = checkMajor(nums, idx);
        if (first != INVALID) {
            res.push_back(first);
        }
        
        idx = n * 2 / 3;
        int second = checkMajor(nums, idx);
        if (second != INVALID && second != first) {
            res.push_back(second);
        }
        return res;
    }
};
