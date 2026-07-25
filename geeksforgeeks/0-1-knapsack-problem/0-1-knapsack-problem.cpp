                    dp[item][currcap]=max(val[item-1]+dp[item-1][currcap-wt[item-1]],dp[item-1][currcap]);

