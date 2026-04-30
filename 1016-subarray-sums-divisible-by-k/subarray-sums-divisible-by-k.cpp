class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int count=0;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                int need=(sum%k+k)%k;

                if(mp.find(need)!=mp.end()){
                    count+=mp[need];
                }

                mp[need]++;
                

            
        }

        return count;
    }
};