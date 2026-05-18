class Solution {
public:


    int find(int child,vector<int>&p){
        if(p[child]==child){
            return child;
        }

      p[child]=find(p[child],p);
            return p[child];
    }


    void uni(int child1,int child2,vector<int>&rank,vector<int>&p){

        int parent1=find(child1,p);
        int parent2=find(child2,p);

        if(parent1==parent2)return;

        if(rank[parent1]<rank[parent2]){
            p[parent1]=parent2;
        }

        if(rank[parent1]>rank[parent2]){
            p[parent2]=parent1;
        }

        if(rank[parent1]==rank[parent2]){

            p[parent1]=parent2;
            rank[parent2]++;

        }   


    }



    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
     
        
        vector<int>p(n);
        vector<int>rank(n,0);

       for(int i=0;i<n;i++){
        p[i]=i;
       }

        for(auto x : edges){
            uni(x[0],x[1],rank,p);
        }

        if(find(source,p)==find(destination,p)){
            return true;
        }

        return false;
    }
};