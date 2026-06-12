class Solution {
public:

   int  fun(int i,vector<int>&cost,vector<int>&v){
        if(i>=cost.size())return 0;
        if(v[i]!=-1){

            return v[i];
        }
        int one=fun(i+1,cost,v);
        int two=fun(i+2,cost,v);
    
    v[i] =min(one,two)+cost[i];
    return v[i];
   }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>v(cost.size(),-1);
       int startfromzero= fun(0,cost,v);
       int startfromone=fun(1,cost,v);
       return min(startfromzero,startfromone);
    }
};