class Solution {
public:
    int calCost(int index,vector<int>&days,vector<int>&cost,vector<int>&dp){
        if(index>=days.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int day1Pass=cost[0]+calCost(index+1,days,cost,dp);

        //7 Day Pass
        int Valid=days[index]+7;
        int ValidIndex=index;
        while(ValidIndex<days.size() && days[ValidIndex]<Valid){
            ValidIndex++;
        }

        int day2Pass=cost[1]+calCost(ValidIndex,days,cost,dp);

         //8 Day Pass
        int Valid2=days[index]+30;
        int ValidIndex2=index;
        while(ValidIndex2<days.size() && days[ValidIndex2]<Valid2){
            ValidIndex2++;
        }

        int day3Pass=cost[2]+calCost(ValidIndex2,days,cost,dp);



        return dp[index]= min({day1Pass,day2Pass,day3Pass});






    }




    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        int minCost=calCost(0,days,costs,dp);
        
        return minCost;
    }
};