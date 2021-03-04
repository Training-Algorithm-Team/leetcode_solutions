// 1328. Break a Palindrome - Medium
// https://leetcode.com/problems/break-a-palindrome/

/* Analysis:
- We can separate the palindrom into first half and second half.
- In the first half, we find the first character > 'a' and change it to 'a' (the smallest character that is smaller than current)
- If all of them are character 'a', we change the last character to 'b' (the smallest character that is larger than current).
- Time complexity: O(n)
- Space complexity: O(1)
*/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n < 2) {
            return "";
        }
        
        int half = n / 2;
        for (int i = 0; i < half; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};
