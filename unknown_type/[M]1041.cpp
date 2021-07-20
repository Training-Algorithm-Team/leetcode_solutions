class Solution {
public:
    typedef pair<int, int> pii;
    const vector<pii> dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    bool isRobotBounded(string instructions) {
        int d = 0;
        pii pos = {0, 0};
        for (char &c : instructions) {
            switch (c) {
                case 'G':
                    pos.first += dirs[d].first;
                    pos.second += dirs[d].second;
                    break;
                case 'L':
                    d = (d + 1) % dirs.size();
                    break;
                case 'R':
                    d = (d + 3) % dirs.size();
                    break;
                default:
                    //Nothing
                    return false;
            }
        }
        
        return !(d == 0 && (pos.first != 0 || pos.second != 0));
    }
};
