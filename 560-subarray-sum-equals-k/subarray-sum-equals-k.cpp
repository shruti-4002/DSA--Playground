class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int currsum=0;
        mp[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            int f=currsum-k;

            if(mp.find(f)!=mp.end()){
                count+=mp[f];
            }

            mp[currsum]++;

        }
        return count;
    }

};