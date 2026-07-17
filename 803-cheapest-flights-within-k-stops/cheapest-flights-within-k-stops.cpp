class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<vector<pair<int,int>>>adj(n);
        queue<pair<int,pair<int,int>>>pq;
        
        for(auto e:flights){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            adj[u].push_back({v,w});
              
        }
        
        
        vector<int>dis(n,INT_MAX);
        
        dis[src]=0;
        pq.push({-1,{dis[src],src}});
        
        while(!pq.empty()){
            
                int DisNodeA=pq.front().second.first;
                int NodeA=pq.front().second.second;
                int numsteps=pq.front().first;
                
                pq.pop();
                
              
                
                for(auto & nodes : adj[NodeA]){
                    int NodeB=nodes.first;
                    int EdgeDisNodeB=nodes.second;
                    if(dis[NodeB]>DisNodeA+EdgeDisNodeB && numsteps+1<=k){
                        dis[NodeB]=DisNodeA+EdgeDisNodeB;
                        pq.push({numsteps+1,{dis[NodeB],NodeB}});
                    }
                }
            
        }
        
        if (dis[dst]==INT_MAX){
            return -1;
        };
        return dis[dst];
    }
};