class Solution {
public:

    bool uni(int child1,int child2,vector<int>&p,vector<int>&rank){
        

        int c1=find(child1,p);
        int c2=find(child2,p);

        if(c1==c2)return false;

        if(rank[c1]<rank[c2]){
            p[c1]=c2;
            return true;
        }else if(rank[c1]>rank[c2]){
            p[c2]=c1;
            return true;
        }else{
            p[c1]=c2;
            rank[c2]++;
            return true;
        }
    }

    int find(int child,vector<int>&p){
        if(p[child]==child)return child;

         p[child]=find(p[child],p);
        return p[child];
    }

      bool ans;
     

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>p(n+1);

        vector<int>rank(n+1,0);

        for(int i=0;i<=n;i++){
            p[i]=i;
        }

        for(auto x:edges){
         ans = uni(x[0],x[1],p,rank);
         if(ans==false){
           return {x[0],x[1]};
         }
           
        }

        return {};

      
    }
};