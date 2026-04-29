class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        vector<long long> mp(k, LLONG_MAX);
        mp[0] = 0;

        long long prefix = 0;
        long long ans = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {

            prefix += nums[i];

            int rem = (i + 1) % k;

            if(mp[rem] != LLONG_MAX) {
                ans = max(ans, prefix - mp[rem]);
            }

            mp[rem] = min(mp[rem], prefix);
        }

        return ans;
    }
};