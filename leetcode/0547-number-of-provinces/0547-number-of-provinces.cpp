class Solution {
public:

   void uni(int c1,int c2,vector<int>&p,vector<int>&rank){
        int p1=find(c1,p);
        int p2=find(c2,p);
    if(rank[p1]>rank[p2]){
        p[p2]=p1;
    }else if(rank[p2]>rank[p1]){
        p[p1]=p2;
    }else{
        p[p1]=p2;
        rank[p2]++;
    }
    }

    int find(int child,vector<int>&p){
            if(p[child]==child){
                return child;
            }
            p[child]=find(p[child],p);
            return p[child];
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>p(isConnected.size()+1);
        vector<int>Rank(isConnected.size()+1,0);

        for(int i=0;i<isConnected.size();i++){
            p[i]=i;
        }

        for(int i=0;i<isConnected.size();i++){
            for(int j=i+1;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                     uni(i,j,p,Rank);
                }
               
            }
        }

        int count=0;

        for(int i=0;i<isConnected.size();i++){
            if(p[i]==i){
                count++;
            }
        }

            return count;

    }
};