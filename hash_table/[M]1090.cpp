// Problem: 1090. Largest Values From Labels - Medium
// Link: https://leetcode.com/problems/largest-values-from-labels/

/* Nhận xét:
- Ta có thể thấy nếu muốn tổng tạo ra là to nhất, ta cần chọn những số lớn nhất với từng label khác nhau. Trong trường hợp này, nếu ta chọn các số theo thứ tự giảm dần
trên toàn bộ tập values ban đầu cũng không làm sai lệch kết quả, chỉ cần loại bỏ đi các value với nhãn đã bị sử dụng quá số lượng use_limit.
- Tiếp tục nhận thấy là ta chỉ cần lựa các số lớn nhất cho tới khi đủ số lượng num_wanted, cho nên nhiều trường hợp ta không cần thiết phải sort cả dãy. Do đó, ta có thể
sử dụng heap để lấy lần lượt các phần tử theo thứ tự giảm dần.
- Ngoài ra, để kiểm tra số lượng phần tử của một nhãn đã vượt qua use_limit chưa, ta dùng một hash table để đếm số lượng tương ứng với nhãn.
*/

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n = values.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        make_heap(idx.begin(), idx.end(), [&](const int &a, const int &b) {
            return values[a] < values[b];
        });
        
        int got = 0;
        unordered_map<int, int> used;
        int sum = 0;
        while (got < num_wanted && !idx.empty()) {
            int i = idx.front();
            int val = values[i];
            int l = labels[i];
            pop_heap(idx.begin(), idx.end(), [&](const int &a, const int &b) {
                return values[a] < values[b];
            }); 
            idx.pop_back();
            
            if (used[l] < use_limit) {
                got++;
                used[l]++;
                sum += val;
            }
        }
        return sum;
    }
};
