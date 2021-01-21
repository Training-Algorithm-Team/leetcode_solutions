// Problem: 676. Implement Magic Dictionary - Medium
// Link: https://leetcode.com/problems/implement-magic-dictionary/

/* Nhận xét:
- I have nothing to say about this :(
*/

class MagicDictionary {
private:
    vector<vector<string>> dict;
    bool compare(const string &s1, const string &s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                count ++;
            }
        }
        return count == 1;
    }
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dict.resize(101);
    }
    
    void buildDict(vector<string> dictionary) {
        for (string w : dictionary) {
            dict[w.size()].push_back(w);
        }
    }
    
    bool search(string searchWord) {
        for (string s : dict[searchWord.size()]) {
            if (compare(s, searchWord)) {
                return true;
            }
        }
        return false;
    }
};
