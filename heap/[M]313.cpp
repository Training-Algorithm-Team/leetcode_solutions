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
- Time complexity: O(n * log(k));
- Space complexity: O(n)
*/

class Solution {
public:
    typedef pair<int, int> pii;
    typedef pair<int, pair<int, int>> pip;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> ugly(n);
        priority_queue<pip, vector<pip>, greater<pip>> nextUgly;
        
        for (int &p : primes) {
            nextUgly.push({1, {p, 0}});
        }
        
        for (int i = 0; i < n; ++i) {
            int u = nextUgly.top().first;       
            ugly[i] = u;
            
            while (nextUgly.top().first == u) {
                auto [p, idx] = nextUgly.top().second;
                nextUgly.pop();
                nextUgly.push({ugly[idx] * p, {p, idx + 1}});
            }
        }
        return ugly[n-1];
    }
};

/* C2:
- Cách này chỉ đơn thuần là duyệt toàn bộ mảng primes, để tìm min chứ ko dùng heap. Độ phức tạp trên lý thuyết là O(n * k) tức là sẽ lớn hơn cách 1. Tuy nhiên khi chạy 
thực tế thì nhanh hơn rất nhiều: 40ms vs. 120ms. Thậm chí khi anh kiểm tra discussion thì các ngôn ngữ khác đều có hiện tượng này.
- Có vẻ như cách sử dụng heap có overhead quá lớn dẫn đến khi k tương đối nhỏ thì các hệ số overhead dành cho C*log(k) còn lớn hơn k. Chú nghĩ sao?
*/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> ugly(n);
        vector<int> idx(k, 0);
        vector<int> nextUgly(k, 1);
        
        ugly[0] = 1;
        int next = INT_MAX;
        for (int i = 1; i < n; ++i) {
            next = INT_MAX;
            for (int j = 0; j < k; ++j) {
                if (ugly[i-1] == nextUgly[j]) {
                    nextUgly[j] = ugly[idx[j]] * primes[j];
                    idx[j]++;
                }
                next = min(next, nextUgly[j]);
            }
            ugly[i] = next;
        }
        return ugly[n-1];
    }
};
