// 650. 2 Keys Keyboard - Medium
// https://leetcode.com/problems/2-keys-keyboard/

/* Solution 1: DP - bottom up
- For n, it will be composed by copy and paste some smaller i => We calculate dp[n] by smaller one dp[i].
- Because we dont know which i will provide best possible value for n, we use another for loop to try every possible i < n, if n % i == 0 then we update dp[n]
by dp[i] if possible.
- Time complexity: O(n^2)
- Space compelxity: O(n)
*/

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[1] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }
        return dp[n];
    }
};

/* Solution 2: DP - bottom up
- We know that we can calculate n from i only when n % i == 0. So we should calculate n based on its factors.
- Another thing is that for a composite number (e.g. 6), can always be factorized into prime factors (e.g. 6 = 3 * 2). And the operations to build a composite number
from prime number is less than operations needed to build the composite number from its own (e.g. 6 = 2 * 3 = 5 operations vs. 6 = 1 * 6 = 6 operations). 
- Time complexity: 
  + Worst case: O(n) when n is prime number.
  + Best case: O(log(n)) when n is a composite number of small prime factors
  + Average case: O(31*log(n)). When n is composite number of 31 - greatest prime number which is 31 * 31 < 1000.
- Space complexity: O(1).
*/

class Solution {
public:
    int minSteps(int n) {        
        for (int i = 2; i < n; ++i) {
            if (n % i == 0) {
                return i + minSteps(n / i);
            }
        }
        return n == 1? 0 : n;
    }
};
