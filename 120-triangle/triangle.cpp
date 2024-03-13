class Solution {
public:

    void helper(int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        
        for(int col = 0; col < n; col++)
            dp[n-1][col] = triangle[n-1][col];

        for(int row = n-2; row >= 0; row--){
            for(int col = row; col >= 0; col--){
                int d = triangle[row][col] + dp[row+1][col];
                int dr = triangle[row][col] + dp[row+1][col+1];
                dp[row][col] = min(d, dr);
            }
        }
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>>dp (n+1, vector<int>(n+1, 0));
        helper(n, triangle, dp);
        return dp[0][0];
    }
};