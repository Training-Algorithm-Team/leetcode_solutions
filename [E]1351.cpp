//Problem: 1351. Count Negative Numbers in a Sorted Matrix - Easy
//Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

/*
1. Nhận xét:
- Ở mỗi hàng, các số xếp theo thứ tự ĐƠN ĐIỆU không tăng, nên ta có thể dùng binary search để tìm ra biên giữa số không âm và số âm.
- Với mỗi cột, các số cũng đều không tăng, cho nên một số nếu là âm ở hàng trên, cũng sẽ là âm ở hàng dưới. Cho nên ta giữ nguyên biên bên phải (biến r) ở dòng trên để 
sử dụng cho dòng dưới, có thể hạn chế một chút không gian tìm kiếm.
- Trường hợp một dòng toàn bộ là số 0 ( điều kiện grid[i][l] < 0 ), ta phải cộng thêm 1 vào biến count. Ngoài ra ta có thể dừng luôn việc tìm kiếm, tuy nhiên sẽ phải xử lý
thêm 1 chút code, mà độ phức tạp thì không ảnh hưởng lên toàn bộ các trường hợp nên có thể bỏ qua.
- Độ phức tạp: O(m * logn)
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int count = 0;
        for (int i = 0; i < m; ++i) {
            int l = 0, r = n;
            while (r - l > 1) {
                int mid = l + (r - l) / 2;
                if (grid[i][mid] >= 0) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            count += n - l - 1;
            if (grid[i][l] < 0) {
                count++;
            }
        }
        return count;
    }
};
