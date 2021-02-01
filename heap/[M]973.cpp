// Problem: 973. K Closest Points to Origin - Medium
// Link: https://leetcode.com/problems/k-closest-points-to-origin/

/* Nhận xét:
- Để có danh sách k phần tử nhỏ nhất với một tập có n phần tử, ta đẩy toàn bộ các phần tử qua 1 min heap và pop heap k lần. Như vậy số phần tử còn lại trong heap sẽ 
phải là (n - k) phần tử. Mỗi khi số lượng phần tử quá (n-k), ta sẽ pop ra và thêm vào kết quả.
*/

class Solution {
public:
    typedef pair<int, pair<int, int>> pip;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pip, vector<pip>, greater<pip>> heap;
        int heapSize = n - k;
        
        vector<vector<int>> res;
        for (auto &pos : points) {
            int x = pos[0], y = pos[1];
            heap.push({x * x + y * y, {x, y}});
            if (heap.size() > heapSize) {
                res.push_back({heap.top().second.first, heap.top().second.second});
                heap.pop();
            }
        }
        return res;
    }
};
