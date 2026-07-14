class Solution {
public:

    int fun(int n,vector<int>arr,vector<int>&memo){
        if(n>=arr.size()){
            return 0;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        int onestep=fun(n+1,arr,memo);
        int twostep=fun(n+2,arr,memo);

        memo[n]=min(onestep,twostep)+arr[n];
        return memo[n];
    }



    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>memo(cost.size(),-1);
        int onestep=fun(0,cost,memo);
       int twostep= fun(1,cost,memo);
       return min(onestep,twostep);
    }

};