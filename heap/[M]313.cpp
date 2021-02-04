// Problem: 313. Super Ugly Number - Medium
// Link: https://leetcode.com/problems/super-ugly-number/

/* Nhận xét: Anh đã phải đọc cách giải của bài Ugly Number trên geeksforgeeks rồi nên cũng không có gì sáng tạo lắm cả, để không thì cũng không làm được.
* Hướng suy nghĩ ban đầu:
- Giả sử tập primes ban đầu là [a, b, c], khi đó rõ ràng đây là các ugly number. Sau đó, ta nhân toàn bộ tập primes với tập ugly hiện có, ta được tập mới 
[a2, ab, ac, b2, bc, c2], tập này cũng là các ugly number. Ta cứ tiếp tục nhân primes * ugly như vậy, ta sẽ có các tập ugly tiếp theo.
- Tuy nhiên vấn đề gặp phải là: có thể a2 < c, khi đó để giữ được thứ tự chuẩn ta cần phải liệt kê a2 trước c. Và cách này trở nên không khả thi. Ngoài ra nó cũng 
liệt kê quá nhiều tích không cần thiết.
* Cách giải quyết đúng theo geeksforgeeks
- Ugly number chỉ bao gồm tích của các primes, như vậy, ta có thể tổng quát hóa thành k dãy gọi là nextUgly, dãy i là tích của primes[i] với các ugly number đã có. Tuy nhiên,
việc liệt kê tất cả các số với 1 dãy nextUgly[i] là không cần thiết, ta chỉ quan tâm đến số nhỏ nhất hiện tại trong dãy nextUgly đó. 
- Việc này có thể thực hiện bằng cách, lưu các ugly numbers trong dãy ugly theo thứ tự tăng dần. Dùng 1 biến chạy idx tương ứng với một primes[i] = p, cho idx chạy từ 0 -> n.
=> idx luôn duyệt qua các ugly number theo thứ tự từ nhỏ đến lớn, và các nextUgly theo p cũng được duyệt theo thứ tự từ nhỏ đến lớn. 
- Ta lưu toàn bộ các nextUgly tương ứng với toàn bộ primes. Việc ở mỗi vòng lặp là tìm 1 uglyNumber tiếp theo, ta thực hiện bằng cách chọn nextUgly nhỏ nhất. Việc này gợi ý
ta có thể dùng heap để giảm thời gian tính toán. Ngoài ra, khi đã thêm mới ugly number, ta cần tìm nextUgly tiếp theo tương ứng với p, việc này thực hiện bằng cách
ta tăng idx lên 1, sau đó nhân với p, để tìm ugly number tiếp theo trong dãy nextUgly của p.
*/

class Solution {
public:
    typedef pair<int, int> pii;
    typedef pair<int, pair<int, int>> pip;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> ugly(n);
        priority_queue<pip, vector<pip>, greater<pip>> nextUgly;
        
        ugly[0] = 1;
        for (int i = 0; i < k; ++i) {
            nextUgly.push({primes[i], {primes[i], 0}});
        }
        
        for (int i = 1; i < n; ++i) {
            int u = nextUgly.top().first;       
            ugly[i] = u;
            
            while (nextUgly.top().first == u) {
                auto [p, idx] = nextUgly.top().second;
                nextUgly.pop();
                idx++;
                nextUgly.push({ugly[idx] * p, {p, idx}});
            }
        }
        return ugly[n-1];
    }
};
