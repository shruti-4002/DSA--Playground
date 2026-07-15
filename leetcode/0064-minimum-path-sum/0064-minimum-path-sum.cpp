class Solution {
public:

    int fun(int i,int j,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=m || j>=n){
            return 1e9 ;
        }
        if(i==m-1 && j==n-1){
            return grid[i][j];
        } 

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=fun(i,j+1,m,n,grid,dp);
        int left=fun(i+1,j,m,n,grid,dp);
        return dp[i][j]=grid[i][j]+min(left,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
       
        int m=grid.size();
        int n=grid[0].size();
 vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=fun(0,0,m,n,grid,dp);
        return ans;
    }
};