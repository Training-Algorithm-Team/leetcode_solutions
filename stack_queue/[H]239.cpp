// Problem: 239. Sliding Window Maximum - Hard
// https://leetcode.com/problems/sliding-window-maximum/

/* C1:
- Để tìm max của một khoảng, ta có thể đưa khoảng đó vào map (binary search tree) và lấy phần tử cuối cùng.
- Mỗi khi window chạy, ta làm thao tác thêm và xoá trong map.
- Như vậy độ phức tạp là O(nlog(n))
- Space complexity: O(k)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      map<int, int> window;
      vector<int> res;
      for (int i = 0; i < n; ++i) {
        window[nums[i]]++;
        if (i >= k - 1) {
          if (i >= k) {
            int v = nums[i-k];
            window[v]--;
            if (window[v] == 0) {
              window.erase(v);
            }  
          }
          res.push_back(window.rbegin()->first);
        }
      }
      return res;
    }
};

/* C2:
- Cách này khá khó (thật ra là quá khó :)) tuy nhiên có độ phức tạp O(1)
- Một cửa sổ cũng có thể coi như 1 queue, ta thêm vào cuối, và lấy phần tử ra từ đầu.
- Tuy nhiên để tìm max của queue là không thể, do ta thay đổi giá trị của nó ở cả hai đầu. Vì thế ta mô phỏng queue này bằng 2 stack.
Ta có thể tìm được max của stack do ta chỉ thêm và bớt phần tử từ một đầu.
- Từ đó ta có thể tìm max của queue chính là max của 2 stack.
- Time complexity: O(n)
- Space complexity: O(k)
*/
class Solution {
public:
  typedef pair<int, int> pii;
  int getMax(const stack<pii> &_push, const stack<pii> &_pop) {
    int res = INT_MIN;
    if (!_push.empty()) {
      res = max(res, _push.top().second);
    }
    if (!_pop.empty()) {
      res = max(res, _pop.top().second); 
    }
    return res;
  }
  
  void pushValue(stack<pii> &_push, int val) {
    int maxVal = val;
    if (!_push.empty()) {
      maxVal = max(maxVal, _push.top().second); 
    }
    _push.push({val, maxVal});
  }
  
  void popValue(stack<pii> &_push, stack<pii> &_pop) {
    if (_pop.empty()) {
      while(!_push.empty()) {
        pushValue(_pop, _push.top().first);
        _push.pop();
      }
    }
    _pop.pop();
  }
               
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
      stack<pii> _push, _pop;
      vector<int> res;
      for (int i = 0; i < n; ++i) {
        pushValue(_push, nums[i]);
        if (i >= k - 1) {
          if (i >= k) {
            popValue(_push, _pop);
          }
          res.push_back(getMax(_push, _pop));
        }
      }
      return res;
    }
};
