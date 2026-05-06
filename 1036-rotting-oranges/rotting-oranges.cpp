class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};

        queue<pair<int,int>>q;

        int freshcount=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)continue;
                if(grid[i][j]==1){
                    freshcount++;
                    continue;
                }
                //Add All sources to quque 
                q.push({i,j});
            }
        }

        int countoftime=0;
        while(!q.empty()){
        
           bool rotthua=false;
       int Size=q.size();

        while(Size--){

                 
        auto curr=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int l=dx[k]+curr.first;
            int m=dy[k]+curr.second;

        if(l<0 || m<0 || l>=grid.size() || m>=grid[0].size())continue;
        if(grid[l][m]==2 || grid[l][m]==0)continue;

        grid[l][m]=2;
        q.push({l,m});
        freshcount--;
        rotthua=true;

        }
            
        }

        if(rotthua){
            countoftime++;
        }

      

       


        }

    return (freshcount==0)?countoftime:-1;

    }
};