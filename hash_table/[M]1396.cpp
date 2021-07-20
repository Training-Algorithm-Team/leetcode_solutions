// https://leetcode.com/problems/design-underground-system/

class UndergroundSystem {
private:
    typedef pair<long, int> pli;
    typedef pair<string, int> psi;
    
    unordered_map<string, pli> hashAverage;
    unordered_map<int, psi> hashStart;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        hashStart[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = hashStart[id].first;
        int startTime = hashStart[id].second;
        
        string key = startStation + "-" + stationName;
        long duration = t - startTime;
        
        hashAverage[key].first += duration;
        hashAverage[key].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "-" + endStation;
        return (double)hashAverage[key].first / hashAverage[key].second;
    }
};
