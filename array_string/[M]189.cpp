// Problem: 189. Rotate Array - Medium
// Link: https://leetcode.com/problems/rotate-array/

/* Solution 1:
- We make an extra k slots for k elements, then move every elements to the right k slots. We move from back to front in order not to overwrite existing elements.
- After that, we move k trail elements to the front of the array.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        nums.resize(n + k);
        for (int i = n - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; ++i) {
            nums[i] = nums[n + i];
        }
        nums.resize(n);
    }
};

/* Solution 2: *Actually, it's hard to explain*
- First, we need to make clear that the element indexes will be moved in a circular style. For example, n = 20 and k = 15, index 0 will be rotated like this:
    0 -> 15 -> 10 -> 5 -> 0  (similar, 1 -> 16 -> 11 -> 6 -> 1)
- The rotation finishes a circle when we add up to lcm(n, k). I mean:
    0 -> 15 -> 30 -> 45 -> 60 = lcm(20, 15)
- So, the number of elements in a circle will be = lcm(n, k) / k. For example: 60 / 15 = 4 => (4 elements: 0, 15, 10, 5) 
- Because, each element will take place of 1 element in array n and the circles are not overlap, number of circles (or a range that we need to rotate) will be 
n / (lcm / k) = n * k / lcm = gcd(n, k);
- So, we create a for loop gcd(n, k) times, each of them, we rotate 1 circle. 
- Time complexity: O(n)
- Space complexity: O(1)
*/
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        
        int range = gcd(n, k);
        for (int i = 0; i < range; ++i) {
            int prev = (i - k + n) % n;
            int memo = nums[i];
            while (prev != i) {
                nums[(prev + k) % n] = nums[prev];
                prev = (prev - k + n) % n;
            }
            nums[i + k] = memo;
        }
    }
};
