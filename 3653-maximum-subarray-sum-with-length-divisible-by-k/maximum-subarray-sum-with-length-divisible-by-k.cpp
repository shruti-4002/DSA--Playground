class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,long long>mp;
        mp[0]=0;

        long long currsumtillnow=0;
        long long ans=LLONG_MIN;
        long long leastprefixsum=0;
        
        for(int i=0;i<nums.size();i++){
            
            currsumtillnow+=nums[i];
            int rem=(i+1)%k;

            if(mp.find(rem)==mp.end()){
                mp[rem]=currsumtillnow;
                continue;
            }
            
           
           long long  sum=currsumtillnow-mp[rem];

            if(sum>ans){
                ans=sum;
            }

            leastprefixsum= min(mp[rem],currsumtillnow);
            mp[rem]=leastprefixsum;

        }

        return ans;

    }
};