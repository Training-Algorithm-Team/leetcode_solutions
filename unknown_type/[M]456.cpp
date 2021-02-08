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

/* Cách 2:
- Giả sử với một đoạn tăng dần, 1 2 3 4, thì ta chỉ quan tâm điểm 4 và điểm 1, hai điểm 2 và 3 không ý nghĩa, ta có thể loại bỏ để tránh phải duyệt nhiều.
Điều đó dẫn ta đến ý tưởng sử dụng 1 stack lưu dãy theo thứ tự giảm dần. Ngoài ra, tại mỗi đỉnh, ta lưu thêm giá trị min của đoạn trước đó để có thể so sánh về sau.
- Như vậy đến một điểm bất kì, nếu điểm đó < top of stack và  > (min của đoạn kết thúc tại top of stack) thì ta kết luận.
- Nếu lớn hơn top of stack thì ta pop ra và push giá trị mới vào.
- Nếu nhỏ hơn thì ta push vào stack.
*/
class Solution {
public:
    typedef pair<int, int> pii;
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<pii> st;
        for (int i = 0; i < n; ++i) {
            int minVal = nums[i];
            while (!st.empty() && st.top().first < nums[i]) {
                minVal = min(minVal, st.top().second);
                st.pop();
            }
            if (!st.empty() && nums[i] < st.top().first && nums[i] > st.top().second) {
                return true;   
            }
            st.push({nums[i], minVal});
        }
        return false;
    }
};
