// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars, int j, char c, int count) {
        chars[j++] = c;
        if (count == 1) {
            return j;
        }
        
        stack<int> st;
        while (count > 0) {
            st.push(count % 10);
            count /= 10;
        }
        while (!st.empty()) {
            chars[j++] = '0' + st.top();
            st.pop();
        }
        return j;
    }
    int compress(vector<char>& chars) {
        int n = chars.size();
        int count = 1;
        int j = 0;
        for (int i = 1; i < n; ++i) {
            if (chars[i] != chars[i - 1]) {
                j = compress(chars, j, chars[i-1], count);
                count = 1;
            } else {
                count++;
            }
        }
        j = compress(chars, j, chars[n-1], count);
        return j;
    }
};
