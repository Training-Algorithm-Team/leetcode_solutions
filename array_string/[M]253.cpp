// https://leetcode.com/problems/meeting-rooms-ii/

/* Analysis:
- Ta trai cac doan ra mot truc toa do, danh dau diem dau diem cuoi
- Sau do chay mot vong for de tinh so concurent meeting tai 1 thoi diem.
- Ket qua se la max value.

*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        const int maxSlot = 1000001;
        
        vector<int> schedule(maxSlot, 0);
        for (auto &intv : intervals) {
            schedule[intv[0]]++;
            schedule[intv[1]]--;
        }
        
        int room = schedule[0];
        for (int i = 1; i < maxSlot; ++i) {
            schedule[i] += schedule[i-1];
            room = max(room, schedule[i]);
        }
        return room;
    }
};
