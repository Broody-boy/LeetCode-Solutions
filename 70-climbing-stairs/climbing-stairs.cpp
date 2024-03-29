class Solution {
public:

    void helper(int n, vector<int> &dp){
        dp[0] = 1;
        if(n >= 1) dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
    }

    int climbStairs(int n) {

        vector<int> dp(n+1, -1);
        helper(n, dp);
        return dp[n];
    }
};