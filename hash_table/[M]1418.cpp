// Problem: 1418. Display Table of Food Orders in a Restaurant - Medium
// Link: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

/* Nhận xét:
- Với bài toán này, ta cần một tập dữ liệu lưu toàn bộ các bàn, và tên các món của mỗi bàn.
- Ban đầu, tôi nghĩ đến phương pháp lưu hash table của các bàn dưới dạng vector, hash table này đã đi kèm luôn cả thứ tự, tuy nhiên lựa chọn kiểu dữ liệu gì 
cho mỗi bàn là hơi khó. nếu với mỗi bàn ta lưu một vector các món ăn, như vậy thì khi có thêm một món ăn mới ta phải duyệt toàn bộ vector để tăng thêm 
số lượng, việc này tăng độ phức tạp. Như vậy, ta có thể dùng một unordered_map với key là tên món và value là số lượng được order từ bàn đó. 
- Ta cần thêm một map tổng, chứa danh sách toàn bộ các món ăn cung cấp. Ta phải sử dụng map để có thể duyệt theo thứ tự alphabet của các món ăn.

- Tuy nhiên, sau đó, tôi quyết định sử dụng hướng khác, đó là lưu một map của các món ăn, mối món ăn lưu một vector để lưu số lượng đặt món ăn đó của mỗi bàn.
- Cách này tôi nghĩ là tốt hơn, nhưng sau khi implement thì thấy hơi phức tạp vì ngược với hướng suy nghĩ thông thường. 
- Ngoài ra vẫn phải lưu thêm 1 set các bàn có khách. Vì vậy độ phức tạp không gian cũng không khác gì phương pháp trước cho lắm.
- Time complexity: Hơi phức tạp. Có vẻ là: O(nlog(n)*mlog(m)). Lí do là với trường hợp 2 vòng for qua map và set, độ phức tạp thao tác ++ trên binary tree là O(logn).
- Space complexity: O(m * n). Mảng res cần lưu tối đa là: số lượng bàn * số lượng món.
*/
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string, vector<int>> m;
        set<int> visitedTable;
        for (vector<string> &o : orders) {
            string dish = o[2];
            int table = stoi(o[1]);
            if (m.find(dish) == m.end()) {
                m[dish].resize(501, 0);
            }
            m[dish][table]++;
            visitedTable.insert(table);
        }
        vector<vector<string>> res;
        vector<string> header(1, "Table");
        for (auto mit = m.begin(); mit != m.end(); ++mit) {
            header.push_back(mit->first);
        }
        res.push_back(header);
        
        for (auto tit = visitedTable.begin(); tit != visitedTable.end(); ++tit) {
            vector<string> temp;
            temp.push_back(to_string(*tit));
            for (auto mit = m.begin(); mit != m.end(); ++mit) {
                temp.push_back(to_string(mit->second[*tit]));
            }
            res.push_back(temp);
        }
        return res;
    }
};
