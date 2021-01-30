// Problem: 981. Time Based Key-Value Store - Medium
// Link: https://leetcode.com/problems/time-based-key-value-store/

/* Nhận xét:
- Tương ứng với mỗi key xác định ta lại có một dòng thời gian xác định, vậy ta lưu một hash table với mỗi phần tử là 1 key khác nhau.
- Theo đầu bài, các giá trị được push vào theo thứ tự tăng dần timestamp => Ta chỉ cần dùng 1 vector để lưu các {timestamp, value}, mảng này đã có thứ tự tăng dần.
- Sau đó ta có thể dùng binary search để tìm phần tử <= timestamp trên mảng tăng dần đó.
- Time complexity: 
  + constructor: O(1)
  + set: O(1)
  + get: O(log(n));
- Space complexity: O(n)
- Bài này anh nghĩ có thể dùng hàm upper_bound để tìm thay vì mình phải tự implement binary search. Chú nghĩ anh có cần code lại theo cách đấy ko?
*/

class TimeMap {
    typedef pair<int, string> pis;
    unordered_map<string, vector<pis>> hash;
    
    int binarySearch(const vector<pis> &vt, int val) {
        int l = 0, r = vt.size();
        while (r - l > 1){
            int mid = l + (r - l) / 2;
            if (vt[mid].first > val) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
    
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (hash.find(key) == hash.end()) {
            return "";
        }
        int idx = binarySearch(hash[key], timestamp);
        return hash[key][idx].first <= timestamp? hash[key][idx].second : "";
    }
};
