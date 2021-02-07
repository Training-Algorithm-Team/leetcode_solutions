// Problem: 456. 132 Pattern - Medium
// Link: https://leetcode.com/problems/132-pattern/

/* Nhận xét:
- Với một đỉnh i bất kì, ta muốn nó là đỉnh 3 trong pattern 132 thì ta phải thỏa mãn 3 điều kiện:
	+ Phải có ít nhất 1 điểm j phía trước i và nhỏ hơn i
	+ Phải có ít nhất 1 điểm k phía sau i và nhỏ hơn i
	+ Điểm k phải lơn hơn điểm j
- Ta sẽ chọn điểm j tốt nhất có thể, tức là giá trị min trong đoạn [0, i)
- Ta cần chọn giá trị k tốt nhất có thể, tức là giá trị nhỏ hơn i trong đoạn (i, n), nhưng phải là lớn nhất có thể. 
Điều này ta có thể thực hiện được bằng cách lưu 1 map (có key giảm dần) số lần xuất hiện toàn bộ các giá trị, 
duyệt đến đâu ta giảm số lần xuất hiện của nó đi 1, nếu bằng 0 thì ta xóa phần tử đó đi. 
Sau đó vỡi mỗi phần tử i, ta look up phần tử ngay phía sau i trong map (tức là phần tử nhỏ hơn i nhưng lớn nhất có thể. 
Nếu phần tử này lớn hơn j thì ta trả về true.
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        map<int, int, greater<int>> m;
        for (int &v : nums) {
            m[v]++;
        }
        
        int pos1 = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (--m[nums[i]] <= 0) {
                m.erase(nums[i]);
            }            
            
            if (nums[pos1] < nums[i]) {
                auto it = m.upper_bound(nums[i]);
                if (it != m.end() && it->first > nums[pos1]) {
                    return true;
                }
            } else {
                pos1 = i;
            }
        }
        return false;
    }
};
