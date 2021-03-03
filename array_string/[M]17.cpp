// 17. Letter Combinations of a Phone Number - Medidum
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

/* Analysis:
- For every digit, we have 3 or 4 characters corresponding to it. So we create a hash table to store them.
- For each digit in the input string, we try all possible characters for it and recursively try next one.
- Time complexity: O(4^n)
- Space complexity: O(4 * 8). 4 characters for 8 digits.
*/

class Solution {
private: 
    const vector<string> hash = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    
    void bt(const string digits, int i, string &cur) {
        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }
        
        int d = digits[i] - '2';
        for (char c : hash[d]) {
            cur.push_back(c);
            bt(digits, i + 1, cur);
            cur.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        string cur;
        bt(digits, 0, cur);
        return res;
    }
};
