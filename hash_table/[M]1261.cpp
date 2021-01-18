// Problem: 1261. Find Elements in a Contaminated Binary Tree - Medium
// Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

/* Nhận xét: 
- Để sửa giá trị các nốt, ta cần sửa nốt cha trước, nốt con sau => Ta có thể thực hiện sử dụng preorder traversal.
- Để tìm một nốt, ban đầu tôi nghĩ đến việc phân tích số cần tìm theo kiểu đệ quy v = (v - 1) / 2 để biết được hướng trái phải cần phải đi từ gốc, sau đó đi theo
hướng đã phân tích xem có đến được nốt có giá trị cần tìm hay không. Tuy nhiên cách này code rất khó.
- Để ý thấy bài này thuộc dạng hash table, ta có thể lưu các số đã recover vào một unordered_set, sau đó look up lại với O(1) time complexity.
- Kinh nghiệm rút ra: Trường hợp đề bài không có constrain thì có thể dùng thêm cấu trúc dữ liệu để giảm thời gian tính toán:
- Time complexity: O(n) cho thao tác recover với n là số nốt của cây. O(1) trung bình cho thao tác find.
- Space complexity: O(n).
*/

class FindElements {
private:
    unordered_set<int> hs;
public:
    void recover(TreeNode* u, int val) {
        if (u) {
            u->val = val;
            hs.insert(val);
            recover(u->left, 2 * val + 1);
            recover(u->right, 2 * val + 2);
        }
    }
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return hs.find(target) != hs.end();
    }
};
