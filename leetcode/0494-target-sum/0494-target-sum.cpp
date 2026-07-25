class Solution {
public:

int help(int index,int sum,vector<int>&arr,vector<vector<int>>&dp){
      if(index==arr.size()){
           if(sum==0){
          return 1;
      }
          
      }
     
      if(index>=arr.size()){
          return 0;
          
      }
      
      
      
      if(dp[index][sum]!=-1){
          return dp[index][sum];
      }
      int pick=0;
      if(arr[index]<=sum){
          pick=help(index+1,sum-arr[index],arr,dp);
      }
      
      int notpick=help(index+1,sum,arr,dp);
      
      return dp[index][sum]=pick+notpick;
      
      
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;

        for(int x:nums){
            sum+=x;
        }

        if( sum<abs(target)){
            return 0;
        }
        if((sum+target)%2!=0)return 0;

        int tofind=(target+sum)/2;
         vector<vector<int>>dp(nums.size()+1,vector<int>(tofind+1,-1));
        int ans=help(0,tofind,nums,dp);
        return ans;

    }
};