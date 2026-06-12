class Solution {
public:

    int climbStairs(int n) {
        vector<int>step(n+2);
        step[0]=0;
        step[1]=1;
        if(n==1)return 1;
        for(int i=2;i<=n+1;i++){
            step[i]=step[i-1]+step[i-2];
        }
      return step[n+1];
       
    }
};