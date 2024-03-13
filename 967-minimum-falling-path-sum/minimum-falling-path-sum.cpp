class Solution {
public:

    void helper(int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        for(int j = 0; j < n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int ld = (j > 0) ? matrix[i][j] + dp[i+1][j-1] : 1e9;
                int d = matrix[i][j] + dp[i+1][j];
                int rd = (j < n-1) ? matrix[i][j] + dp[i+1][j+1] : 1e9;

                dp[i][j] = min(ld,min(d, rd));
            }
        }

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();

        vector<vector<int>>dp(n, vector<int>(n, 0));
        helper(n, matrix, dp);

        for(int i = 0; i < n; i++){
            int curr = dp[0][i];
            ans = min(ans, curr);
        }
        return ans;
    }
};