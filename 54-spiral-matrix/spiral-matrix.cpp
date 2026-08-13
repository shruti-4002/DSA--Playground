class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int>ans;
        int startrow=0;
        int startcol=0;
        int endrow=arr.size()-1;
        int endcol=arr[0].size()-1;
        while(startrow<=endrow && startcol<=endcol){
        //left-right

        for(int j=startcol;j<=endcol;j++){
            ans.push_back(arr[startrow][j]);
        }
         startrow+=1;

         
        if(startrow<=endrow){
            //top-bottom
        for(int i=startrow;i<=endrow;i++){
            ans.push_back(arr[i][endcol]);
        }

        }
      
          endcol=endcol-1;

        if(startrow <= endrow){

        
        //right-left
    
        for(int j=endcol;j>=startcol;j--){
            ans.push_back(arr[endrow][j]);
        }
            
        }
        
        endrow-=1;
        if(startcol <= endcol){
             //bottom-top
        for(int i=endrow;i>=startrow;i--){
            ans.push_back(arr[i][startcol]);
        }
        }
       
       startcol++;



        }

        return ans;
    }
};