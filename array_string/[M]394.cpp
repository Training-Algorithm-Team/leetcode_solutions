// https://leetcode.com/problems/decode-string/

/* Vi cac cap ngoac co the nested => Ta phai dung stack de luu 

*/

class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;
        st.push({1, ""});
        int i = 0;
        
        while (i < s.size()) {
            if (s[i] > '0' && s[i] < '9') {
                int j = s.find('[', i);
                int times = stoi(s.substr(i, j - i));
                st.push({times, ""});
                i = j;
            } else if (s[i] == ']') {
                string temp;
                int times = st.top().first;
                for (int k = 0; k < times; k++) {
                    temp += st.top().second;
                }
                st.pop();
                st.top().second += temp;
            } else {
                st.top().second += s[i];
            }
            i++;
        }
        return st.top().second;  
    }
};
