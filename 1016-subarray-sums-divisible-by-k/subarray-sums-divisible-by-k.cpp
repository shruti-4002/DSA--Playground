class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        int sum=0;
        int count=0;

        mp[0]=1;
        
        for(int i=0;i<nums.size();i++){
        sum+=nums[i];

        int remcurr=((sum%k)+k)%k;

        if(mp.find(remcurr)!=mp.end()){
            count+=mp[remcurr];

        }

        mp[remcurr]++;

        }

        return count;

    }
};