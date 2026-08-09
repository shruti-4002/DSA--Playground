class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>a,vector<int>b){
            if(a[1]<b[1]){
                return true;
            }

            return false;
        });
        int end=points[0][1];
        int arrow=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                arrow++;
                end=points[i][1];
            }
        }
        return arrow;
    }
};