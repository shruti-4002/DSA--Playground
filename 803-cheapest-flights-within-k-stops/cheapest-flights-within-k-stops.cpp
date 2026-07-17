class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& f : flights) {
            int u=f[0];
            int v=f[1];
            int w=f[2];
            adj[u].push_back({v,w});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        

      queue<pair<int, pair<int, int>>>q;
        q.push({src,{0,-1}});


      

       
        while(!q.empty()) {
        
          
                auto curr = q.front();
                int mainNode=curr.first;
                int mainNodeDis=curr.second.first;
                int mainNodeStops=curr.second.second;
                q.pop();

                for(const auto& edge : adj[mainNode]) {
                    int NodeB = edge.first;
                    int DisAB = edge.second;

                if(DisAB+mainNodeDis<dist[NodeB] && mainNodeStops+1<=k){
                    dist[NodeB]=DisAB+mainNodeDis;
                    q.push({NodeB,{dist[NodeB],mainNodeStops+1}});
                } 
                
                }
            }
           
        

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};