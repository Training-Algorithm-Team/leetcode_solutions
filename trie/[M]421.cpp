// 421. Maximum XOR of Two Numbers in an Array - Medium
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

/* Analysis:
- We can build a trie with depth 32 from the original nums.
- After that, we for every item in nums, search them in trie. If we can find a node with opposite bit, we use that node.
- We for from bit 31 -> bit 0 to maximize the result
- Time complexity: O(32n)
- Space complexity: O(32n)
*/

class Solution {
private:
    class TrieNode {
    public:
        TrieNode *node0, *node1;
        
        TrieNode() {
            node0 = nullptr;
            node1 = nullptr;
        }
        
        TrieNode* find(int v) {
            return v == 1? node1 : node0;
        }
        
        TrieNode* insert(int v) {
            if (v == 1 && node1 == nullptr) {
                node1 = new TrieNode();
            } else if (v == 0 && node0 == nullptr) {
                node0 = new TrieNode();
            }
            return find(v);
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode;
        
        for (int &v : nums) {
            TrieNode *u = root;
            for (int i = 31; i >= 0; --i) {
                int bit = (v >> i) & 1;
                u = u->insert(bit);
            }
        }
        
        int maxVal = 0;
        for (int &v : nums) {
            TrieNode *u = root;
            int val = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (v >> i) & 1;
                if (u->find(1 - bit)) {
                    u = u->find(1 - bit);
                    val |= (1 << i);
                } else {
                    u = u->find(bit);
                }
            }
            maxVal = max(maxVal, val);
        }
        return maxVal;
    }
};
