class Solution {
public:
    long long calPoints(vector<vector<int>>&arr,int index,vector<long long>&dp){
        if(index>=arr.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        long long take=arr[index][0]+calPoints(arr,index+arr[index][1]+1,dp);
        long long notTake=calPoints(arr,index+1,dp);

        return dp[index]= max(take,notTake);

    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size(),-1);
        return calPoints(questions,0,dp);
    }
};