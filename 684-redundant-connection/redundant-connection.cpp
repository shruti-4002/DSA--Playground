class Solution {
public:

    int find(int child,vector<int>&parent,vector<int>&rank){
        if(parent[child]==child){
            return child;
        }
        parent[child]= find(parent[child],parent,rank);
        return parent[child];
    }

    bool uni(int n1,int n2,vector<int>&parent,vector<int>&rank){
        int p1=find(n1,parent,rank);
        int p2=find(n2,parent,rank);

        if(p1==p2){
            return false;
        }

        if(rank[p1]==rank[p2]){
            parent[p1]=p2;
            rank[p2]++;

        }else if(rank[p1]<rank[p2]){
            parent[p1]=p2;
            
        }else{
            parent[p2]=p1;

        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1);
        vector<int>rank(edges.size()+1,0);
        
        for(int i=0;i<edges.size();i++){
            parent[i]=i;
        }

        vector<int>ansvec;
        for(auto &e:edges){
            int n1=e[0];
            int n2=e[1];
           bool ans= uni(n1,n2,parent,rank);
           if(ans==false){
            ansvec.push_back(n1);
            ansvec.push_back(n2);
            return ansvec;
           }
        }
        return ansvec;
    }
};