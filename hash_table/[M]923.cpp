// 923. 3Sum With Multiplicity - Medium
// https://leetcode.com/problems/3sum-with-multiplicity/

/* Analysis:
- We maintain a hash table to save all numbers in the array.
- We use 2 nested for loops to find all possible pair j, k, meanwhile all previous number i are already in the hastable.
- We calculate the sum and find the number of i in the hash table and add to result.
- After that, we save j into hash table and go next.
- Time complexity: O(n^2)
- Space complexity: O(n)
*/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        unordered_map<int, int> hash;
        hash[arr[0]]++;
        
        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int num = target - arr[i] - arr[j];
                if (hash.find(num) != hash.end()) {
                    res = (res + hash[num]) %  mod;
                }
            }
            hash[arr[i]]++;
        }
        return res;
    }
};
