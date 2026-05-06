class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        int count=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;

                queue<pair<int,int>>q;
               
                q.push({i,j});
                 grid[i][j]='0';

                while(!q.empty()){
                    
                    auto pair=q.front();
                    q.pop();

                for(int k=0;k<4;k++){
                    int l=pair.first+dx[k];
                    int m=pair.second+dy[k];

                    if(l<0 || m<0 || l>=grid.size() || m>=grid[0].size())continue;
                    if(grid[l][m]=='0')continue;
                    q.push({l,m});
                    grid[l][m]='0';




                }
                    




                }













                }
            }
        }

        return count;

    }
};