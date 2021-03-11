// 816. Ambiguous Coordinates - Medium
// https://leetcode.com/problems/ambiguous-coordinates/

/* Analysis:
- We want to divide into smaller tasks. We need to build 2 coordinates with same rules so we create a function to build all valid coordinate from a string.
- We notice that:
  + If string has 1 character => return it only
  + If string starts with '0' => It must be "0.(the rest)" only
  + If string ends with '0' => It does not have decimal point.
  + Otherwise, we can insert the decimal point at every position after the first character. We return all of them in a vector.
- After we have 2 vectors for 2 coordinates, we make every possible pairs and return them.
- Time complexity: O(n^3). We have n ways to separate into 2 coordinate strings. Each string has n possible coordinate. We make every possible pair 
them => n^2 * n = n^3
- Space complexity: O(1)
*/

class Solution {
public:
    vector<string> createCoordinate(const string &s, int start, int end) {
        if (start == end) {
            return {s.substr(start, 1)};
        }
        if (s[start] == '0' && s[end] == '0') {
            return {};
        }
        if (s[start] == '0') {
            return {s.substr(start, 1) + '.' + s.substr(start + 1, end - start)};
        }
        if (s[end] == '0') {
            return {s.substr(start, end - start + 1)};
        }
        vector<string> res;
        for (int i = start + 1; i <= end; ++i) {
            res.push_back(s.substr(start, i - start) + '.' + s.substr(i, end - i + 1));
        }
        res.push_back(s.substr(start, end - start + 1));
        return res;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> res;
        for (int i = 1; i <= n - 3; ++i) {
            auto set1 = createCoordinate(s, 1, i);
            auto set2 = createCoordinate(s, i + 1, n - 2);
            for (string &s1 : set1) {
                for (string &s2 : set2) {
                    res.push_back('(' + s1 + ", " + s2 + ')');       
                }
            }
        }
        return res;
    }
};
