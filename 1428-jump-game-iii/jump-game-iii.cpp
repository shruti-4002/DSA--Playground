class Solution {
public:

   bool dfs(int index,vector<int>&arr,vector<bool>&v){

        if(index<0 || index>=arr.size())return false;
        if(v[index]==true)return false;

        if(arr[index]==0)return true;
        v[index]=true;

       bool down=false;
       bool up=false;

         if(index+arr[index]<arr.size()){

          down=  dfs(index+arr[index],arr,v);

        }


         if(index-arr[index]>=0){

          up=  dfs(index-arr[index],arr,v);


        }


        if(down || up){
            return true;
        }
        
            return false;
        }

    bool canReach(vector<int>& arr, int start) {
        vector<bool>v(arr.size(),false);
       bool ans= dfs(start,arr,v);
       return ans;
    }
};