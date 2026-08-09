class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        for(int i=0;i<arr.size();i++){
            auto &p=ans.back();
            if(arr[i][0]<=p[1]){
                p[1]=max(arr[i][1],p[1]);
            }else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};