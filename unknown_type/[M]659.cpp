// Problem: 659. Split Array into Consecutive Subsequences - Medium
// Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/

/* Nhận xét:
- Xét 1 điểm x bất kì, ta gọi số đoạn có độ dài 1, 2 và (>=) 3 kết thúc tại điểm ngay trước x lần lượt là l1, l2, l3, gọi giá trị phía trước x là prev. 
Khi đó nếu x == prev - 1, thì nếu số lượng số x < l1 + l2 thì ta sẽ không thể tạo được đủ các đoạn có độ dài >= 3, do đó ta trả về false luôn.
- Nếu số x >= l1 + l2, thì ta thêm x vào các đoạn này và độ dài các đoạn này sẽ tăng lên, ta ưu tiên gắn vào l1, l2 trước, sau đó gắn thêm l3 nếu còn dư. Ngoài ra,
nếu vẫn còn dư thì ta sẽ có (count - l3 - l2 - l1) đoạn kết thúc tại x và có độ dài là 1, do x phải đứng 1 mình.
- Kết thúc, nếu vẫn còn các đoạn l1, l2 thì ta trả về false.
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int l1 = 0, l2 = 0, l3 = 0;
        int count = 0;
        int prev = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] - 1 > prev) {
                if (l1 > 0 || count > l2 + l3) {
                    return false;   
                }
                count = 1;
                prev = nums[i];
                continue;
            }
            if (nums[i] - 1 == prev) {
                if (count < l1 + l2) {
                    return false;
                }
                int rest = count - l1 - l2 - l3;
                if (rest >= 0) {
                    l3 += l2;
                    l2 = l1;
                    l1 = rest;
                } else {
                    l3 += rest + l2;
                    l2 = l1;
                    l1 = 0;
                }
                count = 1;
                prev = nums[i];
            } else {
                count++;
            }
        }
        return (l1 == 0 && count >= l2 && count <= l2 + l3);
    }
};
