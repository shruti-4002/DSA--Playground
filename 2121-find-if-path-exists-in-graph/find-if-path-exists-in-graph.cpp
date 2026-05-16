class Solution {
public:

        bool dfs(int s,int d,unordered_map<int,vector<int>>&mp,vector<bool>&visited){

        for(auto x :mp[s]){
            if(visited[x]==true)continue;
            if(x==d)return true;
           visited[x]=true ;
           if( dfs(x,d,mp,visited)){
            return true;
           };
        }
            return false;

        }



    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        if(source==destination)return true;
        if(edges.size()==0)return true;
        vector<bool>visited(n,false);
        for(auto p:edges){
            int parent=p[0];
            int child=p[1];
            mp[parent].push_back(child);
            mp[child].push_back(parent);
        }



        
        visited[source]=true;

       if (dfs(source,destination,mp,visited))return true;


        return false;
       

    }
};