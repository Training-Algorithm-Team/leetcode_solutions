// https://leetcode.com/problems/replace-words/ - Medium
// 648. Replace Words

/* Analysis:
- We can build a trie from dictionary and search on trie to find a substring to be used to replace. We can split sentence into words beforehand to make a clean code.
- We call number of word in dictionary = n, length of each word = m, length of sentence = l.
- Time complexity: O(n * m + l)
- Space complexity: O(n * m + l). (n * m) for trie, (l) for intermedate "words" vector.
*/

class Solution {
private:
    class TrieNode {
    public:
        char value;
        unordered_map<char, TrieNode*> children;
        bool isFinish;
    
        TrieNode(char v) {
            value = v;
            isFinish = false;
        }
        
        TrieNode* find(char c) {
            TrieNode *res = nullptr;
            if (children.find(c) != children.end()) {
                res = children[c];
            }
            return res;
        }
        
        TrieNode* insert(char c) {
            TrieNode *res = find(c);
            if (res == nullptr) {
                res = new TrieNode(c);
                children[c] = res;
            }
            return res;
        }
    };
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode *root = new TrieNode('#');
        for (string &s : dictionary) {
            TrieNode *u = root;
            for (char &c : s) {
                u = u->insert(c);
            }
            u->isFinish = true;
        }
        
        vector<string> words;
        stringstream ss(sentence);
        string w;
        while (ss >> w) {
            words.push_back(w);
        }
        
        string res;
        for (string &w : words) {
            TrieNode *u = root;
            string replace = w;
            for (int i = 0; i < w.size() && u != nullptr; ++i) {
                char c = w[i];
                u = u->find(c);
                
                if (u != nullptr && u->isFinish) {
                    replace = w.substr(0, i + 1);
                    break;
                }
            }
            res += replace + " ";
        }
        res.pop_back();
        return res;
    }
};
