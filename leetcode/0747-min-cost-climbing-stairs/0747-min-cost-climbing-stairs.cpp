class Solution {
public:




    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+2);
        dp[cost.size()]=0;
         dp[cost.size()+1]=0;
         int mincost=1000;
        for(int i=cost.size()-1;i>=0;i--){
            dp[i]=min(dp[i+1],dp[i+2])+cost[i];
           
        }
        return min(dp[0],dp[1]);

    }

};