// Problem: 1705. Maximum Number of Eaten Apples - Medium
// Link: https://leetcode.com/problems/maximum-number-of-eaten-apples/

/* Nhận xét:
- Mỗi ngày, ta có thể ăn 1 quả táo, để tối ưu nhất có thể, ta nên chọn quả nào sắp hết hạn trước. Vậy ta có thể dùng heap để chọn phần tử có ngày hết hạn nhỏ nhất
với độ phức tạo log(n)
- Time complexity: O(nlog(n))
- Space complexity: O(n)
*/

class Solution {
public:
    typedef pair<int, int> pii;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        priority_queue<pii, vector<pii>, greater<pii>> heap;

        int d = 0;
        int res = 0;
        do {
            if (d < n && apples[d]) {
                heap.push({d + days[d], apples[d]});
            }
            
            while(!heap.empty() && heap.top().first <= d) {
                heap.pop();
            }
            if (!heap.empty()) {
                int x = heap.top().first;
                int y = heap.top().second;
                // cout << "before heap.size = " << heap.size() << endl;
                heap.pop();
                res++;
                if (y > 1) {
                    heap.push({x, --y});
                }
            }
            d++;
        } while (d < n || !heap.empty());
        return res;
    }
};
