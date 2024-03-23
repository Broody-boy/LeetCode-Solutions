class Solution {
public:
    int helper(int i, int j, string s, string t, vector <vector <int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j])
            return dp[i][j] = helper(i-1, j-1, s, t, dp) + helper(i-1, j, s, t,dp);
        else
            return dp[i][j] = helper(i-1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        vector <vector <int>> dp(sSize, vector <int>(tSize, -1));
        return helper(sSize-1, tSize-1, s, t, dp);
    }
};