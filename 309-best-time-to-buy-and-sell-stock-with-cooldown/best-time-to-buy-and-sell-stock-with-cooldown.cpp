class Solution {
public:

    int helper(int i, int canBuy, vector<int> &prices, vector<vector<int>> &dp){

        if(i >= prices.size()) return 0;

        if(dp[i][canBuy] != -1) return dp[i][canBuy]; 
        
        if(canBuy){
            return dp[i][canBuy] = max(-prices[i] + helper(i + 1, 0, prices, dp) , helper(i + 1, canBuy, prices, dp));
        }else{
            return dp[i][canBuy] = max(prices[i] + helper(i + 2, 1, prices, dp) , helper(i + 1, canBuy, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
    }
};