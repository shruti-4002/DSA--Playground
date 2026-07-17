class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
           long long mod=1e9+7;
        
      
        vector<vector<pair<int, int>>> adj(n); 
        vector<long long> ways(n, 0); 
       
        for(auto& e : roads){ 
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
       
        vector<long long> dis(n, LLONG_MAX); 
        
       
        dis[0] = 0;
        ways[0] = 1; 
        pq.push({dis[0], 0});
        
        while(!pq.empty()){
            long long DisNodeA = pq.top().first;
            int NodeA = pq.top().second;
            pq.pop();
            
         
         
            if (DisNodeA > dis[NodeA]) continue;
                
            for(auto& nodes : adj[NodeA]){
                int NodeB = nodes.first;
                long long EdgeDisNodeB = nodes.second;
                
               
                if(dis[NodeB] > DisNodeA + EdgeDisNodeB){
                    dis[NodeB] = DisNodeA + EdgeDisNodeB;
                    ways[NodeB]=ways[NodeA];
                    pq.push({dis[NodeB], NodeB});
                }
              
                else if(dis[NodeB] == DisNodeA + EdgeDisNodeB){
                    ways[NodeB]=(ways[NodeA]+ways[NodeB])%mod;
                }
            }
        }
        
       
        return ways[n - 1]; 
    }
};