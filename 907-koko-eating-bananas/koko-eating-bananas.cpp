class Solution {
public:

    bool canFinish(int eatOnce,int h,vector<int>&piles){
        long long TimeTaken=0;
        for(int bananas: piles){

            if(bananas%eatOnce!=0){
                TimeTaken+=bananas/eatOnce +1;
            }else{
                TimeTaken+=bananas/eatOnce;
            }
        }

        if(TimeTaken>h){
            return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canFinish(mid,h,piles)){
               ans=mid; 
               right=mid-1;
            }else{
                left=mid+1;
            }
        }

        return ans;
    }
};