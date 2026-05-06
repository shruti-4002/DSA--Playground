class Solution {
public:

    void bfs(int i,int j,int c , int o,vector<vector<int>>& grid){

        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};
        

        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=c;

        
        while(!q.empty()){

        auto curr=q.front();
                q.pop();

        for(int k=0;k<4;k++){

            int l=dx[k]+curr.first;
            int m=dy[k]+curr.second;

         if(l < 0 || l >= grid.size() || m < 0 || m >= grid[0].size())continue;
        if(grid[l][m]!=o || grid[l][m]==c)continue;

        grid[l][m]=c;

        q.push({l,m});


        }




        }

       


    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
       

        
        int i=sr;
        int j=sc;
        int c=color;
        int o=image[sr][sc];
       bfs(i,j,c,o,image);

        return image;
    }
};