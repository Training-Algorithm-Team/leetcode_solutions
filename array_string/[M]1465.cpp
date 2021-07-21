// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

/* Analysis:
- Chon do rong nhat va cao nhat thi tim ra dien tich cua mieng cat thoi.

*/

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int mod = 1e9 + 7;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        int m = horizontalCuts.size(), n = verticalCuts.size();
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHeight = 0;
        for (int i = 1; i < m; ++i) {
            maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        int maxWidth = 0;
        for (int i = 1; i < n; ++i) {
            maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i-1]);
        }
        
        long area = (long)maxWidth * maxHeight;
        area %= mod;
        
        return area;
    }
};
