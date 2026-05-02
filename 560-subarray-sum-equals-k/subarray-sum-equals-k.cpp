class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
    unordered_map<int,int>mp;

                int curr=0;
                 mp[0]=1;
                int count=0;
          for(int i=0;i<nums.size();i++){

                curr+=nums[i];
                int prefix=curr-k;

                if(mp.find(prefix) !=mp.end()){
                    count+=mp[prefix];
                }

                mp[curr]++;

          }
          return count;
          }  

    
};