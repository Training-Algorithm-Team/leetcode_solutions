// https://leetcode.com/problems/robot-bounded-in-circle/

/* Analysis:
- Ta chi quan tam den diem dau va diem cuoi cua quang duong.
- Neu huong cua diem cuoi nguoc voi huong cua diem dau thi robot se quay lai (0, 0) ngay vong sau do. Neu huong cua diem cuoi vuong goc 
voi huong cua diem dau thi no se quay lai sau khi di duoc 1 hinh vuong.
- No chi di ra vo han khi ma ket thuc luot dau tien no huong len tren va diem ket thuc la khac voi diem khoi dau
*/

class Solution {
public:
    typedef pair<int, int> pii;
    const vector<pii> dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    bool isRobotBounded(string instructions) {
        int d = 0;
        pii pos = {0, 0};
        for (char &c : instructions) {
            switch (c) {
                case 'G':
                    pos.first += dirs[d].first;
                    pos.second += dirs[d].second;
                    break;
                case 'L':
                    d = (d + 1) % dirs.size();
                    break;
                case 'R':
                    d = (d + 3) % dirs.size();
                    break;
                default:
                    //Nothing
                    return false;
            }
        }
        
        return !(d == 0 && (pos.first != 0 || pos.second != 0));
    }
};
