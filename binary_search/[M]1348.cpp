// https://leetcode.com/problems/tweet-counts-per-frequency/submissions/

/* Analysis:
- Ta co the luu cac tweet theo thu tu tang dan cua thoi gian de giam thoi gian tim kiem.
- Ta luu vao mot set de giam thoi gian insert, khong can sort lai moi khi them phan tu moi
- Vi cac tweet co the trung thoi gian, ta luu vao mot multiset.
- Sau do, ta dung lower_bound de tim cac start va end cua interval, tinh khoang cach giua chung chinh la so luong tweet can tim.
*/

class TweetCounts {
private:
    unordered_map<string, multiset<int>> hashTweets;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        hashTweets[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        multiset<int> &s = hashTweets[tweetName];
        int step;
        if (freq == "minute") {
            step = 60;
        } else if (freq == "hour") {
            step = 3600;
        } else {
            step = 86400;
        }
        
        vector<int> res;
        multiset<int>::iterator itStart, itEnd;
        itStart = s.lower_bound(startTime);
        for (int time = startTime + step; time <= endTime; time += step) {
            itEnd = s.lower_bound(time);
            res.push_back(distance(itStart, itEnd));
            itStart = itEnd;
        }
        itEnd = s.upper_bound(endTime);
        res.push_back(distance(itStart, itEnd));
        return res;
    }
};
