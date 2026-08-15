class Solution {
public:
    int arrangeCoins(int n) {
        int moneyleft=n;
        int count=0;
        for(int i=1;i<=n;i++){
             moneyleft=moneyleft-i;
             if(moneyleft>=0){
                count++;
             }else{
                break;
             }
        }
        return count;
    }
};