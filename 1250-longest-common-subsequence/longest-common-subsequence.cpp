class Solution {
public:

    int help(int index1,int index2,const string &str1,const string &str2,vector<vector<int>>&dp){
        if(index1<0 || index2<0){
            return 0;
        }

        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }

        if(str1[index1]==str2[index2]){
            return dp[index1][index2]=1+help(index1-1,index2-1,str1,str2,dp);
        }

        return dp[index1][index2]=max(help(index1-1,index2,str1,str2,dp),help(index1,index2-1,str1,str2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return  help(n-1,m-1,text1,text2,dp);
    }
};