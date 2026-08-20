class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int lastday=days[days.size()-1];
        vector<int>dp(lastday+1);
        unordered_set<int>st;

        for(int x: days){
            st.insert(x);
        }

        dp[0]=0;
        for(int i=1;i<=lastday;i++){
            if(st.find(i)==st.end()){
                dp[i]=dp[i-1];
                continue;
            }

            dp[i]=min({cost[0]+dp[i-1],cost[1]+dp[max(i-7,0)],cost[2]+dp[max(i-30,0)]});




        }

        return dp[lastday];
    }
};