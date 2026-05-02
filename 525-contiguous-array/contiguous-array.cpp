class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
            int curr=0;
            mp[0]=-1;
            int len=0;
        for(int i=0;i<nums.size();i++){
            int ele=nums[i]==0?-1:1;

            curr+=ele;

            if(mp.find(curr)!=mp.end()){
                len=max(len,i-mp[curr]);
            }else{
                mp[curr]=i;
            }

        }
        return len;
    }
};