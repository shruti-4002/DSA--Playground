class Solution {
public:
 int fun(int n,vector<int>&memo){
        if(n==1)return 1;
        if(n==0)return 0;
        if(memo[n]!=-1)return memo[n];
        memo[n]=fun(n-1,memo)+fun(n-2,memo);
       
        return memo[n];
    }
   
    int fib(int n) {
       vector<int>memo(n+1,-1);
      int k= fun(n,memo);
    
    return k;
    }
};