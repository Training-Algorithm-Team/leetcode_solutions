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

// C2: Bắt đầu từ phần tử bé nhất của mỗi hàng, sau đó thêm vào heap, chọn lần lượt cho tới đến khi đủ k phần tử, mỗi khi loại một phần tử ra thì chỉ cần thêm vào 
// phần tử tiếp theo của hàng đó
// => Time complexity: O(nlog(n) + klog(n)). nlogn cho thao tác tạo heap ban đầu. Sau đó, k lần lấy phần tử ra, mỗi lần lại thêm vào 1 phần tử nên số phần tử
// trong heap luôn được giữ là n => thao tác push heap sẽ có độ phức tạp log(n)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto comp = [&] (const pair<int, int> &a, const pair<int, int> &b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        
        vector<pair<int, int>> heap;
        for (int i = 0; i < n; ++i) {
            heap.push_back({i, 0});
        }
        int count = 0;
        make_heap(heap.begin(), heap.end(), comp);        
        
        while (count < k && !heap.empty()) {
            auto [r, c] = heap.front();
            pop_heap(heap.begin(), heap.end(), comp); heap.pop_back();
            if (++count == k) {
                return matrix[r][c];
            }
            
            if (c < n - 1) {
                int nc = c + 1;
                heap.push_back({r, nc});
                push_heap(heap.begin(), heap.end(), comp);
            }            
        }
        return -1;
    }
};
