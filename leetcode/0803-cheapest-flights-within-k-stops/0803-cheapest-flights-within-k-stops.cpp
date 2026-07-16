class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;

       
        while(!q.empty() && stops <= k) {
            int size = q.size();
            
            while(size--) {
                auto [u, cost] = q.front();
                q.pop();

                for(const auto& edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;

                 
                    if (cost + weight < dist[v]) {
                        dist[v] = cost + weight;
                        q.push({v, dist[v]});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};