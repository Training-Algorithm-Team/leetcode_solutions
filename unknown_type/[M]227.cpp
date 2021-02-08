// Problem: 227. Basic Calculator II - Medium
// Link: https://leetcode.com/problems/basic-calculator-ii/

/* Nhận xét: 
- Nếu dựng biểu thức thành 1 cây, các số hạng của tổng và hiệu nằm ở lv1, và các thừa số của tích hoặc thương sẽ nằm ở lv 2
- Ví dụ với biểu thức: 1 + 2 - 3 * 4 + 6 / 5 * 7 - 8 sẽ được biểu diễn thành:
                      Giá trị cuối cùng
    1     2       (12 = 3 * 4)        (7 = 6 / 5 * 7)     8
                  3         4         6     5      7    
- Như vậy, giá trị cuối cùng sẽ là tổng và hiệu của các số hàng một, ta gọi là curSum. Nếu gặp các phép nhân thì ta đưa vào biến curProduct, sau đó đến khi gặp
phép +, - hoặc hết chuỗi thì ta cộng curProduct vào curSum

*/

class Solution {
public:
    int calculate(string s) {
        int curSum = 0;
        int curProduct = 1;
        char prevSign = '+';
        
        string cur;
        int curNum;
        for (char c : s) {
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                curNum = stoi(cur);
                if (c == '*' || c == '/') {
                    if (prevSign == '+') {
                        curProduct = curNum;  
                    } else if (prevSign == '-') {
                        curProduct = -curNum;
                    } else if (prevSign == '*') {
                        curProduct *= curNum;
                    } else {
                        curProduct = curProduct / curNum;
                    }
                } else {
                    if (prevSign == '*') {
                        curSum += (curProduct * curNum);
                    } else if (prevSign == '/') {
                        curSum += (curProduct / curNum);
                    } else if (prevSign == '+') {
                        curSum += curNum;
                    } else {
                        curSum -= curNum;
                    }
                    curProduct = 1;
                }
                prevSign = c;
                cur = "";
            } else if (isdigit(c)) {
                cur += c;
            }
        }
        
        curNum = stoi(cur);
        if (prevSign == '*') {
            curSum += (curProduct * curNum);
        } else if (prevSign == '/') {
            curSum += (curProduct / curNum);
        } else if (prevSign == '+') {
            curSum += curNum;
        } else {
            curSum -= curNum;
        }
        
        return curSum;
    }
};
