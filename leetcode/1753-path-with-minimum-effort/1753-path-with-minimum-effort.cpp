class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& ori) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        //we are carrying effort of path 
       // ->->->-> priority quque guarentees mimum path as we at every step 
       //greddily we are taking smallest effort 
       //so we dont worry about path we just worry max of path 

       //let say 1stcell->4thcell->5thcell> and max diff of path =3
       //anaother path it wont be even explored 1stcell->4thcell->2ncell->8thcell max diff btw cell=5
        int rows=ori.size();
        int cols=ori[0].size();
        vector<vector<int>>mat(rows,vector<int>(cols,INT_MAX));
        mat[0][0]=0;

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};




        while(!pq.empty()){
            auto cell=pq.top();
            int currRow=cell.second.first;
            int currCol=cell.second.second;
            int carryEffort=cell.first;
            pq.pop();

           //when a node is popped from quque means it had max effort possible 
           //and was psuhed in quque now out of all paths in queu this path was choosen 
           //since it has minimum efforts among pathA pathB Pathc nodes 
           //but interally we are pushing every node with max diff or Carryeffort
           //possible pq ensures currPath instead of pathA,B,c 
           //While Internal for Curr Path Efforts we are MAXIZING FOR currcell by pushing max as possible 
            if(currRow==rows-1 && currCol==cols-1){
                return carryEffort;
            }
        //through currentcell we follow the path 

        for(int i=0;i<4;i++){
            int newRow=currRow+dx[i];
            int newCol=currCol+dy[i];

            if(newRow<0 || newCol<0 || newRow>=rows || newCol >=cols){
                continue;
            }

            

            int currCellEffort=abs(ori[currRow][currCol]-ori[newRow][newCol]);

            int newPathEffort=max(currCellEffort,carryEffort);

                if(newPathEffort<mat[newRow][newCol]){

                mat[newRow][newCol]=newPathEffort;
                pq.push({newPathEffort,{newRow,newCol}});

            


                }


        }


        }


        return mat[rows-1][cols-1];


    }
//     Internally for Single Path: Jaisa aapne likha — hum har step par max(carryEffort, stepEffort) karke path ki sabse badi 
//     jump (Maximum effort) carry karte hain.

// Externally Among Multiple Paths: Min-Heap Priority 
// Queue har moment par saare candidate paths mein se Minimum effort wale path ko pick (pop) karti hai.




};