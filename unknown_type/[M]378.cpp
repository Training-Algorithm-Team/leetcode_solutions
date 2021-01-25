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
    typedef pair<int, pair<int, int>> pp;
    
    class Comp {
    public:
        bool operator() (const pp &a, const pp &b) {
            return a.first > b.first;
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        priority_queue<pp, vector<pp>, Comp> heap;
        for (int i = 0; i < k && i < n; ++i) {
            heap.push({matrix[i][0], {i, 0}});
        }
        int count = 0;
        
        while (count < k && !heap.empty()) {
            auto val = heap.top();
            int r = val.second.first;
            int c = val.second.second;
            heap.pop();
            if (++count == k) {
                return matrix[r][c];
            }
            
            if (c < n - 1) {
                heap.push({matrix[r][c+1], {r, c + 1}});
            }            
        }
        return -1;
    }
};
