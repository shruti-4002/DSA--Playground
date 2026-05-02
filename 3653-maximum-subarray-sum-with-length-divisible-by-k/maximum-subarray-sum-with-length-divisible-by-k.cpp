class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,long long>mp;
        long long curr=0;
        long long maxsum=LLONG_MIN;
        mp[0]=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            int newindex=i+1;
            int rem=((newindex%k)+k)%k;

            if(mp.find(rem)!=mp.end()){
                maxsum=max(maxsum,curr-mp[rem]);
                mp[rem]=min(curr,mp[rem]);
            }

            if(mp.find(rem)==mp.end()){
                mp[rem]=curr;
            }

        }
        return maxsum;
    }
};