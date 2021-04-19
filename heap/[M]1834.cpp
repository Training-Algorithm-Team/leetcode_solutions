// 1834. Single-Threaded CPU - Medium
// https://leetcode.com/problems/single-threaded-cpu/

/* Analysis:
- First, we sort from big to small. We choose the small then add to priority_queue first.
- Each time, we process the priority queue 1 by 1, and plus the length to end time.
- After each processing, we add other small start time if possible.
- If smallest one is larger than the end time, we update end time the that smallest start time.
- Time complexity: O(nlog(n))
- Space complexity: O(n).
*/

class Solution {
public:
    typedef pair<int, int> pii;
    class Comp {
    public:
        bool operator()(const pii &a, const pii &b) {
            return a.first > b.first || (a.first == b.first && a.second > b.second);
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int &a, int &b){
            return tasks[a][0] > tasks[b][0];
        });
        
        priority_queue<pii, vector<pii>, Comp> waiting;
            
        long endTime = -1;
        vector<int> res;
        while (!idx.empty() || !waiting.empty()) {
            while (!idx.empty()) {
                int t = idx.back();
                if (waiting.empty()) {
                    endTime = max((long)tasks[t][0], endTime);
                }
                
                if (tasks[t][0] <= endTime) {
                    idx.pop_back();
                } else {
                    break;
                }
                waiting.push({tasks[t][1], t});
            }
            
            int t = waiting.top().second;
            int length = waiting.top().first;
            endTime += length;
            res.push_back(t);
            waiting.pop();
        }
        return res;
    }
};
