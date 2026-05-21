class Solution {
public:
 int fun(int n,vector<int>&table){
       for(int i=2;i<=n;i++){
        table[i]=table[i-1]+table[i-2];

       }
       return table[n];
    }
   
    int fib(int n) {
       vector<int>table(n+1);
       if(n==0)return 0;
       if(n==1)return 1;
       table[0]=0;
       table[1]=1;
      int k= fun(n,table);
    
    return k;
    }
};