// Problem: 1046. Last Stone Weight - Easy
// Link: https://leetcode.com/problems/last-stone-weight/

/* Nhận xét:
- Do ta luôn phải lấy 2 phần tử lớn nhất trong dãy, kể cả sau khi đã thêm phần tử mới vào dãy. Do đó dùng heap sẽ hợp lý nhất.
- Ta cũng có thể dùng multiset nhưng khi đó ta phải thực hiện erase và insert bằng, code sẽ phức tạp hơn 1 chút.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        while (heap.size() > 1) {
            int y = heap.top(); heap.pop();
            int x = heap.top(); heap.pop();
            if (y > x) {
                heap.push(y - x);
            }
        }
        return heap.empty()? 0 : heap.top();
    }
};
