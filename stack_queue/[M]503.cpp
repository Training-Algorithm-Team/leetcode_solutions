// Problem: 503. Next Greater Element II - Medium
// Link: https://leetcode.com/problems/next-greater-element-ii/

/* C1:
- Nếu ở mỗi phần tử, ta update lại các phần tử nhỏ hơn đứng trước nó trong stack, thì ta sẽ được một stack giảm dần về giá trị khi duyệt hoàn tất.
- Vấn đề đặt ra là làm thế nào để update được giá trị cho các phần tử còn lại trong stack.
- Để làm được việc này, ta cần phải có một dãy tăng dần các phần tử trong dãy ban đầu. Với mỗi phần tử trong stack, ta duyệt qua dãy tăng dần này, 
đến khi nào gặp phần tử lớn hơn nó thì dừng lại và update giá trị. Làm như vậy cho đến khi hết dãy thì thôi. Với cách duyệt đó, ta sẽ cần sử dụng 1 
queue để có thể lưu dãy tăng dần. Sẽ có thể có một vài phần tử có giá trị lớn nhất nằm lại trong stack, tuy nhiên ta khởi tạo kết quả cho 
mọi phần tử là -1, nên ta sẽ ko cần phải update lại giá trị cho các phần tử này.
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (0 == n) {
            return {};
        }
        vector<int> res(n, -1);
        
        deque<int> increasing;
        stack<int> decreasing;
        
        increasing.push_back(0); decreasing.push(0);
        for (int i = 1; i < n; ++i) {
            while (decreasing.size() > 0) {
                int j = decreasing.top();
                if (nums[i] <= nums[j]) {
                    break;
                }
                res[j] = nums[i];
                decreasing.pop();
            }
            decreasing.push(i);
            
            if (nums[increasing.back()] < nums[i]) {
                increasing.push_back(i);   
            }
        }
        
        while (decreasing.size() > 0) {
            int i = decreasing.top();
            decreasing.pop();
            
            while (increasing.size() > 0 && nums[i] >= nums[increasing.front()]) {
                increasing.pop_front();   
            }
            if (increasing.size() > 0) {
                res[i] = nums[increasing.front()];   
            }
        }
        return res;
    }
};

/* C2:
- Nếu ta nhân đôi dãy ban đầu lên và duyệt qua toàn bộ dãy mới thì các phần tử ở dãy ban đầu sẽ có thể được update giá trị như khi đã duyệt 
đủ một vòng tròn theo yêu cầu của đề bài.
- Ta có thể giả lập việc nhân đôi dãy này bằng cách duyệt qua mảng 2 lần, và lưu lần lượt các phần tử vào 1 stack. 
Khi lưu phần tử mới, ta update giá trị cho toàn bộ các phần tử đã nằm trong stack mà nhỏ hơn nó.
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (0 == n) {
            return {};
        }
        stack<int> st;
        vector<int> res(n, -1);
        for (int k = 0; k < 2; ++k) {
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && nums[st.top()] < nums[i]) {
                    res[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};
