//NO OF ISLAND 

class Solution {
public:


void explorefullisland(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return;
        if(visited[i][j])return;
        if(grid[i][j]=='0')return ;

        visited[i][j]=true;
        explorefullisland(grid,i-1,j,visited);
        explorefullisland(grid,i+1,j,visited);
        explorefullisland(grid,i,j+1,visited);
        explorefullisland(grid,i,j-1,visited);
    }


    int numIslands(vector<vector<char>>& grid) {
     int rows = grid.size();
     int cols = grid[0].size();  
vector<vector<bool>> visited(rows, vector<bool>(cols, false));
int island=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    if(!visited[i][j]){
                        island++;
                    explorefullisland(grid,i,j,visited);
                    }
                }
            }
        }
            return island;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////

// 1 MEANS LAND AND 0 MEANS WATER 
// MATRIX MEIN ISLAND IS GRP OF 1 OR EITHER SIRF 1 
// EXP1=
// AGAR 111 YAHA 6 NAHI BAKI GRP OF 1=1 ISLAND BECASUE NO WATER SEPARTING THEM
//      111

//     AGAR 1010  YAHA 1 ISLAND HAI SEPARTED BY 2 ZEROS 
// AB EXP1 MEIN HO SKATA HAI MAI IS GRP OF ISLAND MEIN 1 UPAR WLA VIST KI ISLAND +++
// FIR NEECHE WALA VIST KI ISLAND ++ BAR YE ALAG ALAG ISLAND NAHI EK HI HAI 
// THATS WHY VISITED 


// okokok i got i was thinking ki island wahi hai jiska left right down up exits 
// nahi 1 means island hai ab vo akela ho sat ahai ya kisi big island ka chota part
//  ho sakta hai and all 1 grp togther =1 island and even 1 alone is asland


// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//      int rows = grid.size();
//      int cols = grid[0].size();  

//         for(int i=0;i<rows;i++){
//             for(int j=0;i<cols;j++){
//                 if its land 
//           bool check=      check by traversing its neighbours up left right down
//                             SO THAT USS PARTICULAR LAND SE AUR JUDE LAND I MEAN 
//                             CURRENT i,j JO HAI VO KISI ISLAND KA PART HAI 
//                             AB USS PURE BADE ISLAND KO TRAVERSE KARKE AAO JISKA 
//                             CUURENT i,j part hai aur mark them as visted varna matrix
//                             mein wapus kabhi uss island ka part aaya toh count ho jayega 
//             }
//         }
 
//     }
// };