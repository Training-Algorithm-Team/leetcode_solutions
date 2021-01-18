// Problem: 1111. Maximum Nesting Depth of Two Valid Parentheses Strings - Medium
// Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

/* Nhận xét:
- Bài này anh lọc với tag binary search + hash table, nhưng khi làm thì có vẻ không liên quan lắm. Anh cứ up lên, chú xem có thể liệt vào dạng nào.
- Trước hết, ta nhận thấy, với dãy có dạng "AB", nếu ta chia một bên A và một bên B, như vậy sẽ không làm giảm depth của VPS.
- Ta chỉ có thể giảm depth của VPS có dạng "A" và chia nó thành "BC" với depth(B + C) = depth(A).
- Như vậy, phương án đầu tiên tôi nghĩ ra đó là duyệt toàn bộ string một lần, đếm maxLvl (maxDepth) của string. Sau đó duyệt lần 2, với tất cả các kí tự nằm ở 
depth <= maxDepth / 2, ta cho về xâu 0. Nếu nằm ở depth > maxDepth / 2, ta đưa về xâu 1. Như vậy ta sẽ chia được thành 2 xâu có max depth = maxDepth ban đầu / 2.
Đây là phương án tốt nhất có thể.
- Tuy nhiên phương án này cần 2 lần duyệt mảng.
- Sau đó, tôi đi đến một phương án tốt hơn, chỉ cần 1 lần duyệt mảng. Đó là đưa tất cả các kí tự ở depth chẵn về một xâu, các kí tự ở depth lẻ về một xâu. Như vậy, 
kết quả cuối cùng cũng sẽ gồm 2 xâu có max depth = maxDepth ban đầu / 2.
- Còn một chút ý, đó là với kí tự '(', thì ta phải tăng depth trước khi xử lý. Còn với kí tự ')', thì nó ở cùng lvl với kí tự mở ngoặc, do đó ta cần xử lý trước để có thể
xử lý tương đương với kí tự mở ngoặc, sau đó mới giảm depth. 
*/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int curLvl = 0;
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                curLvl++;
                if (curLvl & 1) {
                    res[i] = 1;
                }
            } else {
                if (curLvl & 1) {
                    res[i] = 1;
                }
                curLvl--;
            }
        }
        return res;
    }
};
