class Solution {
public:
    int arrangeCoins(int n) {
        long long start=1;
        long long end=n;
        
        
        while(start<=end){
            long long mid=(end-start)/2+start;
            long long stm=(mid*(mid+1))/2;

        
            if(stm>n){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return end;
    }
};