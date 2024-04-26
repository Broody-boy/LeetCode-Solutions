class Solution {
public:

    int helper(int r, int prevCol, vector<vector<int>>& grid, vector<vector<int>>& dp){

        if(r == grid.size()) return 0;

        if(dp[r][prevCol] != -1) return dp[r][prevCol];
        int mini = INT_MAX;
        
        for(int c = 0; c < grid[0].size(); c++){
            if(c != prevCol)
                mini = min(mini, grid[r][c] + helper(r+1, c, grid, dp));
        }

        return dp[r][prevCol] = mini;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int mini = INT_MAX;

        //For row 0:
        for(int startCol = 0; startCol < n; startCol++)
            mini = min(mini, grid[0][startCol] + helper(1, startCol, grid, dp));

        return mini;
    }
};