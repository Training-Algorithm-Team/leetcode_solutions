// 787. Cheapest Flights Within K Stops - Medium
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

/* Analysis:
- We can use Ford-Bellman algorithm to find shortest path from src to dest. Because we have another constrain that the path must have at most k stops,
we create a dp table to store the minimum path to reach from src->u with exactly i stops.
- Because the path has up to k stops, we just need to use bfs with at most k-hops from src.
- After all, we search all the distances to dst, to find the smallest one. If all of them not set, we return -1.
- Time complexity: O(n * E * k). O(n * E) for the Bellman-Ford and k for k columns of the dp table.
- Space complexity: O(n * k).
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 2000000000;
        vector<vector<pair<int, int>>> adjList(n);
        for (auto f : flights) {
            adjList[f[0]].push_back({f[1], f[2]});
        }
        
        vector<vector<int>> d(n, vector<int>(k + 2, INF));
        fill(d[src].begin(), d[src].end(), 0);
        queue<int> q;
        q.push(src);
        int hop = 0;
        
        while (!q.empty() && hop <= k + 1) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int u = q.front();
                q.pop();

                for (auto &[v, w] : adjList[u]) {
                    for (int i = 0; i < k + 1; ++i) {
                        if (d[u][i] + w < d[v][i+1]) {
                            d[v][i+1] = d[u][i] + w;
                            q.push(v);
                        }
                    }
                }
            }
            hop++;    
        }
        int res = *min_element(d[dst].begin(), d[dst].end());
        if (res == INF) {
            res = -1;
        }
        return res;
    }
};
