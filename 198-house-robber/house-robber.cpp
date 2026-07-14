class Solution {
public:

    int fun(int n,vector<int>nums,vector<int>&memo){
        if(n>=nums.size()){
            return 0;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        int take=fun(n+2,nums,memo);
        int nottake=fun(n+1,nums,memo);
        memo[n]=max((take+nums[n]),nottake);
        return memo[n];
    }
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
       int ans=fun(0,nums,memo); 
       return ans;
    }
};