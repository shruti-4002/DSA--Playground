class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        int curr=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            int odd=nums[i]%2==0?0:1;
            curr+=odd;

            int target=curr-k;

            if(mp.find(target)!=mp.end()){
                count+=mp[target];
            }

            mp[curr]++;


        }

        return count;
    }
};