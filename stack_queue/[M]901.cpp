// Problem: 901. Online Stock Span - Medium
// Link: https://leetcode.com/problems/online-stock-span/

/* Nhận xét:
- Giả sử với price là p, các điểm p' nằm trước p và có p' < p => Khi xét các điểm p2, nằm sau p và p2 > p thì chắc chắc các điểm p2 này sẽ có p2 > p'
=> Ta có thể loại bỏ các điểm p' này không cần xét đến. Ta có thể sử dụng stack để phục vụ mục đích đó.
- Ngoài ra, ta cần có khoảng cách đến ngày có p1 > p2 và nằm trước p2, trước khi push p2 vào stack. Để làm được điều này, ta lưu kèm với giá là index của ngày có giá đó.
Index này sẽ tính từ 1.
- Với n thao tác next, stack của chúng ta sẽ có tối đã là n phần tử. Mỗi phần tử sau khi đã bị loại ra thì sẽ không quay lại stack nữa => Độ phức tạp với worst case 
sẽ là: [O(n) cho n thao tác push + O(n) cho n thao tác pop + O(n) cho n thao tác top] / n lần next => Amortized time complexity: O(1).
- Space complexity: O(n) cho stack.
- Ngoài ra, theo tôi ta cũng có thể dùng binary search để tìm kiếm nhanh phần tử p1 > p2 hiện tại. Tuy nhiên thao tác này cũng không làm thay đổi độ phức tạp nên tôi
không sử dụng.
*/

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int count;
    StockSpanner() : count(0) {
        st.push({INT_MAX, 0});
    }
    
    int next(int price) {
        // We dont need to check size because of the INT_MAX we pushed earlier
        while (st.top().first <= price) {
            st.pop();
        }
        count++;
        
        int res = count - st.top().second;
        st.push({price, count});
        return res;
    }
};
