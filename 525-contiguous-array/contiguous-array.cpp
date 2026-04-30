class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int curr=0;
        int maxleng=0;
         
        unordered_map<int,int>mp;

        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i]==1?1:-1;
            if(mp.find(curr)!=mp.end()){
                maxleng=max(maxleng,i-mp[curr]);
            }else{
                   mp[curr]=i;
            }

         

        }
        return maxleng;
    }

};