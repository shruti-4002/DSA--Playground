// Problem: LeetCode 62 - Unique Paths
// Platform: LeetCode
// Language: C++
// Time Complexity: O(m * n)
// Space Complexity: O(m * n) (DP) + O(m+n) (recursion stack) ≈ O(m * n)

class Solution {
public:

    int path(int m, int n, int i, int j, vector<vector<int>>& dp) {

      
        if(i >= m || j >= n) return 0;               // Out of bounds
        if(i == m-1 && j == n-1) return 1;          // Reached destination
        if(dp[i][j] != -1) return dp[i][j];         // Memoization check

        int right = path(m, n, i, j+1, dp);         // Move right
        int down = path(m, n, i+1, j, dp);          // Move down

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int paths = path(m, n, 0, 0, dp);
        return paths;
    }
};
