class Solution {
public:

    int wrapper(string lastAction){
        if(lastAction == "buy") return 0;
        if(lastAction == "sell") return 1;
        return -1;
    }

    int helper(int i, string lastAction, vector<int>& prices, vector<vector<int>> &dp){

        if(i == prices.size() - 1){
            if(lastAction == "buy") return prices[i];
            else if(lastAction == "sell") return 0;
        }

        int nowAction = !wrapper(lastAction);
        if(dp[i][nowAction] != -1) return dp[i][!wrapper(lastAction)];

        if(lastAction == "sell"){
        
            int bought = - prices[i] + helper(i + 1 , "buy"  ,  prices , dp);
            int notBought = helper(i + 1 , lastAction ,  prices , dp );
        
            dp[i][nowAction] = max(bought , notBought);
        
        }else if(lastAction == "buy"){
        
            int sold =+ prices[i]  +  helper(i + 1 , "sell" ,  prices , dp );
            int notSold = helper(i + 1 , lastAction   , prices , dp );
        
            dp[i][nowAction] = max(sold , notSold);
        
        }

        return dp[i][nowAction];
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return helper(0 , "sell"  , prices , dp);       
    }

};