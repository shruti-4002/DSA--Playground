class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int curr=0;
        int count=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            int rematthispoint=((curr%k )+ k)%k;

            if(mp.find(rematthispoint)!=mp.end()){
                count+=mp[rematthispoint];
            }

            mp[rematthispoint]++;
        }

        return count;
    }
};