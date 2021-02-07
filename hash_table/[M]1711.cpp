// Problem: 1711. Count Good Meals - Medium
// Link: https://leetcode.com/problems/count-good-meals/

/* Nhận xét:
- Với mỗi power của 2, gọi là target, ở một điểm i với d[i], ta tìm số lượng phần tử [target - d[i]] và thêm vào kết quả.
- Do có nhiều target, ta tính trước toàn bộ target rồi lưu vào một mảng. Mảng này có độ dài bằng log(maxVal) = 22.
- Time complexity: O(n * log(maxVal) = O(22n)
- Space complexity: O(n);
- Bài này khi anh bỏ dòng kiểm tra trước khi thêm vào kết quả (tức là nếu phần tử chưa tồn tại sẽ được tạo mới), thì thời gian chạy lên tận 1000ms. Có vẻ
như unordered_map khi số lượng phần tử tăng lên thì khả năng bị collision là khá lớn dẫn đến thời gian chạy rất lâu nên độ phức tạp ko còn là O(1) nữa.
- Ngoài ra nếu dùng hash bằng vector thì tốc độ còn có thể giảm đi 1 nửa.
*/

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int maxPower = 21;
        const int mod = 1e9 + 7;
        vector<int> powerof2;
        for (int i = 0; i <= maxPower; ++i) {
            powerof2.push_back(1 << i);
        }
        unordered_map<int, int> hash;
        int res = 0;
        for (int &d : deliciousness) {
            for (int i = 0; i <= maxPower; ++i, res %= mod) {
                if (hash.find(powerof2[i] - d) != hash.end()) { // Nếu bỏ dòng này đi thì chạy mất 1000ms
                    res += hash[powerof2[i] - d];
                }
            }
            hash[d]++;
        }
        return res;
    }
};
