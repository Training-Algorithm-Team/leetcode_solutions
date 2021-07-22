// https://leetcode.com/problems/reorganize-string/

/* Analysis:
- I will always try to put the most frequent character first, so we use a max heap to store the chars. And a wait char after 1 round.

*/

class Solution {
public:
    typedef pair<int, char> pic;
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; ++i) {
            freq[s[i] - 'a']++;
        }
        
        priority_queue<pic> heap;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                heap.push({freq[i], 'a' + i});   
            }
        }
        
        pic wait = {0, 'a'};
        string res;
        while (!heap.empty()) {
            auto [f, c] = heap.top();
            heap.pop();
            
            res += c;
            if (wait.first > 0) {
                heap.push(wait);
            }
            wait = {--f, c};
        }
        if (res.size() == n) {
            return res;   
        } else {
            return "";
        }
    }
};
