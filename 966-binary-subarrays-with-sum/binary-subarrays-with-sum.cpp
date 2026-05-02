class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int>mp;
        int curr=0;
        int count=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            int target=curr-goal;
            if(mp.find(target)!=mp.end()){
                count+=mp[target];
            }

            mp[curr]++;
        }

        return count;

    }
};