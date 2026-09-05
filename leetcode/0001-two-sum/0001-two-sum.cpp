class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int>mp;
     for(int x=0;x<nums.size();x++){
        int need=target-nums[x];
        if(mp.find(need)!=mp.end()){
            return {x,mp[need]};
        }
        mp[nums[x]]=x;
     
     }
     return {-1,-1};
    }
};