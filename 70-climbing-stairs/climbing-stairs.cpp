class Solution {
public:

    int helper(int k){

        vector<int> dp(k+1, -1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= k; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[k];
    }

    int climbStairs(int n) {
        return helper(n);
    }
};