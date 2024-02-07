class Solution {
public:

    int helper(int k, vector<int> &dp){
        if(k <= 1) return 1;

        if(dp[k] != -1) return dp[k];

        return dp[k] = helper(k-1, dp) + helper(k-2, dp);
    }

    int climbStairs(int n) {

        vector<int> v(n+1, -1);
        return helper(n, v);
    }
};