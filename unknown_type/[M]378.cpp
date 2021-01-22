// Problem: 378. Kth Smallest Element in a Sorted Matrix - Medium
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/* Nhận xét:
- Bài này anh chịu rồi :))
- Bài này sau khi sửa theo C2 thì thời gian chạy thậm chỉ còn tăng lên, có vẻ như overhead là quá lớn. (C1: 32ms vs C2: 52ms). Chú nghĩ sao?
*/

// C1: Sort toàn bộ dãy rồi chọn phần tử thứ k
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> a;
        for (auto &vt : matrix) {
            for (auto &val : vt) {
                a.push_back(val);
            }
        }
        sort(a.begin(), a.end());
        return a[k-1];
    }
};

// C2: loang từ phần tử bé nhất, sau đó thêm vào heap, chọn lần lượt cho tới đến khi đủ k phần tử
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto comp = [&] (const pair<int, int> &a, const pair<int, int> &b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        
        vector<pair<int, int>> heap;
        vector<vector<bool>> expanded(n, vector<bool>(n, false));
        int count = 0;
        expanded[0][0] = true;
        heap.push_back({0, 0});
        
        
        while (count < k && !heap.empty()) {
            auto [r, c] = heap.front();
            pop_heap(heap.begin(), heap.end(), comp); heap.pop_back();
            if (++count == k) {
                return matrix[r][c];
            }
            
            if (r < n - 1) {
                int nr = r + 1;
                if (!expanded[nr][c]) {
                    expanded[nr][c] = true;
                    heap.push_back({nr, c});
                    push_heap(heap.begin(), heap.end(), comp);
                }
            }
            
            if (c < n - 1) {
                int nc = c + 1;
                if (!expanded[r][nc]) {
                    expanded[r][nc] = true;
                    heap.push_back({r, nc});
                    push_heap(heap.begin(), heap.end(), comp);
                }
            }            
        }
        return -1;
    }
};
