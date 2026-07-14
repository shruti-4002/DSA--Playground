class Solution {
public:
    int fun(vector<int>nums){
            vector<int>dp(nums.size());
     dp[0]=nums[0];
     
     dp[1]=max(nums[0],nums[1]);
    

    for(int i=2;i<nums.size();i++){
        dp[i]=max(dp[i-1],nums[i]+dp[i-2]);

    }

     return dp[nums.size()-1];
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1){
        return nums[0];
     }
      if(nums.size()==2){
        return max(nums[0],nums[1]);
     }
     vector<int>part1;
     vector<int>part2;
     for(int i=0;i<nums.size();i++){
        if(i!=0){
            part1.push_back(nums[i]);//disinclude 1 st element
        }
        if(i!=nums.size()-1){
            part2.push_back(nums[i]);
        }
     }
        int way1=fun(part1);
        int way2=fun(part2);

        return max(way1,way2);

    }
};