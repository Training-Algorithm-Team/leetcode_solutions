// https://leetcode.com/problems/shortest-word-distance-ii/

/* Analysis:
- Ban dau anh dinh dung hash table de luu khoang cach giua cac cap word, nhung ma cach nay can O(n^2) preprocess, khong dat yeu cau.
- Luc sau doc goi y thi thay bon no dung cach O(n) cho ham shortest vi so lan goi ham nay la nho.
- Ban dau anh code thu C1, cho duyet trau toan bo mang nhung bi TLE.
- Sau do anh phai chuyen ve chi luu toa do tuong ung cua tung string thoi.

*/

// C1:
class WordDistance {
private:
    vector<string> _wordsDict;
public:
    WordDistance(vector<string>& wordsDict) {
        _wordsDict = wordsDict;
    }
    
    int shortest(string word1, string word2) {
        int n = _wordsDict.size();
        int latestPos1 = -100000, latestPos2 = -100000;
        int dist = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (_wordsDict[i] == word1) {
                dist = min(dist, i - latestPos2);
                latestPos1 = i;
            } else if (_wordsDict[i] == word2) {
                dist = min(dist, i - latestPos1);
                latestPos2 = i;
            }
        }
        return dist;
    }
};


// C2:
class WordDistance {
private:
    unordered_map<string, vector<int>> hashWords;
public:
    WordDistance(vector<string>& wordsDict) {
        int n = wordsDict.size();
        for (int i = 0; i < n; i++) {
            hashWords[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int m = hashWords[word1].size(), n = hashWords[word2].size();
        int i = 0, j = 0;
        int dist = INT_MAX;
        while (i < m && j < n) {
            if (hashWords[word1][i] < hashWords[word2][j]) {
                dist = min(dist, hashWords[word2][j] - hashWords[word1][i]);
                i++;
            } else {
                dist = min(dist, hashWords[word1][i] - hashWords[word2][j]);
                j++;
            }
        }
        return dist;
    }
};
