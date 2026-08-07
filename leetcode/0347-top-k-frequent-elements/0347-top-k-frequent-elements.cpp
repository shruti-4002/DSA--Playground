class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;

        for(int x:nums){
            mp[x]++;
        }

        for(auto k :mp){
            pq.push({k.second,k.first});
        }

        vector<int>ans;

        while(k--){
           auto k=pq.top();
           ans.push_back(k.second);
           pq.pop();
        }

        return ans;


    }
};