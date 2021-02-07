// Problem: 950. Reveal Cards In Increasing Order
// Link: https://leetcode.com/problems/reveal-cards-in-increasing-order/

/*
- Ta đẩy toàn bộ deck vào một queue để mô phỏng thao tác của đề bài. Mỗi lần lặp, ta thực hiện liền 2 thao tác lấy phần tử ra 
và lấy phần tử rồi thêm vào cuối.
- Mỗi lần lấy ra, ta lấy idx của deck ban đầu, để ta biết được vị trí ta sẽ thêm phần tử vào.
- Ngoài ra ta cần sort dãy ban đầu để fill các phần tử theo thứ tự tăng dần.
- Time complexity: Hơi khó đánh giá. Số lượng phép toán tích cực sẽ là: n + n/2 + n/4 + n/8 + ... 
(do sau mỗi lần duyệt hết dãy thì số lượng phần tử sẽ giảm đi một nửa)
- Space complexity: O(n)
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
        }
        
        vector<int> res(n);
        int idx = 0;
        while (q.size() > 1) {
            res[q.front()] = deck[idx++];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        res[q.front()] = deck[idx];
        return res;
    }
};
