// Problem: 1170. Compare Strings by Frequency of the Smallest Character - Medium
// Link: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

/* Nhận xét:
- Trước tiên ta phải thực hiện việc tính tần số xuất hiện của kí tự nhỏ nhất trong mỗi dãy, độ phức tạp trong trường hợp này là 
đồ dài xâu = queries[i].length, words[i].length <= 10 => O(10) = O(1)
- Với m queries và n words, độ phức tạp là O(m + n) hay O(max(m, n)).
- Tiếp theo, với mỗi query, ta cần look up số lượng chuỗi trong words có freq > f(query). Độ phức tạp trong trường hợp này là O(n). Với m query, độ phức tạp là O(m * n).
- Nhận thấy, nếu ta sort dãy words, sau đó thực hiện việc tìm kiến PHẦN TỬ ĐẦU TIÊN có freq > f(query), như vậy ta vẫn đáp ứng được yêu cầu của đề bài. Ta có thể 
thực hiện việc này với binary search với độ phức tạp O(log(n)).
- Như vậy tổng kết lại, ta có time complexity là: O(m + n + nlog(n) + mlog(n)) = O(max(nlog(n), mlog(n)).
- Space complexity: O(m + n) cho mảng 2 frequency.
*/

class Solution {
public:
    int countSmallestFreq(const string &s) {
        int count = 1;
        char smallest = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == smallest) {
                count++;
            } else if (s[i] < smallest) {
                count = 1;
                smallest = s[i];
            }
        }
        return count;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int m = queries.size(), n = words.size();
        vector<int> freqq, freqw;
        for (string s : queries) {
            freqq.push_back(countSmallestFreq(s));
        }
        for (string s : words) {
            freqw.push_back(countSmallestFreq(s));
        }
        sort(freqw.begin(), freqw.end());
        
        vector<int> res;
        for (int f : freqq) {
            int l = 0, r = n;
            while (r - l > 0) {
                int mid = l + (r - l) / 2;
                if (freqw[mid] <= f) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            res.push_back(n - l);
        }
        return res;
    }
};
