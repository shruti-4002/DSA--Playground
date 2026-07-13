class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto e : times){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({w,v});

        }
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({dis[k],k});

        while(!pq.empty()){
            int DisCurrNode=pq.top().first;
            int CurrNode=pq.top().second;
                pq.pop();

                if(dis[CurrNode]<DisCurrNode){
                    continue;
                }

            for(auto ad:adj[CurrNode]){
                int DisNeighbourNode=ad.first;
                int NeighbourNode=ad.second;

                if(DisNeighbourNode+DisCurrNode<dis[NeighbourNode]){
                    dis[NeighbourNode]=DisNeighbourNode+DisCurrNode;
                    pq.push({dis[NeighbourNode],NeighbourNode});
                }


            }

        }

        int maxi=-1;

        for(int i=1;i<dis.size();i++){
            if(dis[i]>maxi){
                maxi=dis[i];
            }
            if(dis[i]==INT_MAX){
                return -1;
            }
        }

        return maxi;

    }
};