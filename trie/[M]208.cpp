// 208. Implement Trie (Prefix Tree) - Medium
// https://leetcode.com/problems/implement-trie-prefix-tree/

/* Analysis:
- In order to make clean code, we create a new class TrieNode and class Trie will have a pointer to a root node.
- A node will have a find and a insert function.
- We use a hash table to save children of a node to make it general, so we can use a wide range of characters.
- Time complexity: length of each word = l:
  + insert: O(l)
  + search: O(l)
  + startsWith: O(l)
- Space complexity: O(l * n). For each insertion, we create at most l nodes. We call insert for n times, so we create at most (l * n) nodes.
*/

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isFinished;
    
    TrieNode() : isFinished(false) {
        
    }
    
    TrieNode* find(char c) {
        TrieNode *u = nullptr;
        if (children.find(c) != children.end()) {
            u = children[c];
        }
        return u;
    }
    
    TrieNode *insert(char c) {
        TrieNode *u = find(c);
        if (u == nullptr) {
            u = new TrieNode();
            children[c] = u;
        }
        return u;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()){
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *u = root;
        for (char &c : word) {
            u = u->insert(c);
        }
        u->isFinished = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *u = root;
        for (char &c : word) {
            u = u->find(c);
            if (u == nullptr) {
                return false;
            }
        }
        return u->isFinished;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *u = root;
        for (char &c : prefix) {
            u = u->find(c);
            if (u == nullptr) {
                return false;
            }
        }
        return true;
    }
};
