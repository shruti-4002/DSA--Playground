class Solution {
public:

    void uni(int c1,int c2,vector<int>&parent){
        int p1=find(c1,parent);
        int p2=find(c2,parent);
        if(p1!=p2){
            parent[p1]=p2;
        }
    }

    int find(int c,vector<int>&parent){
        if(parent[c]==c){
            return c;
        }

         parent[c]=find(parent[c],parent);
        return parent[c];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto x:edges){
            int c1=x[0];
            int c2=x[1];
            uni(c1,c2,parent);

        }

        if(find(source,parent)==find(destination,parent)){
            return true;
        }else{
            return false;
        }

    }
};