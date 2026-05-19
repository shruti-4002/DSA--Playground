class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

       
        for(int x=0;x<nums.size();x++){
            int ans=target-nums[x];
            
            if(mp.find(ans)!=mp.end()){
                return {x,mp[ans]};
            }

            mp[nums[x]]=x;

        }
        return {};
    }
};