// Problem: 155. Min Stack - Easy (Easy cái khỉ gió ý :)))
// Link: https://leetcode.com/problems/min-stack/

/* Nhận xét:
- Min của stack là min của toàn bộ các phần tử đã có trong stack ( giả sử là x). Khi push thêm phần tử y vào stack, vậy min của stack sẽ là min(x, y)
=> Bài này có yếu tố quy hoạch động. Min của cả dãy là min của dãy trước đó và phần tử hiện tại.
- Ta lưu kèm với mỗi phần tử khi thêm vào stack là giá trị min của dãy kết thúc tại phần tử đó.
*/ 

class MinStack {
  private:
    vector<pair<int, int>> st;
  public:
  
  MinStack() {
    
  }
  
  void push(int x) {
    int prevMin = INT_MAX;
    if (!st.empty()) {
      prevMin = st.back().second;
    }
    st.push_back({x, min(x, prevMin)});
  }
  
  void pop() {
    if (!st.empty()) {
      st.pop_back(); 
    }
  }
                 
  int top() {    
    return st.back().first; 
  }
                 
  int getMin() {
    return st.back().second;
  }  
};
