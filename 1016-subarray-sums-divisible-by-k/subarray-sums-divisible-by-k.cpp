class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
       int count=0;
        mp[0]=1;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            int rem=((curr%k)+k)%k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }

            mp[rem]++;
        }
        return count;
    }
};