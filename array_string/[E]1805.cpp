// 1805. Number of Different Integers in a String - Easy
// https://leetcode.com/problems/number-of-different-integers-in-a-string/

/* Analysis:
- We maintain a hashtable of string to save all possible distinct strings.
- We for through the string, if we see a alphabet, we add the current number string to hash table.
- Time complexity: O(n)
- Space complexity: O(n)
*/

class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();
        string cur = "";
        unordered_set<string> hash;
        for (char &c : word) {
            if (isalpha(c)) {
                if (cur.size() > 0) {
                    hash.insert(cur);
                    cur = "";    
                }
            } else {
                if (cur.size() == 1 && cur[0] == '0') {
                    cur = "";
                }
                cur += c;
            }
        }
        if (cur.size() > 0) {
            hash.insert(cur);
        }
        return hash.size();
    }
};
