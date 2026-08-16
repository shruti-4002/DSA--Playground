class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxmoney=0;
        for(auto acc : accounts){
            int sum=0;
            for(int j : acc){
                sum+=j;

            } maxmoney=max(sum,maxmoney);
        }

        return maxmoney;
    }
};