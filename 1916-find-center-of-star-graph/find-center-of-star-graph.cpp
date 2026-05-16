class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int nofoedge=edges.size();
        unordered_map<int,int>mp;

        for(auto p : edges){
            int first=p[0];
            int second=p[1];
            mp[first]++;
            mp[second]++;
        }
int k;
        for(auto x :mp){
            if(x.second==nofoedge){
              k =x.first;
               break;
            }
        }

        return k;
    }
};