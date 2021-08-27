// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> vals, ops;
        int curOp = 1;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int temp = 0;
                while (i < n && isdigit(s[i])) {
                    temp = temp * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                
                res += curOp * temp;
            } else if (s[i] == '(') {
                vals.push(res);
                ops.push(curOp);
                curOp = 1;
                res = 0;
            } else if (s[i] == ')') {
                res = res * ops.top() + vals.top();
                ops.pop(); vals.pop();
            } else if (s[i] == '+') {
                curOp = 1;
            } else if (s[i] == '-') {
                curOp = -1;
            }
        }
        
        return res;
    }
};
