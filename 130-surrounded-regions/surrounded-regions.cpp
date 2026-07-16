class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&g){
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size()|| g[i][j]=='X' || g[i][j]=='#'){
            return ;
        }

       g[i][j]='#';

        dfs(i+1,j,g);
         dfs(i,j+1,g);
          dfs(i-1,j,g);
           dfs(i,j-1,g);
    }

    void solve(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        //send upper and lower level
        for(int j=0;j<n;j++){
            if(grid[0][j]=='O'){
                dfs(0,j,grid);
            }
            if(grid[m-1][j]=='O'){
                dfs(m-1,j,grid);
            }

        }

          //send left and right
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O'){
                dfs(i,0,grid);
            }
            if(grid[i][n-1]=='O'){
                dfs(i,n-1,grid);
            }

        }

        //convert rest o to X

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }

  for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='#'){
                    grid[i][j]='O';
                }
            }
        }
     
       
     

    }
};