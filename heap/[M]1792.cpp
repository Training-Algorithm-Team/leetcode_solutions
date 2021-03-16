// 1792. Maximum Average Pass Ratio - Medium
// https://leetcode.com/problems/maximum-average-pass-ratio/

/* Analysis:
- Each time we add a student, we need to choose a class that increases pass ratio the most. So we can put them into a heap, sorted based on the increase ratio 
((p + 1) / (t + 1)) - (p / t).
- Each time, we pop a class from heap, add 1 student and push it back. After m times, we stop and calculate the average base on all elements in the heap.
- Time complexity: (n + m)log(n). m times pop-push takes O(mlog(n)). n times pop to calculate result takes O(nlog(n)).
- Space complexity: O(n).
*/

class Solution {
public:
    typedef pair<int, int> pii;
    class Comp {
    public:
        bool operator()(const pii& a, const pii &b) {
            double p1 = a.first, t1 = a.second, p2 = b.first, t2 = b.second;
            
            double inc1 = ((p1 + 1) / (t1 + 1)) - (p1 / t1);
            double inc2 = ((p2 + 1) / (t2 + 1)) - (p2 / t2);
            
            return inc1 < inc2;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        
        priority_queue<pii, vector<pii>, Comp> heap;
        for (int i = 0; i < n; ++i) {
            heap.push({classes[i][0], classes[i][1]});
        }
        
        while (extraStudents-- > 0) {
            auto [p, t] = heap.top();
            heap.pop();
            
            p++; t++;
            heap.push({p, t});
        }
        
        double sum = 0;
        while(!heap.empty()) {
            auto [p, t] = heap.top();
            heap.pop();
            
            sum += (double) p / t;
        }
        return sum / n;
    }
};
