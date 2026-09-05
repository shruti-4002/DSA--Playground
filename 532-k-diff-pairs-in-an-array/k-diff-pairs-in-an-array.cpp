class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int x:nums){
        mp[x]++;
        }

    for(auto x:mp){
        if(k==0){
            if(x.second>=2){
                ans++;
            }
        }else{
            
            int need=x.first-k;
            if(mp.find(need)!=mp.end()){
                ans++;
            }




        }
    }
        return ans;
    }
};