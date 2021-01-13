// Problem: 658. Find K Closest Elements - Medium
// Link: https://leetcode.com/problems/find-k-closest-elements/

/* Nhận xét:
- Anh ko hiểu bài này làm binary search kiểu gì luôn đấy. Chú thử gợi ý anh xem?
- Anh submit 5 lần, lần nào cũng beat 100%, phải chăng bài này làm cách bình thường thì nhanh hơn binary search?
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int s = 0;
        while (s < n) {
            if (arr[s] >= x) {
                break;
            }
            s++;
        }
        
        int i = s, j = s - 1;
        deque<int> res;
        while (i < n || j >=0) {
            if (i < n) {
                if (j >= 0) {
                    if (x - arr[j] <= arr[i] - x) {
                        res.push_front(arr[j--]);
                    } else {
                        res.push_back(arr[i++]);
                    }
                } else {
                    res.push_back(arr[i++]);  
                }
            } else {
                res.push_front(arr[j--]);  
            }
            if (0 == --k) {
                break;
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
