class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,long long> mp;

        mp[0] = 0;

        long long prefix = 0;
        long long ans = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++) {

            prefix += nums[i];

            int rem = (i + 1) % k;

            // only if same remainder existed before
            if(mp.find(rem) != mp.end()) {
                ans = max(ans, prefix - mp[rem]);
            }

            // store minimum prefix
            if(mp.find(rem) == mp.end()) {
                mp[rem] = prefix;
            }
            else {
                mp[rem] = min(mp[rem], prefix);
            }
        }

        return ans;
    }
};