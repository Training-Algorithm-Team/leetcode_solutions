// https://leetcode.com/problems/3sum-smaller/

/* C2:
- Sort lai xong dung 2 pointers, cach nay anh tham khao giai

*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] < target) {
                    res += r - l;
                    l++;
                } else {
                    r--;
                }
            }
        }
        return res;
    }
};

/* C1: Cach 1 anh dinh thu dung counting sort xem co hay ho khong, nhung ma nhan ra cach nay chi tot khi dung cho 2 sum thoi.

*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> counts(201, 0);
        
        for (int i = 0; i < n; i++) {
            counts[nums[i] + 100]++;
        }
        
        int res = 0;
        for (int i = 0; i < 201; i++) {
            if ((i - 100) * 3 < target) {
                res += counts[i] * (counts[i] - 1) * (counts[i] - 2) / 6;
            }
            for (int j = i + 1; j < 201; j++) {
                if ((j - 100) * 2 + (i - 100) < target) {
                    res += counts[i] * counts[j] * (counts[j] - 1) / 2;
                }
                if ((j - 100) + 2 * (i - 100) < target) {
                    res += counts[i] * (counts[i] - 1) / 2 * counts[j];   
                }
            }
            for (int j = i + 1; j < 201; j++) {
                for (int k = j + 1; k < 201; k++) {
                    if (i + j + k - 300 < target) {
                        res += counts[i] * counts[j] * counts[k];
                    }
                }
            }
        }
        return res;
    }
};
