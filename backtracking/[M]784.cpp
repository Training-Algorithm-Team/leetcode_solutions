// 784. Letter Case Permutation - Medium
// https://leetcode.com/problems/letter-case-permutation/

/* Analysis:
- We can use backtracking to list every possible string. If we see a letter, we change it to lower then upper then test the next character.
- Time complexity: O(2^n).
- Space complexity: O(n) for call stack.
*/

class Solution {
private:
    vector<string> res;
    void bt(string &s, int i) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        
        char c = s[i];
        if (isalpha(c)) {
            s[i] = tolower(c);
            bt(s, i+1);
            
            s[i] = toupper(c);
            bt(s, i+1);
        } else {
            bt(s, i+1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        bt(s, 0);
        return res;
    }
};
