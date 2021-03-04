// 169. Majority Element - Easy
// https://leetcode.com/problems/majority-element/

/* Solution 1:
- We maintain a hash table to count the frequencies of all values.
- Because the major element always exists, we can just return the value with maximum occurences.
- Time complexity: O(n)
- Space complexity: O(n)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        
        int maxElement = nums[0];
        for (int &v : nums) {
            hash[v]++;
            if (hash[v] > hash[maxElement]) {
                maxElement = v;
            }
        }
        return maxElement;
    }
};

/* Solution 2:
- Với yêu cầu của đầu bài là làm với space O(1) thì may ra anh chỉ nghĩ ra cách 2 này, còn các cách khác thì anh phải nghiên cứu discussion, 
trong phòng thi đúng là chịu.
- If we divide the original array into 2 smaller array, the major will definitely be the major in at least 1 subarray. So we need to count the occurences between 
2 possible candidate and return the one with more occurences.
- We do this recursively until the array length is 1.
- Time complexity: O(nlog(n))
- Space complexity: O(1). If strictly calculated, this maybe O(log(n)) because of the call stack with log(n) depth.
*/

class Solution {
public:
    int major(const vector<int> &nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        
        int mid = l + (r - l) / 2;
        int majorLeft = major(nums, l, mid);
        int majorRight = major(nums, mid + 1, r);
        
        return count(nums.begin() + l, nums.begin() + r + 1, majorLeft) > count(nums.begin() + l, nums.begin() + r + 1, majorRight) ? majorLeft : majorRight;
    }
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        return major(nums, 0, n-1);
    }
};

/* Solution 3: Use C++ built-in function
- C++ has funciton nth_element, in which, the nth element will be the same with nth element of a sorted array.
- Because the major element appears more than n/2 times, so if we sort the array, this major element will surely be placed at the middle position.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        return nums[n/2];
    }
};

/* Solution 4: Moore voting
- Phương pháp này anh phải tìm hiểu mãi thì mới nắm được. Nói để giải thích trong vài dòng thì cũng khó.
- We want to pair 1 element with 1 different element. If the major element exists, it will exist after we pair-up every possible items.
- So we use a count variable and 1 variable to keep the current majority. We iterate through the whole array, if we see a different value than the current major,
we reduce the count variable. If the count variable is 0, it means all previous variables have been paired out, and we make the current variable the major.
- Time complexity: O(n)
- Space complexity: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major;
        for (int &v : nums) {
            if (count == 0) {
                major = v;
            }
            
            if (v != major) {
                count--;
            } else {
                count++;
            }
        }
        return major;
    }
};
