// Problem: 939. Minimum Area Rectangle - Medium
// Link: https://leetcode.com/problems/minimum-area-rectangle/

/* C1: cách tù.
- Với mỗi điểm {x, y}, ta lưu vào 2 hash table hash[x].insert(y) và hash[y].insert(x). Như vậy ta sẽ có được các điểm nằm trên tung độ và hoành độ cụ thể.
- Sau đấy ta lại lưu thành hash table của tất cả các hoành độ và tất cả các tung độ.
- Sau đó, với mỗi hoành độ x1 trong hash table của các hoành độ, ta chọn 2 tung độ y1, y2 ra, và xét để tìm 1 hoành độ x2 chung, nằm trong cả 2 hash table của 2 tung độ 
nói trên.
- Tính diện tích và lưu lại kết quả
- Time complexity: O(n^4)
- Space complexity: O(2 * n). Với mỗi điểm ta sẽ có tương ứng 1 phần tử trong 1 hash table. Ta có 2 hash table vậy space gấp đôi lên.
*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> xPoints, yPoints;
        
        for (auto &p : points) {
            xPoints[p[0]].insert(p[1]);
            yPoints[p[1]].insert(p[0]);
        }
        
        int res = INT_MAX;
        for (auto xit = xPoints.begin(); xit != xPoints.end(); ++xit) {
            int x = xit->first;
            unordered_set<int> &correspondingY = xit->second;
            for (auto it1 = correspondingY.begin(); it1 != correspondingY.end(); ++it1) {
                for (auto it2 = next(it1); it2 != correspondingY.end(); ++it2) {
                    int y1 = *it1, y2 = *it2;
                    for (auto nextX = yPoints[y1].begin(); nextX != yPoints[y1].end(); ++nextX) {
                        if (*nextX != x && yPoints[y2].find(*nextX) != yPoints[y2].end()) {
                            res = min(res, abs((y2 - y1) * ((*nextX) - x)));
                        }
                    }
                }
            }            
        }
        return res == INT_MAX? 0 : res;
    }
};

/* C2: 
- Ta lưu 1 hash table cho tất cả các điểm.
- Với 2 điểm bất kì, nếu nó không cùng nằm trên 1 đường thẳng song song với trục tọa độ => nó có thể trở thành 2 góc của hình chữ nhật => Ta tìm trong hash table
xem có tồn tại 2 góc còn lại hay không.
- Nếu có thì tính diện tích và update kết quả.
- Vì một pair<int, int> không thể có hàm hash tương ứng nên tôi convert tọa độ thành một số integer, và làm thêm 1 hàm revert tương ứng.
*/
class Solution {
public:
    const int c = 50000;
    int convert(const int &x, const int &y) {
        return x * c + y;
    }
    pair<int, int> revert(const int &p) {
        return {p / c, p % c};
    }
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> hash;
        for (auto &p : points) {
            hash.insert(convert(p[0], p[1]));
        }
        
        int res = INT_MAX;
        for (auto it1 = hash.begin(); it1 != hash.end(); ++it1) {
            for (auto it2 = next(it1); it2 != hash.end(); ++it2) {
                const auto &[x1, y1] = revert(*it1);
                const auto &[x2, y2] = revert(*it2);
                if (x1 != x2 && y1 != y2 && hash.count(convert(x1, y2)) && hash.count(convert(x2, y1))) {
                    res = min(res, abs((x1 - x2) * (y1 - y2))); 
                }
            }
        }
        return res == INT_MAX? 0 : res;
    }
};
