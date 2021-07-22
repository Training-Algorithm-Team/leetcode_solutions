// https://leetcode.com/problems/reconstruct-itinerary/

/* Bai nay ban dau anh khong biet giai the nao danh phai dung DFS de tim toan bo cac duong di co the.
- Sau doc giai moi nho ra la bai nay la bai tim duong di Euler, hinh nhu co phuong phap cu the dung de quy.
- Khong biet bai nay co the ra trong phong van ko nhi.

*/

class Solution {
public:
    typedef map<string, int> Edges;
    bool dfs(unordered_map<string, Edges> adj, string pos, vector<string> &itinerary, int total) {
        itinerary.push_back(pos);
        if (itinerary.size() == total) {
            return true;
        }
        
        Edges &edges = adj[pos];
        for (auto it = edges.begin(); it != edges.end(); it++) {
            if (it->second > 0) {
                it->second--;
                 if (dfs(adj, it->first, itinerary, total)) {
                     return true;
                 }
                it->second++;
            }
        }
        itinerary.pop_back();
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, Edges> adj;
        
        int total = 0;
        for (auto ticket : tickets) {
            adj[ticket[0]][ticket[1]]++;
            total++;
        }
        
        vector<string> itinerary;
        dfs(adj, "JFK", itinerary, total+1);
        
        return itinerary;
    }
};
