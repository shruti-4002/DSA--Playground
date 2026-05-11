class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int curr=0;
        int count=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            int target=curr-k;
            if(mp.find(target)!=mp.end()){
                count+=mp[target];
            }

            mp[curr]++;
        }

        return count;
    }
};