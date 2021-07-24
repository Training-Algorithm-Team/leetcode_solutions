// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

/* Ap dung dung tu tuong 2 bien 2 ben cua chu. 
- Khi nao mot ben bang null thi tro no ra bien.

*/

class Solution {
public:
    void traverse(Node *u, Node *leftBound, Node *rightBound) {
        if (u->left) {
            traverse(u->left, leftBound, u);
        } else {
            u->left = leftBound;
            u->left->right = u;
        }
        
        if (u->right) {
            traverse(u->right, u, rightBound);
        } else {
            u->right = rightBound;
            u->right->left = u;
        }
    }
    
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return nullptr;
        }
        
        Node *leftBound = new Node(0);
        Node *rightBound = new Node(10);
        
        
        traverse(root, leftBound, rightBound);
        leftBound->right->left = rightBound->left;
        rightBound->left->right = leftBound->right;
        return leftBound->right;
    }
};
