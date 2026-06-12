class Solution {
public:

    int fun(vector<int>&step,int n){

        if(n==0)return 1;
        if(n<0)return 0;
        if(step[n]!=-1){
            return step[n];
        }
         
        int one=fun(step,n-1);
        int two=fun(step,n-2);
        step[n]= one+two;
        return step[n];

    }

    int climbStairs(int n) {
        vector<int>step(n+1,-1);
      int ans=  fun(step,n);
      return ans;
       
    }
};