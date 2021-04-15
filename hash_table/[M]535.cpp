// https://leetcode.com/problems/encode-and-decode-tinyurl/
// 535. Encode and Decode TinyURL - Medium

/* Analysis:
- We maintain a hashtable to map a string key with the requested url.
- We generate the larger key 1 by 1 each turn. After that, we save the url into hash table with that larger key.
- Time complexity:
  + encode: O(log24(n)). n = number of requested url
  + decode: O(1).
- Space complexity: O(n)
*/

class Solution {
private:
    unordered_map<string, string> hash;
    string curKey;
    
    void nextString() {
        int n = curKey.size();
        int i = n - 1;
        while (i >= 0 && curKey[i] == 'z') {
            --i;
        }
        
        if (i >= 0) {
            curKey[i]++;
            while (++i < n) {
                curKey[i] = 'a';
            }
        } else {
            curKey.push_back('a');
            fill(curKey.begin(), curKey.end(), 'a');
        }
    }
public:
    Solution() : curKey("a"){
        
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        nextString();
        hash[curKey] = longUrl;
        return curKey;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return hash[shortUrl];
    }
};
