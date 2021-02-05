// Problem: 970. Powerful Integers - Medium
// Link: https://leetcode.com/problems/powerful-integers/

/* Nhận xét:
- Bài này anh bị overthinking rồi, anh chả biết nói gì nữa.
- Time complexity: O(log(bound) * log(bound) * log(log(bound))). Số lượng đáp án có thể là O(log(bound) * log(bound)). Với mỗi đáp án có thể, ta còn phải push thêm phần tử
mới vào heap, heap có độ lớn là log(bound) => Độ phức tạp thao tác push là log(log(bound)).
- Space complexity: O(log(bound)).
*/

class Solution {
public:
    typedef pair<int, int> pii;
    typedef pair<int, pii> pip;
    vector<int> powerfulIntegers(int x, int y, int bound) {
        priority_queue<pip, vector<pip>, greater<pip>> heap;

        for (int powy = 1; powy + 1 <= bound; powy *= y) {
            heap.push({1 + powy, {1, powy}});
            if (y == 1) {
                break;
            }
        }    
        
        
        unordered_set<int> res;
        while (!heap.empty()) {
            res.insert(heap.top().first);
            auto [powx, powy] = heap.top().second;
            heap.pop();
            
            if (powx == powx * x) {
                continue;
            }
            int u = powx * x + powy;
            if (u <= bound) {
                heap.push({u, {powx * x, powy}});
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
