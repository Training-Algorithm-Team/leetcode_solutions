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
        int l = 0, r = n - 1;
        while (r - l > 0) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        int i = r, j = r - 1;
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
