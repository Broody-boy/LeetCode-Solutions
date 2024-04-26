class Solution {
public:

    int helper(vector<vector<int>>& grid){
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int col = 0; col < n; col++) dp[n-1][col] = grid[n-1][col];

        for(int row = n-2; row >= 0; row--){
            for(int col = 0; col < n; col++){
                int mini = INT_MAX;
                for(int colOfNextRow = 0; colOfNextRow < n; colOfNextRow++){
                    if(colOfNextRow != col) mini = min(mini, grid[row][col] + dp[row+1][colOfNextRow]);
                }
                dp[row][col] = mini;
            }
        }

        int mini2 = INT_MAX;

        for(int c = 0; c < n; c++){
            mini2 = min(mini2, dp[0][c]);
        }
        return mini2;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        return helper(grid);
    }
};