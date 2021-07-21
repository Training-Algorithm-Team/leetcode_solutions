// https://leetcode.com/problems/random-pick-with-weight/

/* Analysis:
- Vi khi random ra cac so co ti le nhu nhau, nen voi so nao co weight lon hon, ta cho no chiem 1 khoang lon hon tren truc so.
- Ta dua chung vao sorted array, trong truong hop nay la 1 map.
- Random ra 1 so bat ki, chon diem can tren cua khoang do de return ra ket qua.

*/

class Solution {
private:
    map<int, int> mapWeight;
    int maxWeight;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        int val = 0;
        for (int i = 0; i < n; ++i) {
            val += w[i];
            mapWeight[val] = i;
        }
        maxWeight = val;
    }
    
    int pickIndex() {
        int num = rand() % maxWeight;
        auto it = mapWeight.upper_bound(num);
        return it->second;
    }
};
