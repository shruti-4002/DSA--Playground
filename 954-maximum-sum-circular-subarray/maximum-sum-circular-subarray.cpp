class Solution {
public:

    int KadaneMax(vector<int>nums){
        int currsum=0;
        int MaxTillNow=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum=max(nums[i],nums[i]+currsum);
            MaxTillNow=max(MaxTillNow,currsum);
        }
        return MaxTillNow;
    }

     int KadaneMin(vector<int>nums){
        int currsum=0;
        int MaxTillNow=INT_MAX;
        for(int i=0;i<nums.size();i++){
            currsum=min(nums[i],nums[i]+currsum);
            MaxTillNow=min(MaxTillNow,currsum);
        }
        return MaxTillNow;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int MAX=KadaneMax(nums);
        int MIN=KadaneMin(nums);

            int TotalSum=0;
        for(int i=0;i<nums.size();i++){
            TotalSum+=nums[i];
        }

        if(MAX<0){
            return MAX;
        }

        return max(MAX,TotalSum-MIN);

    }
};