// Problem: 1010. Pairs of Songs With Total Durations Divisible by 60 - Medium
// Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

/* Nhận xét:
- Với một bài hát nhất định, ta cần tìm tất cả các bài hát đã duyệt qua mà khi cộng vào thì có tổng % 60 == 0. Vì thời lượng của từng bài là có hạn (< 500), 
nên số lượng các thời lượng cần tìm là hữu hạn. Ví dụ, thời lượng 30 thì các độ dài cần tìm là 30, 90, 150, 210, 270, 330, 390, 450.
- Tuy nhiên, đến đây ta có thể nhận ra là để 2 số cộng với nhau % 60 == 0 <=> phần dư khi % 60 của 2 số đó cộng với nhau % 60 cũng == 0.
- Vậy, đối với một số, ta chỉ cần quan tâm đến phần dư khi % 60 của nó, ta lưu phần dư này vào một hash table để đếm số lần xuất hiện. Vì phần dư này đơn giản, ta có thể 
lưu vào một vector<int> để hạn chế overhead.
- Với mỗi một số mới, ta cộng vào kết quả số lượng phần tử có phần dư là (60 - r) vào thẳng kết quả luôn.
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainderFreq(60, 0);   
        
        int res = 0;
        for (int t : time) {
            int r = t % 60;
            res += remainderFreq[(60 - r) % 60];
            remainderFreq[r]++;
        }
        return res;
    }
};
