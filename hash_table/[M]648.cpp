// Problem: 648. Replace Words - Medium
// Link: https://leetcode.com/problems/replace-words/

/* Nhận xét: 
- Độ dài của các xâu trong từ điển là khác nhau, ta không thể tìm kiếm nhanh một root trong từ điển được.
- Ta có thể chia các xâu theo độ dài vào lưu vào một unordered_set cho mỗi xâu có độ dài bằng nhau. Như vậy việc look up có độ phức tạp O(1).
- Ta duyệt qua toàn bộ string, mỗi kí tự ta lại thêm vào xâu dùng để thay thế và look up trong hash table có độ dài tương ứng. Trường hợp đã tìm được thì ta không tăng 
xâu thay thế lên nữa.
- Khi gặp dấu cách hoặc hết string thì ta lại thêm xâu thay thế vào chuỗi kết quả.
*/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<unordered_set<string>> hsByLen(101);
        for (string &s : dictionary) {
            hsByLen[s.size()].insert(s);
        }
        
        string toreplace;
        bool found = false;
        string res;
        for (int i = 0; i < sentence.size(); ++i) {
            char c = sentence[i];
            if (c != ' ') {
                if (!found) {
                    toreplace += c;   
                    int cz = toreplace.size();
                    if (cz < 101 && hsByLen[cz].find(toreplace) != hsByLen[cz].end()) {
                        found = true;
                    }   
                }
            } else {
                res += toreplace;
                res += ' ';
                found = false;
                toreplace = "";
            }
        }
        res += toreplace;
        return res;
    }
};
