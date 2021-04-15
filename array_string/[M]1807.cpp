// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/ - Medium
// 1807. Evaluate the Bracket Pairs of a String

/* Analysis:
- First, we use a hash table to save the knowledge in order to reduce look up time.
- In order to use built-in find function, we use 2 pointers. Pos1 is the position of '(', pos2 is the position after ')'.
- We look up for the string between pos1 and pos2. After that, we put the substring between pos2 and pos1 to the result.
- Time complexity: O(n)
- Space complexity: O(1)
*/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> hash;
        for (vector<string> &k : knowledge) {
            hash[k[0]] = k[1];
        }
        
        string res;
        
        size_t pos1 = 0, pos2 = 0;
        
        while ((pos1 = s.find('(', pos2)) != string::npos) {
            res += s.substr(pos2, pos1 - pos2);
            pos2 = s.find(')', pos1) + 1;
            
            string toFind = s.substr(pos1 + 1, pos2 - pos1 - 2);
            // cout << "toFind = " << toFind << endl;
            if (hash.find(toFind) != hash.end()) {
                res += hash[toFind];
            } else {
                res += '?';
            }
        }
        res += s.substr(pos2);
        return res;
    }
};
