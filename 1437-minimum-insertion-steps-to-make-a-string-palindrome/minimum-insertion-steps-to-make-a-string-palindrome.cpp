class Solution {
public:

    int helper(int i, int j, string s1, string s2, vector<vector<int>> &dp){

        //In memoisation:
        //i -> size1-1 to -1
        //j -> size2-1 to -1
        //Hence, in tabulation, reverse it

        int size1 = s1.size();
        int size2 = s2.size();

        for(int i = 0; i < size1; i++)
            for(int j = 0; j < size2; j++)
                if(s1[i] == s2[j])
                    dp[i][j] = 1 + ((i-1 < 0 || j-1 < 0) ? 0 : dp[i-1][j-1]);
                else
                    dp[i][j] = 0 + max((j-1 < 0) ? 0 : dp[i][j-1], (i-1 < 0) ? 0 : dp[i-1][j]);

        return dp[size1-1][size2-1];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = s;       //r is reversed
        reverse(r.begin(), r.end());
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return helper(n-1, n-1, s, r, dp);
    }

    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};