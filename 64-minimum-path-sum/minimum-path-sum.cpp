class Solution {
public:

    void helper(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i==0 && j==0) continue;

                int up = (i>0) ? grid[i][j] + dp[i-1][j] : 1e9;
                int left = (j>0) ? grid[i][j] + dp[i][j-1] : 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        helper(m, n, grid, dp);
        return dp[m-1][n-1];
    }
};