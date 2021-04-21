// 1487. Making File Names Unique - Medium
// https://leetcode.com/problems/making-file-names-unique/

/* Analysis:
- Complicated.
- Time complexity: O(n) amortized
- Space complexity: O(n)
*/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        unordered_map<string, int> hash;
        
        for (string &name : names) {
            if (hash.find(name) != hash.end()) {
                int k = hash[name];
                while (hash.find(name + "(" + to_string(k) + ")") != hash.end()) {
                    k++;
                }
                string toAdd = name + "(" + to_string(k) + ")";
                hash[toAdd] = 1;
                hash[name] = k + 1;
                res.push_back(toAdd);
            } else {
                hash[name] = 1;;
                res.push_back(name);
            }
        }
        return res;
    }
};
