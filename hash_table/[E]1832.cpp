// 1832. Check if the Sentence Is Pangram - Easy
// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> hash(sentence.begin(), sentence.end());
        return hash.size() == 26;
    }
};
