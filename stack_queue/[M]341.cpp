// Problem: 341. Flatten Nested List Iterator - Medium
// Link: https://leetcode.com/problems/flatten-nested-list-iterator/

/* Nhận xét:
- Nếu ta coi như list ban đầu là 1 cây, các list phía trong là nốt trong và các integer là nốt lá. Như vậy ta sẽ có một cây. Và công việc là phải 
list ra các nốt lá theo thứ tự từ trái sang phải.
- Ban đầu ta đẩy hết các nốt vào cây. Nếu gặp một nốt trong, ta phải tiếp tục extract nó ra và DUYỆT TRƯỚC các nốt còn lại trong cây, vì ta cần duyệt các nốt lá trước. 
Do đó ta sẽ dùng một stack để mô phỏng cây này, sau khi extract ra sẽ đẩy toàn bộ các nốt mới vào cây.
- Cây là hasNext khi mà top of stack là một nốt lá. Vì hàm hasNext được gọi trước hàm next nên đã đảm bảo top luôn là nốt lá => hàm next có thể luôn lấy top of stack.
- Time complexity: 
  + constructor: O(n) tương đương với số phần tử con của root.
  + hasNext: O(n) tương đương với độ sâu tối đa của cây.
  + next: O(1)
- Space complexity: O(n)
*/

class NestedIterator {
public:
    stack<NestedInteger> st;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            st.push(nestedList[i]);
        }    
    }
    
    int next() {
        while (!st.top().isInteger()) {
            auto list = st.top().getList();
            st.pop();
            for (int i = list.size() - 1; i >= 0; --i) {
                st.push(list[i]);
            }
        }
        int res = st.top().getInteger();
        st.pop();
        return res;
    }
    
    bool hasNext() {
        while (!st.empty() && !st.top().isInteger()) {
            auto list = st.top().getList();
            st.pop();
            for (int i = list.size() - 1; i >= 0; --i) {
                st.push(list[i]);
            }
        }
        return !st.empty();
    }
};
