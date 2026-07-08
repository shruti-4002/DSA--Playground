class Solution {
public:

    

    int numIslands(vector<vector<char>>& grid) {
      
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
        int count=0;
       int dx[4]={-1,1,0,0};
       int dy[4]={0,0,-1,1};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!='0'){
                    q.push({i,j});
                    count++;
                    grid[i][j]='0';

                    while(!q.empty()){
                        auto curr=q.front();
                        q.pop();
                        int currrow=curr.first;
                        int currcol=curr.second;
                    for(int j=0;j<4;j++){
                        int newrow=currrow+dx[j];
                        int newcol=currcol+dy[j];

                        if(newrow<0 || newcol <0 || newrow>=row || newcol>=col || grid[newrow][newcol]=='0'){
                            continue;
                        }

                        q.push({newrow,newcol});
                        grid[newrow][newcol]='0';


                    }

                    }
                }

               
            }

        }

             return count;
        }

       
        


    
};