class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n=grid[0].size();
      int m=grid.size();
      queue<pair<int,int>>q;
      vector<vector<bool>>v(m,vector<bool>(n,false));

        if(grid[0][0]==1 || grid[m-1][n-1]==1){
            return -1;
        }

        if(m==1 && n==1){
            return 1;
        }

        q.push({0,0});
        v[0][0]=true;
        int dx[8]={0,0,1,-1,-1,1,1,-1};
        int dy[8]={1,-1,0,0,-1,1,-1,1};

       int count=1;
        while(!q.empty()){
            int Size=q.size();
            while(Size--){

            auto curr=q.front();
                q.pop();
             

            for(int i=0;i<8;i++){
                int newi=curr.first+dx[i];
                int newj=curr.second+dy[i];
            if(newi<0 || newj<0 || newi>=m || newj>=n || grid[newi][newj]==1 ||v[newi][newj]==true){
                continue;
            }

            if(newi ==m-1 && newj ==n-1){
                v[newi][newj]=true;
                return count+1;

            }

            q.push({newi,newj});
           
            v[newi][newj]=true;

            }

            }
            count++;

        }

        if(v[m-1][n-1]){
            return count;
        }

        return -1;

    }
};