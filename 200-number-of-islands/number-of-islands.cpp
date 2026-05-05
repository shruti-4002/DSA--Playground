class Solution {
public:

    void bfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())return;
        if(grid[i][j]=='0')return;

        grid[i][j]='0';
        bfs(grid,i+1,j);
          bfs(grid,i-1,j);
            bfs(grid,i,j+1);
              bfs(grid,i,j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='0'){
                    continue;
                }else{
                    count++;
                    bfs(grid,i,j);
                }
            }
        }

        return count;
    }
};