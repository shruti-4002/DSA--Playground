class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,false));
        vector<vector<int>>ans(rows,vector<int>(cols,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==1)continue;
                ans[i][j]=0;
                visited[i][j]=true;
                q.push({i,j});
            }
        }        
            int level=1;

            while(!q.empty()){

                int Size=q.size();

                while(Size--){
                    auto curr=q.front();
                    q.pop();

                for(int k=0;k<4;k++){
                    int l=curr.first+dx[k];
                    int m=curr.second+dy[k];

                if(l<0 || m<0 || l>=mat.size() || m >=mat[0].size())continue;
                if(visited[l][m]==true)continue;

                ans[l][m]=level;
                visited[l][m]=true;

                q.push({l,m});

                }



                }         level++;



            }


            return ans;



    }
};