// Problem: 1054. Distant Barcodes - Medium
// Link: https://leetcode.com/problems/distant-barcodes/

/* Nhận xét:
- Cách dễ thấy nhất là ở mỗi vị trí, chọn phần tử đang có tần số xuất hiện cao nhất. Mỗi khi điền vào một vị trí thì giảm tần số của nó đi 1 và đưa vào một biến wait
vì nó không thể được điền vào vị trí ngay sau đó.
- Time complexity: O(nlog(n))
- Space complexity: O(n)
- Anh không nghĩ ra được cách nào tốt hơn nên tạm thời phải dùng cách này. Chú có ý kiến gì ko?
*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int, int> hash;
        
        for (int &b : barcodes) {
            hash[b]++;
        }
        
        priority_queue<pair<int, int>> heap;
        for (auto &[k, v] : hash) {
            heap.push({v, k});
        }
        
        vector<int> res(n);
        pair<int, int> waiting;
        for (int i = 0; i < n; ++i) {
            auto [f, b] = heap.top();
            res[i] = b;
            heap.pop();
            
            if (waiting.first > 0) {
                heap.push(waiting);
            }
            
            waiting = {f - 1, b};
        }
        return res;
    }
};
