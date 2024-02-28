class Solution {
public:

    void helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){

        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0; //No obstacle => 1. obstacle => 0.

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0 && j == 0) continue;

                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }

                int up = (i>0) ? dp[i-1][j] : 0;
                int left = (j>0) ? dp[i][j-1] : 0;

                dp[i][j] = up + left;
            }
        }

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        helper(m, n, obstacleGrid, dp);
        return dp[m-1][n-1];
    }
};