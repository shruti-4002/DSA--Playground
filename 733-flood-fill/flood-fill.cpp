class Solution {
public:

    void bfs(int i,int j,int c , int o,vector<vector<int>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())return;
        if(grid[i][j]!=o || grid[i][j]==c)return;

        grid[i][j]=c;
        bfs(i + 1, j,c,o,grid);
        bfs( i - 1, j,c,o,grid);
        bfs( i, j + 1,c,o,grid);
        bfs( i, j - 1,c,o,grid);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
       

        int row = image.size();
        int col = image[0].size();
        
        int i=sr;
        int j=sc;
        int c=color;
        int o=image[sr][sc];
       bfs(i,j,c,o,image);

        return image;
    }
};