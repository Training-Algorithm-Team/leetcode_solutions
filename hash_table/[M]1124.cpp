// Problem: 1124. Longest Well-Performing Interval - Medium
// Link: https://leetcode.com/problems/longest-well-performing-interval/

/* Nhận xét:
- Ta có thể cho những ngày > 8 là 1 điểm, những ngày nhỏ hơn 8 là -1 điểm. Ta có thể dùng prefix sum để tính tổng điểm đến ngày hiện tại.
- Giả sử một đoạn WPI dài nhất có độ dài nhỏ hơn n => thì nó luôn có tổng điểm của đoạn là 1. Lý do: Giả sử tổng điểm của đoạn > 1.
  + Nếu bên cạnh nó là số 1 => ta sẽ có một đoạn WPI dài hơn => mâu thuẫn.
  + Nếu bên cạnh nó là số 0 => Vì tổng điểm > 1 => ta vẫn build được 1 đoạn dài hơn.
- Do đó, ta dùng một hash table, tính lần đầu tiên xuất hiện của 1 số điểm xác định (lần đầu tiền xuất hiện để ta có thể tìm được đoạn dài nhất có thể). Sau đó, tìm lần 
xuất hiện của điểm cur - 1, và cập nhật kết quả. Trường hợp điểm của cả dãy lớn hơn 0 => ta trả về kết quả là độ dài dãy.
*/

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> hash;
        hash.insert({0, -1});
        
        int cur = 0;
        int res = 0;
        for (int i = 0; i < hours.size(); ++i) {
            if (hours[i] > 8) {
                cur++;
            } else {
                cur--;
            }
            if (hash.find(cur) == hash.end()) {
                hash[cur] = i;
            }
            if (hash.find(cur - 1) != hash.end()) {
                res = max(res, i - hash[cur-1]);
            }
        }
        return cur > 0 ? hours.size() : res;
    }
};
