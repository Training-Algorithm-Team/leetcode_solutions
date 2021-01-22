// Problem: 875. Koko Eating Bananas - Medium
// Link: https://leetcode.com/problems/koko-eating-bananas/

/* Nhận xét:
- Giả sử k là điểm cần tìm, vậy mọi điểm đằng sau k đều cho phép ăn hết chuối trong vòng h tiếng. Và mọi điểm trước k đều không đủ để ăn hết.
- Vì k là điểm NHỎ NHẤT, nên ta sẽ đẩy kết quả về biến r.
*/

class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        int count = 0;
        for (int p : piles) {
            count += p / k;
            if (p % k > 0) {
                count++;
            }
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = INT_MAX;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (canEat(piles, h, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
