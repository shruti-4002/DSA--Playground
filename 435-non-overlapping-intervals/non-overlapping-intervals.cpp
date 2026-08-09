class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),[](vector<int>a,vector<int>b){
            if(a[1]<b[1]){
                return true;
            }
            return false;    
                });

        int k=arr[0][1];
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]>=k){
                k=arr[i][1];
            }else{
                ans++;
            }
        }
        return ans;
    }
};