// Problem: 692. Top K Frequent Words - Medium
// Link: https://leetcode.com/problems/top-k-frequent-words/

/* Nhận xét:
- Do ta cần giữ lại tập k phần tử, và CÓ THỂ SẮP XẾP THỨ TỰ trên tập kết quả, nên ta lưu 1 heap có k phần tử, và sắp xếp để cho sau khi duyệt hết dãy, toàn bộ
các kết quả sẽ nằm lại trong heap này.
- Do ta cần lưu k phần tử lớn nhất, nên ta sẽ lưu 1 min heap, để ta có thể loại dần các phần tử không nằm trong tập kết quả (phần tử nhỏ nhất trong k + 1 phần tử sẽ
bị loại đi). 
- Sau đó, với các phần tử có freq bằng nhau, ta cần đẩy các phần tử có thứ tự từ điển lớn hơn lên trên, để các phần tử này bị loại đi. Kèm theo đó là các phần tử này
sẽ xuất hiện trước trong tập kết quả (các phần tử có thứ tự từ điển nhỏ hơn sẽ được pop ra sau và push_back => sẽ nằm sau ở trong tập kết quả)
- Time complexity: O(nlog(k))
- Space complexity: O(n);
*/

public:
    typedef pair<int, string> pis;
    class Comp {
        public:
        bool operator()(const pis &a, const pis &b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for (string &s : words) {
            hash[s]++;
        }
        
        priority_queue<pis, vector<pis>, Comp> heap;
        for (auto &[s, v] : hash) {
            heap.push({v, s});
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<string> res(k);
        int i = k - 1;
        while (!heap.empty() && i >= 0) {
            res[i--] = heap.top().second;
            heap.pop();
        }
        return res;
    }
};
