class Solution {
public:

    int helper(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row == n-1) return dp[row][col] = triangle[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = min(triangle[row][col] + helper(row+1, col, n, triangle, dp), triangle[row][col] + helper(row+1, col+1, n, triangle, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>>dp (n+1, vector<int>(n+1,-1));
        return helper(0, 0, n, triangle, dp);
    }
};