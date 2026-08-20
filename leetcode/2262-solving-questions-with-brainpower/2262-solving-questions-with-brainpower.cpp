class Solution {
public:
  
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long>dp(q.size(),-1);
        
        int n=q.size();

        for(int i=n-1;i>=0;i--){
            long long currPoint=q[i][0];
         
         
            long long futureOpen=   q[i][1]+i+1<n? dp[q[i][1]+i+1] :0;
           int nextindex=i+1<n?i+1:0;
            dp[i]=max(dp[nextindex],currPoint+futureOpen);
        }

        return dp[0];
    }
};